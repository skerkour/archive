/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 14:34:52 by skerkour          #+#    #+#             */
/*   Updated: 2016/03/31 14:34:52 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "catch.hpp"

#include "Lexer.hpp"

namespace Catch {
    template<> struct StringMaker<Token> {
        static std::string convert(Token const& value) {
            return value.toString(); 
        } 
    }; 
}

TEST_CASE("[Lexer]") {
    
    SECTION("Testing the default constructor") {
    }
    
    SECTION("Testing the (string) constructor") {
        Lexer lxr{"   "};
        std::vector<Token> expected;
        std::vector<Token> value;

        value = lxr.run();
        expected = {
            {Token::EOF_, "<EOF>", {0, 3}}
        };
        REQUIRE(value == expected);

        lxr.setInput("  float(42) double(42.42) push  \n"
                    " int8(42)##_ ");
        value = lxr.run();
        expected = {
            {Token::Float, "42", {0, 2}},
            {Token::Double, "42.42", {0, 12}},
            {Token::Instruction, "push", {0, 26}},
            {Token::Sep, "\n", {0, 32}},
            {Token::Int8, "42", {1, 1}},
            {Token::Unknown, "##_", {1, 9}},
            {Token::EOF_, "<EOF>", {1, 13}}
        };
        REQUIRE(value == expected);
        
        lxr.setInput("push int32(42)\n\n"
                    "push int32(33)\n"
                    "add\n"
                    "push float(44.55)\n"
                    "; lol\n\n"
                    "mul\n"
                    /*"push double(42.42)\n"
                    "push int32(42)\n"
                    "dump\n"
                    "pop\n"
                    "assert double(42.42)\n"
                    "exit\n"*/);
        value = lxr.run();
        expected = {
            {Token::Instruction, "push", {0, 0}},
            {Token::Int32, "42", {0, 5}},
            {Token::Sep, "\n\n", {0, 14}},
            {Token::Instruction, "push", {2, 0}},
            {Token::Int32, "33", {2, 5}},
            {Token::Sep, "\n", {2, 14}},
            {Token::Instruction, "add", {3, 0}},
            {Token::Sep, "\n", {3, 3}},
            {Token::Instruction, "push", {4, 0}},
            {Token::Float, "44.55", {4, 5}},
            {Token::Sep, "\n", {4, 17}},
            {Token::Sep, "\n", {6, 0}},
            {Token::Token::Instruction, "mul", {7, 0}},
            {Token::Sep, "\n", {7, 3}},

            {Token::EOF_, "<EOF>", {8, 0}}
        };
        REQUIRE(value == expected);

    }
}
