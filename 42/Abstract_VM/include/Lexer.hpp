/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 12:45:14 by skerkour          #+#    #+#             */
/*   Updated: 2016/03/31 12:45:14 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_HPP
# define LEXER_HPP

#include <string>
#include <vector>
#include <array>
#include <regex>

#include "Token.hpp"

class Lexer {

public:
    Lexer();
    Lexer(const std::string& input);
    ~Lexer();

    std::string getInput() const;
    void setInput(const std::string& input);
    std::vector<Token> getTokens() const;
    bool hasUnknown() const;
    void clean();
    std::vector<Token> run();

private:
    Token _next();
    Token _consumeSep();
    Token _consumeSpaces();
    Token _consumeUnknown();

    std::string _input;
    std::vector<Token> _tokens;
    bool _has_unknown;
    std::string::const_iterator _pos;
    std::string::const_iterator _end;
    size_t _line;
    size_t _col;
    static std::array<std::regex, 6> _token_patterns;
    static std::array<Token::eType, 6> _token_types;
    static std::string _int_pattern;
    static std::string _float_pattern;
    static std::regex _comment_pattern;
};

#endif // LEXER_HPP
