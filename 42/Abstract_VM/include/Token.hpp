/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 12:45:08 by skerkour          #+#    #+#             */
/*   Updated: 2016/03/31 12:45:08 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_HPP
# define TOKEN_HPP

#include <cstdlib>
#include <string>
#include <ostream>
#include <array>



struct TokenPosition {
    TokenPosition(const size_t linee = 0, const size_t coll = 0) :
        line{linee}, col{coll} { }
    TokenPosition(const TokenPosition& pos) : line{pos.line}, col{pos.col} { }

    bool operator==(const TokenPosition& rhs) const { return line == rhs.line && col == rhs.col; }
    bool operator!=(const TokenPosition& rhs) const { return !(*this == rhs); }

    size_t line = 0;
    size_t col = 0;
};
using TokenPosition = struct TokenPosition;


class Token {

public:
enum eType {
    Instruction,
    Int8,
    Int16,
    Int32,
    Float,
    Double,
    Sep,
    Unknown,
    EOF_
};

    Token(const eType type, const std::string& value, const TokenPosition& pos);
    ~Token();

    bool operator==(const Token& rhs) const;
    bool operator!=(const Token& rhs) const;
    std::ostream& operator<<(std::ostream& os) const;

    eType getType() const;
    std::string getValue() const;
    TokenPosition getPos() const;
    bool isOperand() const;
    const std::string toString() const;

    static std::array<std::string, 9> tokenTypeStrings;
    static std::string tokenTypeToString(eType type);

private:
    Token();
    eType _type;
    std::string _value;
    TokenPosition _pos;
};

#endif // TOKEN_HPP
