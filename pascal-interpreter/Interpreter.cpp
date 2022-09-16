#include "Interpreter.h"
#include <iostream>

Interpreter::Interpreter() {
	tokenizer = Tokenizer();
}

Interpreter::Interpreter(Tokenizer _tokenizer) {
	tokenizer = Tokenizer(_tokenizer);
}

void Interpreter::eat(tkType _tokenType) {
	// Compare current and passed token type
	if (currentToken.getType() == _tokenType) {
		tokens.push(currentToken);
		currentToken = tokenizer.getNextToken();
	}
	else {
		throw std::invalid_argument("There was an error parsing the input");
	}
}

int Interpreter::performExpr() {
	// Set current token to first token
	currentToken = tokenizer.getNextToken();

	// Get all elements of the expression
	while (currentToken.getType() != tkType::END) {
		eat(currentToken.getType());
	}

	int answer = 0;
	tkType op = tkType::PLUS;
	// Iterate through tokens vector, performing all arithmetic calculations
	while (!tokens.empty()) {
		Token tmpToken = tokens.front();
		if (tmpToken.getType() == tkType::INTEGER) {
			switch (op) {
			case tkType::PLUS:
				answer += tmpToken.getValue();
				break;
			case tkType::SUBTRACT:
				answer -= tmpToken.getValue();
				break;
			case tkType::MULTIPLY:
				answer *= tmpToken.getValue();
				break;
			case tkType::DIVIDE:
				answer /= tmpToken.getValue();
				break;
			default:
				break;
			}
		} else { // We can assume that it's an operator
			op = tmpToken.getType();
		}
		tokens.pop();
	}
	return answer;
}

void Interpreter::factor() {
	Interpreter::eat(tkType::INTEGER);
}