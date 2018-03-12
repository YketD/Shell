#include "CommandVisitor.h"
#include "Sequence.h"
#include "Pipeline.h"
#include "SimpleCommand.h"

#define PRINT_DEBUG_INFO 1   // Set to 1 to print debug lines when visiting command parts
#if PRINT_DEBUG_INFO
	#define LOG(...) do { printf(__VA_ARGS__); } while(false)
#else
	#define LOG(...) do { } while(false)
#endif

antlrcpp::Any CommandVisitor::visitSequence(ShellGrammarParser::SequenceContext *ctx) {
	LOG("Visiting sequence\n");
	Sequence *sequence = new Sequence();

	// Walk through the list of pipelines
	size_t numberOfPipelines = ctx->pipeline().size();
	LOG("  Visiting %zu pipelines\n", numberOfPipelines);
	for( size_t i = 0; i < numberOfPipelines; i++ ) {
		Pipeline *pipeline = visit(ctx->pipeline(i));

		// Check if pipeline must be executed asynchronously
		if( ctx->seqDelim(i) ) {
			// There is another pipeline to the right from us.
			// Could be delimited using ';' or '&'
			if( ctx->seqDelim(i)->AMPERSAND() )
				pipeline->setAsync(true);
		} else if( ctx->lastAmpersand != nullptr ) {
			// If this is the last pipeline, check if user appended a '&'
			pipeline->setAsync(true);
		}

		LOG("    Pipeline %zu -> %s\n", i, pipeline->isAsync() ? "async" : "wait");
		sequence->addPipeline(pipeline);
	}

	LOG("Done\n");
	return sequence;
}

antlrcpp::Any CommandVisitor::visitPipeline(ShellGrammarParser::PipelineContext *ctx) {
	LOG("     Visiting pipeline\n");
	Pipeline *pipeline = new Pipeline();

	size_t n = ctx->simpleCommand().size();
	LOG( "     Pipeline has %zu commands\n", n );
	for( size_t i = 0; i < n; i++ ) {
		SimpleCommand *cmd = visit(ctx->simpleCommand(i));
		pipeline->addCommand(cmd);
	}

	return pipeline;
}

antlrcpp::Any CommandVisitor::visitSimpleCommand(ShellGrammarParser::SimpleCommandContext *ctx) {
	std::string program = visit(ctx->string(0));
	SimpleCommand *cmd = new SimpleCommand(program);
	LOG( "       Program: %s\n", program.c_str() );

	// Gather arguments
	size_t n = ctx->string().size();
	for( size_t i = 1; i < n; i++ ) {
		std::string arg = visit(ctx->string(i));
		LOG( "         Arg %zu: %s\n", i, arg.c_str() );
		cmd->addArgument(arg);
	}

	// Add IO redirection
	n = ctx->ioRedirect().size();
	for( size_t i = 0; i < n; i++ ) {
		ShellGrammarParser::IoRedirectContext *ioRedir = ctx->ioRedirect(i);

		// Find out the type
		std::string redir = ioRedir->REDIRECT() ? ioRedir->REDIRECT()->getText() : ioRedir->REDIRECTFD()->getText();
		size_t redirChar = std::isdigit(redir[0]) ? 1 : 0;   // is there a number before >, >> or < ?
		IORedirect::Type redirType = redir[redirChar] == '<' ? IORedirect::INPUT : IORedirect::OUTPUT;
		if( redir.size() > redirChar+1 ) {
			if( redir[redirChar+1] == '>' )
				redirType = IORedirect::APPEND;
		}

		// Get the source fd
		int fd;
		if( redirChar == 0 ) {
			// Nope. Do the default: 0 for input, 1 for output and append
			fd = (redirType == IORedirect::INPUT ? 0 : 1);
		} else {
			fd = redir[0] - '0';
		}

		// Get the target
		std::string outFile;
		if( ioRedir->REDIRECT() ) {
			std::string s = visit(ioRedir->string());
			outFile = s;
		}
		else {
			std::string r = ioRedir->REDIRECTFD()->getText();
			size_t ampersandChar = r.find('&');
			outFile = r.substr( ampersandChar, r.size()-ampersandChar);
		}

		// Add redirect to command
		cmd->addIORedirect(fd, redirType, outFile);

		// Log
		LOG( "       Redir %d %s %s\n", fd,
			 redirType == IORedirect::INPUT ? "<" : redirType == IORedirect::OUTPUT ? ">" : ">>",
			 outFile.c_str()
		);
	}

	return cmd;
}

antlrcpp::Any CommandVisitor::visitString(ShellGrammarParser::StringContext *ctx) {
	if( ctx->STRING() )
		return ctx->STRING()->getText();

	std::string str = ctx->QUOTEDSTRING()->getText();
	return str.substr(1, str.size()-2);
}
