/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:02:15 by skerkour          #+#    #+#             */
/*   Updated: 2016/04/01 09:02:15 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
# define PARSER_HPP

#include <vector>

#include "Token.hpp"

class Parser {

public:
    Parser(const std::vector<Token>& tokens);
    ~Parser();

    void validateInput();

private:
    Token _peek(const size_t n = 1) const;
    bool _instructionNeedOperand(const Token& token) const;
    void _validateInstruction();

    std::vector<Token> _tokens;
    std::vector<Token>::const_iterator _pos;
    std::vector<Token>::const_iterator _end;
};

#endif // PARSER_HPP
