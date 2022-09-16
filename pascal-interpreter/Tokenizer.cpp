#include "Tokenizer.h"

Tokenizer::Tokenizer() {
	inputTxt = "";
	position = 0;
}

Tokenizer::Tokenizer(std::string _inputTxt) {
	inputTxt = _inputTxt;
	position = 0;
}

Token Tokenizer::getNextToken() {
	// Lexer Nodes
	if (position > inputTxt.length() - 1) {
		return Token(tkType::END, 1);
	}

	char curr = inputTxt[position];

	// If int, get ALL digits
	int num = 0;
	bool isNum = false;
	while (isdigit(curr)) {
		isNum = true;
		num = num * 10 + (curr - 48);
		position += 1;
		curr = inputTxt[position];
	}

	// Check to see if int
	if (isNum) {
		return Token(tkType::INTEGER, num);
	}
	// Not an int, check to see if operant
	switch (curr) {
	case '+':
		position += 1;
		return Token(tkType::PLUS, 1);
	case '-':
		position += 1;
		return Token(tkType::SUBTRACT, 1);
	case '*':
		position += 1;
		return Token(tkType::MULTIPLY, 1);
	case '/':
		position += 1;
		return Token(tkType::DIVIDE, 1);
	default:
		// Something went wrong, throw error
		throw std::invalid_argument("There was an error parsing the input");
	}

	return Token(tkType::END, 1);
}