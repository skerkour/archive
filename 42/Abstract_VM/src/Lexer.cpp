/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 12:45:02 by skerkour          #+#    #+#             */
/*   Updated: 2016/04/28 11:49:44 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <regex>
#include <array>

#include "Lexer.hpp"

std::string Lexer::_int_pattern{"[-]?[0-9]+"};

std::string Lexer::_float_pattern{"[-]?[0-9]+(\\.[0-9]+)?"};

std::regex Lexer::_comment_pattern{"[;].*\\n"};

std::array<std::regex, 6> Lexer::_token_patterns{{
    std::regex{"push|pop|dump|assert|add|sub|mul|div|mod|print|exit"}, // Instructions
    std::regex{"int8\\(("+_int_pattern+")\\)"}, // Int8
    std::regex{"int16\\(("+_int_pattern+")\\)"}, // Int16
    std::regex{"int32\\(("+_int_pattern+")\\)"}, // Int32
    std::regex{"float\\(("+_float_pattern+")\\)"}, // Float
    std::regex{"double\\(("+_float_pattern+")\\)"}, // Double
}};

std::array<Token::eType, 6> Lexer::_token_types{{
    Token::Instruction,
    Token::Int8,
    Token::Int16,
    Token::Int32,
    Token::Float,
    Token::Double
}};

Lexer::Lexer() {

}

Lexer::Lexer(const std::string& input) : _input{input}, _tokens{},
    _has_unknown{false}, _pos{_input.cbegin()}, _end{_input.cend()}, _line{0}, _col{0} {
}

Lexer::~Lexer() {
}

std::string Lexer::getInput() const {
    return _input;
}

void Lexer::setInput(const std::string& input) {
    clean();
    _input = input;
}

std::vector<Token> Lexer::getTokens() const {
    return _tokens;
}

bool Lexer::hasUnknown() const {
    return _has_unknown;
}

void Lexer::clean() {
    _input.erase();
    _tokens.clear();
}

std::vector<Token> Lexer::run() {
    _pos = _input.cbegin();
    _end = _input.cend();
    _col = 0;
    _line = 0;

    Token token{_next()};

    while (true) {
        _tokens.push_back(token);
        if (token.getType() == Token::EOF_) {
            break;
        }
        token = _next();
    }

    return _tokens;
}
#include <iostream>

Token Lexer::_next() {
    if (_pos == _end) {
        return {Token::EOF_, "<EOF>", {_line, _col}};
    }

    std::smatch sm;


    if (*_pos == '\n') {
        return _consumeSep();
    } else if (isspace(*_pos)) {
        return _consumeSpaces();
    } else if (std::regex_search(_pos, _end, sm, _comment_pattern,
        std::regex_constants::match_continuous)) {
        _pos += sm.length();
        _line += 1;
        _col = 0;
        return _next();
        
    } else {
        size_t i = 0;

        for (auto& r : _token_patterns) {
            if (std::regex_search(_pos, _end, sm, r, std::regex_constants::match_continuous)) {
                Token ret{_token_types[i], sm.str(sm.size() > 1 ? 1 : 0), {_line, _col}};
                _col += sm.length();
                _pos += sm.length();
                return ret;
            }
            i += 1;
        }

        return _consumeUnknown();
    }
}

Token Lexer::_consumeSep() {
    auto start = _pos;

    while (*_pos == '\n' && _pos != _end) {
        _pos += 1;
    }

    Token ret{Token::Sep, std::string{start, _pos}, {_line, _col}};
    _line += _pos - start;
    _col = 0;
    return ret;
}

Token Lexer::_consumeSpaces() {
    while (isspace(*_pos) && *_pos != '\n') {
        _col += 1;
        _pos += 1;
    }
    return _next();
}

Token Lexer::_consumeUnknown() {
    auto start = _pos;

    while (!isspace(*_pos) && _pos != _end) {
        for (auto& p : _token_patterns) {
            if (std::regex_search(_pos, _end, p, std::regex_constants::match_continuous)) {
                break;
            }
        }
        _pos += 1;
    }
    
    Token ret {Token::Unknown, std::string{start, _pos}, {_line, _col}};
    _col += _pos - start;
    return ret;
}
