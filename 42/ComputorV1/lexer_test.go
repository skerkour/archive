package main

import (
	"testing"
)

func testSameToken(reference, value Token, expected, res bool, t *testing.T) {
	if res != expected {
		t.Error("Error: reference:", reference, "value:", value, "expected:", expected, "got:", res)
	}
}

func TestTokenEquality(t *testing.T) {
	var reference Token
	var value Token
	var expected bool
	var res bool

	reference = Token{L_PARENT, "("}
	value = Token{L_PARENT, ")"}
	expected = false
	res = reference.Equal(value)

	reference = Token{NUMBER, "1.33333333333333333333333398428482"}
	value = Token{NUMBER, "1.33333333333333333333333398428482"}
	expected = true
	res = reference.Equal(value)
	testSameToken(reference, value, expected, res, t)

	reference = Token{EOF, ""}
	value = Token{EOF, ""}
	expected = true
	res = reference.Equal(value)
	testSameToken(reference, value, expected, res, t)

	reference = Token{EOF, ""}
	value = Token{NUMBER, ""}
	expected = false
	res = reference.Equal(value)
	testSameToken(reference, value, expected, res, t)
}

func testTokens(expected, value []Token, t *testing.T) {
	if len(expected) != len(value) {
		t.Error("Error: the list of tokens are not the same length, expected:", expected, "got", value)
	}

	for i, tok := range expected {
		if !tok.Equal(value[i]) {
			t.Error("Error: the list of tokens are not the same at index:", i, "expected:", expected[i], "got", value[i])
		}
	}
}

func TestLexer(t *testing.T) {
	var lexer Lexer
	var str string
	var expected []Token
	var value []Token

	str = ""
	expected = []Token{
		{EOF, "EOF"}}
	value = lexer.Lex(str)
	testTokens(expected, value, t)

	str = " 5 + 4 * X + X^2= X^2  "
	expected = []Token{
		{NUMBER, "5"},
		{PLUS, "+"},
		{NUMBER, "4"},
		{ASTERISK, "*"},
		{VARIABLE, "X"},
		{PLUS, "+"},
		{VARIABLE, "X"},
		{EXPONENT, "^2"},
		{EQUAL, "="},
		{VARIABLE, "X"},
		{EXPONENT, "^2"},
		{EOF, "EOF"}}
	value = lexer.Lex(str)
	testTokens(expected, value, t)

	str = " 5 + 4 * X +    # -42.42"
	expected = []Token{
		{NUMBER, "5"},
		{PLUS, "+"},
		{NUMBER, "4"},
		{ASTERISK, "*"},
		{VARIABLE, "X"},
		{PLUS, "+"},
		{ERROR, "#"}}
	value = lexer.Lex(str)
	testTokens(expected, value, t)

	str = "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"

	str = "5 * X^0 + 4 * X^1 = 4 * X^0"

	str = "8 * X^0 - 6 * X^1 + 0 * X^2 - 5.6 * X^3 = 3 * X^0"

	str = "	4 * X^0 + 4 * X^1 - 9.3 * X^2=0"
	expected = []Token{
		{NUMBER, "4"},
		{ASTERISK, "*"},
		{VARIABLE, "X"},
		{EXPONENT, "^0"},
		{PLUS, "+"},
		{NUMBER, "4"},
		{ASTERISK, "*"},
		{VARIABLE, "X"},
		{EXPONENT, "^1"},
		{MINUS, "-"},
		{NUMBER, "9.3"},
		{ASTERISK, "*"},
		{VARIABLE, "X"},
		{EXPONENT, "^2"},
		{EQUAL, "="},
		{NUMBER, "0"},
		{EOF, "EOF"}}
	value = lexer.Lex(str)
	testTokens(expected, value, t)

	str = " (1+2)* 3.43 - 42 / (1.337 + 10^-5)  "
	expected = []Token{
		{L_PARENT, "("},
		{NUMBER, "1"},
		{PLUS, "+"},
		{NUMBER, "2"},
		{R_PARENT, ")"},
		{ASTERISK, "*"},
		{NUMBER, "3.43"},
		{MINUS, "-"},
		{NUMBER, "42"},
		{SLASH, "/"},
		{L_PARENT, "("},
		{NUMBER, "1.337"},
		{PLUS, "+"},
		{NUMBER, "10"},
		{EXPONENT, "^-5"},
		{R_PARENT, ")"},
		{EOF, "EOF"}}
	value = lexer.Lex(str)
	testTokens(expected, value, t)
}
