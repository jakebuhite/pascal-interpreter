#include "Token.h"

Token::Token() {
	tokenType = tkType::END;
	value = 0;
}

Token::Token(tkType _tokenType, int _value) {
	tokenType = _tokenType;
	value = _value;
}

std::string Token::ToString() {
	std::string strToken = "";
	switch (tokenType) {
	case tkType::INTEGER:
		strToken = "INTEGER";
		break;
	case tkType::PLUS:
		strToken = "PLUS";
		break;
	case tkType::END:
		strToken = "END";
		break;
	default:
		strToken = "UNKNOWN";
	}
	return "Token(" + strToken + ", " + std::to_string(value) + ")";
}

tkType Token::getType() {
	return tokenType;
}

int Token::getValue() {
	return value;
}

void Token::setValue(int _value) {
	value = _value;
}