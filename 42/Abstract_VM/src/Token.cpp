/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 12:44:59 by skerkour          #+#    #+#             */
/*   Updated: 2016/04/28 11:49:35 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Token.hpp"

std::array<std::string, 9> Token::tokenTypeStrings{{
	"Instruction",
    "Int8",
    "Int16",
    "Int32",
    "Float",
    "Double",
    "Sep",
    "Unknown",
    "EOF"
}};

std::string Token::tokenTypeToString(eType type) {
    if (type >= Instruction && type <= EOF_) {
        return tokenTypeStrings[type];
    } else {
        return "Error"; // throw an error instead
    }
}

Token::Token() {
}

Token::Token(const eType type, const std::string& value, const TokenPosition& pos) :
    _type{type}, _value{value}, _pos{pos} {
}

Token::~Token() {
}

bool Token::operator==(const Token& rhs) const {
    return _type == rhs.getType() && _value == rhs.getValue() && _pos == rhs.getPos();
}

bool Token::operator!=(const Token& rhs) const {
    return !(*this == rhs);
}

std::ostream& Token::operator<<(std::ostream& os) const {
    os << toString();
    return os;
}

Token::eType Token::getType() const {
    return _type;
}

std::string Token::getValue() const {
    return _value;
}

TokenPosition Token::getPos() const {
    return _pos;
}

bool Token::isOperand() const {
    return (_type == Int8 || _type == Int16 || _type == Int32 || _type == Float
        || _type == Double);
}

const std::string Token::toString() const {
    return "["+ tokenTypeToString(getType())+", '" +_value
        +"', ("+std::to_string(_pos.line)+","+std::to_string(_pos.col)+")]";
}
