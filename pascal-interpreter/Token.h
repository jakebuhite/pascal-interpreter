#pragma once
#include <string>
#include <iostream>

enum class tkType { INTEGER, PLUS, SUBTRACT, MULTIPLY, DIVIDE, END };

class Token {
private:
	int value;
	tkType tokenType;
public:
	Token();
	Token(tkType _tokenType, int _value);
	std::string ToString();
	tkType getType();
	int getValue();
	void setValue(int _value);
};
