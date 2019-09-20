#ifndef PARSER_HPP
# define PARSER_HPP

#include <string>
#include <vector>

enum Token {
    MoveFwd,
    MoveBack,
    Incr,
    Decr,
    Print,
    Read,
    WhileStart,
    WhileEnd,
    Unknow,
    EOF_
};

class Parser {

public:
    Parser(const std::string& input);
    ~Parser();

    std::vector<Token> instructions() const;

private:
    std::string _input;
};

#endif // PARSER_HPP
