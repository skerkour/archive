/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 14:01:39 by skerkour          #+#    #+#             */
/*   Updated: 2016/03/31 14:01:39 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "catch.hpp"

#include "Token.hpp"

namespace Catch {
    template<> struct StringMaker<Token> {
        static std::string convert( Token const& value ) {
            return value.toString(); 
        } 
    }; 
}

TEST_CASE("[TokenPosition]") {

    SECTION("Testing the default constructor") {
        TokenPosition pos;
        REQUIRE(pos.line == 0);
        REQUIRE(pos.col == 0);
    }

    SECTION("Testing the (uint, uint) constructor") {
        TokenPosition pos{3, 42};
        REQUIRE(pos.line == 3);
        REQUIRE(pos.col == 42);
    }

    SECTION("Testing the copy constructor") {
        TokenPosition pos{3, 42};
        TokenPosition pos2{pos};
        REQUIRE(pos2.line == 3);
        REQUIRE(pos2.col == 42);
    }
}

TEST_CASE("[Token]") {
    SECTION("Testing the (eTokenType, string, TokenPosition) constructor") {
        Token tok{Token::Double, "42.4242", {0, 42}};
        TokenPosition pos{0, 42};
        REQUIRE(tok.getType() == Token::Double);
        REQUIRE(tok.getValue() == "42.4242");
        REQUIRE(tok.getPos() == pos);

        Token tok2{Token::Double, "42.4242", {0, 42}};
        REQUIRE(tok == tok2);

        Token tok3{Token::Double, "42.4242", {1, 42}};
        REQUIRE(!(tok2 == tok3));
        REQUIRE(tok2 != tok3);
    }
}
