
// Generated from D:/Prog/Saxion/2.3-Compilers-Operating-Systems/Practical/Shell/Base\ShellGrammar.g4 by ANTLR 4.7


#include "ShellGrammarVisitor.h"

#include "ShellGrammarParser.h"


using namespace antlrcpp;
using namespace antlr4;

ShellGrammarParser::ShellGrammarParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ShellGrammarParser::~ShellGrammarParser() {
  delete _interpreter;
}

std::string ShellGrammarParser::getGrammarFileName() const {
  return "ShellGrammar.g4";
}

const std::vector<std::string>& ShellGrammarParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& ShellGrammarParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- SequenceContext ------------------------------------------------------------------

ShellGrammarParser::SequenceContext::SequenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ShellGrammarParser::PipelineContext *> ShellGrammarParser::SequenceContext::pipeline() {
  return getRuleContexts<ShellGrammarParser::PipelineContext>();
}

ShellGrammarParser::PipelineContext* ShellGrammarParser::SequenceContext::pipeline(size_t i) {
  return getRuleContext<ShellGrammarParser::PipelineContext>(i);
}

tree::TerminalNode* ShellGrammarParser::SequenceContext::EOF() {
  return getToken(ShellGrammarParser::EOF, 0);
}

std::vector<ShellGrammarParser::SeqDelimContext *> ShellGrammarParser::SequenceContext::seqDelim() {
  return getRuleContexts<ShellGrammarParser::SeqDelimContext>();
}

ShellGrammarParser::SeqDelimContext* ShellGrammarParser::SequenceContext::seqDelim(size_t i) {
  return getRuleContext<ShellGrammarParser::SeqDelimContext>(i);
}

tree::TerminalNode* ShellGrammarParser::SequenceContext::AMPERSAND() {
  return getToken(ShellGrammarParser::AMPERSAND, 0);
}


size_t ShellGrammarParser::SequenceContext::getRuleIndex() const {
  return ShellGrammarParser::RuleSequence;
}

antlrcpp::Any ShellGrammarParser::SequenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShellGrammarVisitor*>(visitor))
    return parserVisitor->visitSequence(this);
  else
    return visitor->visitChildren(this);
}

ShellGrammarParser::SequenceContext* ShellGrammarParser::sequence() {
  SequenceContext *_localctx = _tracker.createInstance<SequenceContext>(_ctx, getState());
  enterRule(_localctx, 0, ShellGrammarParser::RuleSequence);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(12);
    pipeline();
    setState(18);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(13);
        seqDelim();
        setState(14);
        pipeline(); 
      }
      setState(20);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
    setState(22);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ShellGrammarParser::AMPERSAND) {
      setState(21);
      dynamic_cast<SequenceContext *>(_localctx)->lastAmpersand = match(ShellGrammarParser::AMPERSAND);
    }
    setState(24);
    match(ShellGrammarParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SeqDelimContext ------------------------------------------------------------------

ShellGrammarParser::SeqDelimContext::SeqDelimContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ShellGrammarParser::SeqDelimContext::SEMICOLON() {
  return getToken(ShellGrammarParser::SEMICOLON, 0);
}

tree::TerminalNode* ShellGrammarParser::SeqDelimContext::AMPERSAND() {
  return getToken(ShellGrammarParser::AMPERSAND, 0);
}


size_t ShellGrammarParser::SeqDelimContext::getRuleIndex() const {
  return ShellGrammarParser::RuleSeqDelim;
}

antlrcpp::Any ShellGrammarParser::SeqDelimContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShellGrammarVisitor*>(visitor))
    return parserVisitor->visitSeqDelim(this);
  else
    return visitor->visitChildren(this);
}

ShellGrammarParser::SeqDelimContext* ShellGrammarParser::seqDelim() {
  SeqDelimContext *_localctx = _tracker.createInstance<SeqDelimContext>(_ctx, getState());
  enterRule(_localctx, 2, ShellGrammarParser::RuleSeqDelim);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(26);
    _la = _input->LA(1);
    if (!(_la == ShellGrammarParser::SEMICOLON

    || _la == ShellGrammarParser::AMPERSAND)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PipelineContext ------------------------------------------------------------------

ShellGrammarParser::PipelineContext::PipelineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ShellGrammarParser::SimpleCommandContext *> ShellGrammarParser::PipelineContext::simpleCommand() {
  return getRuleContexts<ShellGrammarParser::SimpleCommandContext>();
}

ShellGrammarParser::SimpleCommandContext* ShellGrammarParser::PipelineContext::simpleCommand(size_t i) {
  return getRuleContext<ShellGrammarParser::SimpleCommandContext>(i);
}

std::vector<tree::TerminalNode *> ShellGrammarParser::PipelineContext::PIPE() {
  return getTokens(ShellGrammarParser::PIPE);
}

tree::TerminalNode* ShellGrammarParser::PipelineContext::PIPE(size_t i) {
  return getToken(ShellGrammarParser::PIPE, i);
}


size_t ShellGrammarParser::PipelineContext::getRuleIndex() const {
  return ShellGrammarParser::RulePipeline;
}

antlrcpp::Any ShellGrammarParser::PipelineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShellGrammarVisitor*>(visitor))
    return parserVisitor->visitPipeline(this);
  else
    return visitor->visitChildren(this);
}

ShellGrammarParser::PipelineContext* ShellGrammarParser::pipeline() {
  PipelineContext *_localctx = _tracker.createInstance<PipelineContext>(_ctx, getState());
  enterRule(_localctx, 4, ShellGrammarParser::RulePipeline);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(28);
    simpleCommand();
    setState(33);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ShellGrammarParser::PIPE) {
      setState(29);
      match(ShellGrammarParser::PIPE);
      setState(30);
      simpleCommand();
      setState(35);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimpleCommandContext ------------------------------------------------------------------

ShellGrammarParser::SimpleCommandContext::SimpleCommandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ShellGrammarParser::StringContext *> ShellGrammarParser::SimpleCommandContext::string() {
  return getRuleContexts<ShellGrammarParser::StringContext>();
}

ShellGrammarParser::StringContext* ShellGrammarParser::SimpleCommandContext::string(size_t i) {
  return getRuleContext<ShellGrammarParser::StringContext>(i);
}

std::vector<ShellGrammarParser::IoRedirectContext *> ShellGrammarParser::SimpleCommandContext::ioRedirect() {
  return getRuleContexts<ShellGrammarParser::IoRedirectContext>();
}

ShellGrammarParser::IoRedirectContext* ShellGrammarParser::SimpleCommandContext::ioRedirect(size_t i) {
  return getRuleContext<ShellGrammarParser::IoRedirectContext>(i);
}


size_t ShellGrammarParser::SimpleCommandContext::getRuleIndex() const {
  return ShellGrammarParser::RuleSimpleCommand;
}

antlrcpp::Any ShellGrammarParser::SimpleCommandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShellGrammarVisitor*>(visitor))
    return parserVisitor->visitSimpleCommand(this);
  else
    return visitor->visitChildren(this);
}

ShellGrammarParser::SimpleCommandContext* ShellGrammarParser::simpleCommand() {
  SimpleCommandContext *_localctx = _tracker.createInstance<SimpleCommandContext>(_ctx, getState());
  enterRule(_localctx, 6, ShellGrammarParser::RuleSimpleCommand);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(37); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(36);
      string();
      setState(39); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == ShellGrammarParser::QUOTEDSTRING

    || _la == ShellGrammarParser::STRING);
    setState(44);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ShellGrammarParser::REDIRECTFD

    || _la == ShellGrammarParser::REDIRECT) {
      setState(41);
      ioRedirect();
      setState(46);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IoRedirectContext ------------------------------------------------------------------

ShellGrammarParser::IoRedirectContext::IoRedirectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ShellGrammarParser::IoRedirectContext::REDIRECT() {
  return getToken(ShellGrammarParser::REDIRECT, 0);
}

ShellGrammarParser::StringContext* ShellGrammarParser::IoRedirectContext::string() {
  return getRuleContext<ShellGrammarParser::StringContext>(0);
}

tree::TerminalNode* ShellGrammarParser::IoRedirectContext::REDIRECTFD() {
  return getToken(ShellGrammarParser::REDIRECTFD, 0);
}


size_t ShellGrammarParser::IoRedirectContext::getRuleIndex() const {
  return ShellGrammarParser::RuleIoRedirect;
}

antlrcpp::Any ShellGrammarParser::IoRedirectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShellGrammarVisitor*>(visitor))
    return parserVisitor->visitIoRedirect(this);
  else
    return visitor->visitChildren(this);
}

ShellGrammarParser::IoRedirectContext* ShellGrammarParser::ioRedirect() {
  IoRedirectContext *_localctx = _tracker.createInstance<IoRedirectContext>(_ctx, getState());
  enterRule(_localctx, 8, ShellGrammarParser::RuleIoRedirect);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(50);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ShellGrammarParser::REDIRECT: {
        enterOuterAlt(_localctx, 1);
        setState(47);
        match(ShellGrammarParser::REDIRECT);
        setState(48);
        string();
        break;
      }

      case ShellGrammarParser::REDIRECTFD: {
        enterOuterAlt(_localctx, 2);
        setState(49);
        match(ShellGrammarParser::REDIRECTFD);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringContext ------------------------------------------------------------------

ShellGrammarParser::StringContext::StringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ShellGrammarParser::StringContext::QUOTEDSTRING() {
  return getToken(ShellGrammarParser::QUOTEDSTRING, 0);
}

tree::TerminalNode* ShellGrammarParser::StringContext::STRING() {
  return getToken(ShellGrammarParser::STRING, 0);
}


size_t ShellGrammarParser::StringContext::getRuleIndex() const {
  return ShellGrammarParser::RuleString;
}

antlrcpp::Any ShellGrammarParser::StringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShellGrammarVisitor*>(visitor))
    return parserVisitor->visitString(this);
  else
    return visitor->visitChildren(this);
}

ShellGrammarParser::StringContext* ShellGrammarParser::string() {
  StringContext *_localctx = _tracker.createInstance<StringContext>(_ctx, getState());
  enterRule(_localctx, 10, ShellGrammarParser::RuleString);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(52);
    _la = _input->LA(1);
    if (!(_la == ShellGrammarParser::QUOTEDSTRING

    || _la == ShellGrammarParser::STRING)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> ShellGrammarParser::_decisionToDFA;
atn::PredictionContextCache ShellGrammarParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ShellGrammarParser::_atn;
std::vector<uint16_t> ShellGrammarParser::_serializedATN;

std::vector<std::string> ShellGrammarParser::_ruleNames = {
  "sequence", "seqDelim", "pipeline", "simpleCommand", "ioRedirect", "string"
};

std::vector<std::string> ShellGrammarParser::_literalNames = {
  "", "';'", "'&'", "'|'"
};

std::vector<std::string> ShellGrammarParser::_symbolicNames = {
  "", "SEMICOLON", "AMPERSAND", "PIPE", "REDIRECTFD", "REDIRECT", "QUOTEDSTRING", 
  "STRING", "WS"
};

dfa::Vocabulary ShellGrammarParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ShellGrammarParser::_tokenNames;

ShellGrammarParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0xa, 0x39, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x13, 0xa, 0x2, 0xc, 0x2, 
    0xe, 0x2, 0x16, 0xb, 0x2, 0x3, 0x2, 0x5, 0x2, 0x19, 0xa, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 
    0x22, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x25, 0xb, 0x4, 0x3, 0x5, 0x6, 0x5, 
    0x28, 0xa, 0x5, 0xd, 0x5, 0xe, 0x5, 0x29, 0x3, 0x5, 0x7, 0x5, 0x2d, 
    0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x30, 0xb, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x5, 0x6, 0x35, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x2, 0x2, 
    0x8, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0x2, 0x4, 0x3, 0x2, 0x3, 0x4, 0x3, 
    0x2, 0x8, 0x9, 0x2, 0x38, 0x2, 0xe, 0x3, 0x2, 0x2, 0x2, 0x4, 0x1c, 0x3, 
    0x2, 0x2, 0x2, 0x6, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x8, 0x27, 0x3, 0x2, 0x2, 
    0x2, 0xa, 0x34, 0x3, 0x2, 0x2, 0x2, 0xc, 0x36, 0x3, 0x2, 0x2, 0x2, 0xe, 
    0x14, 0x5, 0x6, 0x4, 0x2, 0xf, 0x10, 0x5, 0x4, 0x3, 0x2, 0x10, 0x11, 
    0x5, 0x6, 0x4, 0x2, 0x11, 0x13, 0x3, 0x2, 0x2, 0x2, 0x12, 0xf, 0x3, 
    0x2, 0x2, 0x2, 0x13, 0x16, 0x3, 0x2, 0x2, 0x2, 0x14, 0x12, 0x3, 0x2, 
    0x2, 0x2, 0x14, 0x15, 0x3, 0x2, 0x2, 0x2, 0x15, 0x18, 0x3, 0x2, 0x2, 
    0x2, 0x16, 0x14, 0x3, 0x2, 0x2, 0x2, 0x17, 0x19, 0x7, 0x4, 0x2, 0x2, 
    0x18, 0x17, 0x3, 0x2, 0x2, 0x2, 0x18, 0x19, 0x3, 0x2, 0x2, 0x2, 0x19, 
    0x1a, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x1b, 0x7, 0x2, 0x2, 0x3, 0x1b, 0x3, 
    0x3, 0x2, 0x2, 0x2, 0x1c, 0x1d, 0x9, 0x2, 0x2, 0x2, 0x1d, 0x5, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0x23, 0x5, 0x8, 0x5, 0x2, 0x1f, 0x20, 0x7, 0x5, 
    0x2, 0x2, 0x20, 0x22, 0x5, 0x8, 0x5, 0x2, 0x21, 0x1f, 0x3, 0x2, 0x2, 
    0x2, 0x22, 0x25, 0x3, 0x2, 0x2, 0x2, 0x23, 0x21, 0x3, 0x2, 0x2, 0x2, 
    0x23, 0x24, 0x3, 0x2, 0x2, 0x2, 0x24, 0x7, 0x3, 0x2, 0x2, 0x2, 0x25, 
    0x23, 0x3, 0x2, 0x2, 0x2, 0x26, 0x28, 0x5, 0xc, 0x7, 0x2, 0x27, 0x26, 
    0x3, 0x2, 0x2, 0x2, 0x28, 0x29, 0x3, 0x2, 0x2, 0x2, 0x29, 0x27, 0x3, 
    0x2, 0x2, 0x2, 0x29, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2e, 0x3, 0x2, 
    0x2, 0x2, 0x2b, 0x2d, 0x5, 0xa, 0x6, 0x2, 0x2c, 0x2b, 0x3, 0x2, 0x2, 
    0x2, 0x2d, 0x30, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2c, 0x3, 0x2, 0x2, 0x2, 
    0x2e, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x9, 0x3, 0x2, 0x2, 0x2, 0x30, 
    0x2e, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x7, 0x7, 0x2, 0x2, 0x32, 0x35, 
    0x5, 0xc, 0x7, 0x2, 0x33, 0x35, 0x7, 0x6, 0x2, 0x2, 0x34, 0x31, 0x3, 
    0x2, 0x2, 0x2, 0x34, 0x33, 0x3, 0x2, 0x2, 0x2, 0x35, 0xb, 0x3, 0x2, 
    0x2, 0x2, 0x36, 0x37, 0x9, 0x3, 0x2, 0x2, 0x37, 0xd, 0x3, 0x2, 0x2, 
    0x2, 0x8, 0x14, 0x18, 0x23, 0x29, 0x2e, 0x34, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ShellGrammarParser::Initializer ShellGrammarParser::_init;
