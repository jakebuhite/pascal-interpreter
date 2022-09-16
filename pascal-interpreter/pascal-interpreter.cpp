// pascal-interpreter.cpp
#include <iostream>
#include "Token.h"
#include "Interpreter.h"

int main()
{
    std::string input;

    // Get input
    std::cout << "Please enter a calculation: ";
    std::getline(std::cin, input);

    // Check to see if there's whitespace
    input.erase(remove(input.begin(), input.end(), ' '), input.end());

    // Interpret Pascal using Tokenizer
    Tokenizer tokenizer = Tokenizer(input);
    Interpreter interpreter = Interpreter(tokenizer);

    // Perform calculations
    int result = interpreter.performExpr();

    // Share results
    std::cout << "The answer is " << result << std::endl;
}
