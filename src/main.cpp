#include <iostream>
#include <ANTLRInputStream.h>
#include <CommonTokenStream.h>
#include <tree/ParseTree.h>
#include "../gen/ShellGrammarLexer.h"
#include "../gen/ShellGrammarParser.h"
#include "CommandVisitor.h"
#include "Sequence.h"

class ErrorListener : public antlr4::BaseErrorListener {
	bool seenError;

public:
	ErrorListener()
		: antlr4::BaseErrorListener()
		, seenError(false)
	{}

	bool hasSeenError() const { return seenError; }
	void reset()              { seenError = false; }

	void syntaxError( antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol,
					  size_t line, size_t charPositionInLine, const std::string &msg, std::exception_ptr e ) override {
		std::cerr << "ERROR in input - line " << line << ":" << charPositionInLine << " " << msg << std::endl;
		seenError = true;
	}
};

int main() {
	static const char *PROMPT = "-> ";
	while( true ) {
		// Print a prompt
		std::cout << PROMPT;
		std::flush(std::cout);

		// Read a complete line
		std::string line;
		std::getline(std::cin, line);

		// Check if the user typed 'exit'.
		// Now this is a bit of a hack, since the nice way to do this is actually
		// just check for 'exit' in the SimpleCommand-class.
		// You are encouraged to remove this hack and handle things 'the nice way'.
		if( line == "exit" )
			break;

		// Create an error listener. This will be called when an error occured.
		ErrorListener errorListener;

		// Create parser and lexer for line
		// The lexer combines characters into meaningful tokens
		// The parser then uses these tokens to deduce meaning of the line
		antlr4::ANTLRInputStream inputStream(line);
		ShellGrammarLexer lexer(&inputStream);
		lexer.removeErrorListeners();
		lexer.addErrorListener(&errorListener);
		antlr4::CommonTokenStream tokens(&lexer);
		ShellGrammarParser parser(&tokens);
		parser.removeErrorListeners();
		parser.addErrorListener(&errorListener);

		// Actually parse the line
		antlr4::tree::ParseTree *parseTree = parser.sequence();

		// Did ANTLR report an error?
		if( !errorListener.hasSeenError() ) {
			// Take apart the line entered into sequences, pipelines and commands
			CommandVisitor visitor;
			Sequence *sequence = visitor.visit(parseTree);

			// Execute sequence
			// Now these execute() methods are were you have to add your code...
			sequence->execute();

			// Cleanup
			delete sequence;
		}
	}
	return 0;
}
