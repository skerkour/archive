#ifndef INTERPRETER_HPP
# define INTERPRETER_HPP

#include <vector>
#include <array>

#include "Parser.hpp"

class Interpreter {

public:
    Interpreter();
    Interpreter(std::vector<Token> instructions);
    ~Interpreter();

    void clean();
    void setInstructions(std::vector<Token> instructions);
    void run();

private:
    void _jumpForward();
    void _jumpBackward();

    std::vector<Token> _instructions;
    std::array<char, 30000> _data;
    std::array<char, 30000>::iterator _dp;
    std::vector<Token>::const_iterator _ip;
    std::vector<Token>::const_iterator _begin;
    std::vector<Token>::const_iterator _end;
};

#endif //INTERPRETER_HPP
