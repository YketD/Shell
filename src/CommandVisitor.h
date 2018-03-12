#ifndef SHELL_COMMANDVISITOR_H
#define SHELL_COMMANDVISITOR_H

#include "../gen/ShellGrammarBaseVisitor.h"

/**
 * Visitor class that walks through the whole parse tree and creates objects
 * for the parsed command.
 * Visiting a parse tree will yield a Sequence-pointer that contains all
 * pipelines, which in turn will contain the simple commands.
 */
class CommandVisitor : public ShellGrammarBaseVisitor {
	public:
		antlrcpp::Any visitSequence(ShellGrammarParser::SequenceContext *ctx) override;
		antlrcpp::Any visitPipeline(ShellGrammarParser::PipelineContext *ctx) override;
		antlrcpp::Any visitSimpleCommand(ShellGrammarParser::SimpleCommandContext *ctx) override;
		antlrcpp::Any visitString(ShellGrammarParser::StringContext *ctx) override;
};


#endif //SHELL_COMMANDVISITOR_H
