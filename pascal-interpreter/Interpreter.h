#pragma once
#include "Tokenizer.h"

class Interpreter {
private:
	Tokenizer tokenizer;
	Token currentToken;
	std::queue<Token> tokens;
public:
	Interpreter();
	Interpreter(Tokenizer _tokenizer);
	void eat(tkType _tokenType);
	int performExpr();
	void factor();
};