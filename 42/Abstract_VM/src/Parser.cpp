/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:02:05 by skerkour          #+#    #+#             */
/*   Updated: 2016/04/01 09:02:05 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>

#include "Token.hpp"
#include "Parser.hpp"

Parser::Parser(const std::vector<Token>& tokens) : _tokens{tokens} {

}

Parser::~Parser() {
}

#include <iostream>

void Parser::validateInput() {
    _pos = _tokens.cbegin();
    _end = _tokens.cend();

    while (_pos != _end) {
        std::cout << _pos->toString() << std::endl;

        switch (_pos->getType()) {
        case Token::Instruction:
            _validateInstruction();
            break;
        case Token::Sep:
            break;
        case Token::EOF_:
            return;
        case Token::Unknown:
            throw std::logic_error{"unknown :"+_pos->toString()};
            break;
        default:
            break;
        }

     _pos += 1;
    }
}

Token Parser::_peek(const size_t n) const {
    return _pos == _end ? *_pos : *(_pos + n);
}

bool Parser::_instructionNeedOperand(const Token& token) const {
    auto value = token.getValue();

    if (value == "push" || value == "assert") {
        return true;
    }
    return false;
}

void Parser::_validateInstruction() {
    auto next = _peek();
    auto next_type = next.getType();

    if (_instructionNeedOperand(*_pos)) {
        if (next.isOperand()) {
            _pos += 1;
            next = _peek();
            next_type = next.getType();
            if (next_type == Token::Sep) {
                return;
            } else {
                throw std::logic_error{"uexpected "+next.toString()+", need Sep or EOF"};
            }
        } else {
            throw std::logic_error{"Unexpected :"+next.toString()+", need an Operand"};
        }
    } else {
        if (next_type == Token::Sep || next_type == Token::EOF_) {
            return;
        } else {
            throw std::logic_error{"uexpected "+next.toString()+", need Sep or EOF"};
        }
    }
}
