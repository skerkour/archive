#include <vector>
#include <array>
#include <iostream>

#include "Interpreter.hpp"
#include "Parser.hpp"

Interpreter::Interpreter() :
    _instructions{}, _data{0}, _dp{_data.begin()},
    _ip{_instructions.cbegin()}, _begin{_instructions.cend()},
    _end{_instructions.cend()} {
}

Interpreter::Interpreter(std::vector<Token> instructions) :
    _instructions{instructions}, _data{0}, _dp{_data.begin()},
    _ip{_instructions.cbegin()}, _begin{_instructions.cend()},
    _end{_instructions.cend()} {
}


Interpreter::~Interpreter() {
}

void Interpreter::clean() {
    _instructions = {};
    _data = {0};
    _dp = {};
    _ip = {};
    _begin = {};
    _end = {};
}
void Interpreter::setInstructions(std::vector<Token> instructions) {
    _instructions = {instructions};
}

void Interpreter::run() {
    auto d_end = _data.cend();
    auto d_begin = _data.cbegin();

    while (_ip != _end) {
        switch (*_ip) {
        case MoveFwd:
            if (_dp != d_end) {
                _dp += 1;
            }
            break;
        case MoveBack:
            if (_dp != d_begin) {
                _dp -= 1;
            }
            break;
        case Incr:
            *_dp += 1;
            break;
        case Decr:
            *_dp -= 1;
            break;
        case Print:
            std::cout << *_dp;
            break;
        case Read:
            std::cin >> *_dp;
            break;
        case WhileStart:
            if (*_dp == 0) {
                _jumpForward();
            }
            break;
        case WhileEnd:
            if (*_dp != 0) {
                _jumpBackward();
            }
            break;
        default:
            break;
        }
        _ip += 1;
    }
}

void Interpreter::_jumpForward() {
    int while_level = 0;

    while (true && _ip != _end) {
        if (*_ip == WhileStart) {
            while_level += 1;
        } else if (*_ip == WhileEnd) {
            while_level -= 1;
            if (while_level == 0) {
                break;
            }
        }
        _ip += 1;
    }
}

void Interpreter::_jumpBackward() {
    int while_level = 0;

    while (true && _ip != _begin) {
        if (*_ip == WhileEnd) {
            while_level += 1;
        } else if (*_ip == WhileStart) {
            while_level -= 1;
            if (while_level == 0) {
                break;
            }
        }
        _ip -= 1;
    }
}
