#include <string>
#include <vector>

#include "Parser.hpp"

Parser::Parser(const std::string& input) : _input{input} {
}

Parser::~Parser() {
}

#include <iostream>
std::vector<Token> Parser::instructions() const {
    std::vector<Token> tokens;
    auto pos = _input.cbegin();
    auto end = _input.cend();
    int while_level = 0;

    while (pos != end) {
        switch (*pos) {
        case '>':
            tokens.push_back(MoveFwd);
            break;
        case '<':
            tokens.push_back(MoveBack);
            break;
        case '+':
            tokens.push_back(Incr);
            break;
        case '-':
            tokens.push_back(Decr);
            break;
        case '.':
            tokens.push_back(Print);
            break;
        case ',':
            tokens.push_back(Read);
            break;
        case '[':
            tokens.push_back(WhileStart);
            while_level += 1;
            break;
        case ']':
            if (while_level == 0) {
                std::cerr << "Error: unexpected WhileEnd" << std::endl;
            }
            tokens.push_back(WhileEnd);
            while_level -= 1;
            break;
        default:
            tokens.push_back(Unknow);
            break;
        }
        pos += 1;
    }
   // tokens.push_back(EOF_);
    
    if (while_level != 0) {
        std::cerr << "Invalid while number" << std::endl;
    }

    return tokens;
}
