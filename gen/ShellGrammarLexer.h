
// Generated from D:/Prog/Saxion/2.3-Compilers-Operating-Systems/Practical/Shell/Base\ShellGrammar.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"




class  ShellGrammarLexer : public antlr4::Lexer {
public:
  enum {
    SEMICOLON = 1, AMPERSAND = 2, PIPE = 3, REDIRECTFD = 4, REDIRECT = 5, 
    QUOTEDSTRING = 6, STRING = 7, WS = 8
  };

  ShellGrammarLexer(antlr4::CharStream *input);
  ~ShellGrammarLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

