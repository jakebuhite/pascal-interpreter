#pragma once
#include <string>
#include <ctype.h>
#include <stdexcept>
#include <iostream>
#include <queue>
#include "Token.h"

class Tokenizer {
private:
	std::string inputTxt;
	int position;
public:
	Tokenizer();
	Tokenizer(std::string _inputTxt);
	Token getNextToken();
};