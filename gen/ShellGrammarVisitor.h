
// Generated from D:/Prog/Saxion/2.3-Compilers-Operating-Systems/Practical/Shell/Base\ShellGrammar.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "ShellGrammarParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ShellGrammarParser.
 */
class  ShellGrammarVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ShellGrammarParser.
   */
    virtual antlrcpp::Any visitSequence(ShellGrammarParser::SequenceContext *context) = 0;

    virtual antlrcpp::Any visitSeqDelim(ShellGrammarParser::SeqDelimContext *context) = 0;

    virtual antlrcpp::Any visitPipeline(ShellGrammarParser::PipelineContext *context) = 0;

    virtual antlrcpp::Any visitSimpleCommand(ShellGrammarParser::SimpleCommandContext *context) = 0;

    virtual antlrcpp::Any visitIoRedirect(ShellGrammarParser::IoRedirectContext *context) = 0;

    virtual antlrcpp::Any visitString(ShellGrammarParser::StringContext *context) = 0;


};

