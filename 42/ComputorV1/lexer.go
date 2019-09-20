package main

import (
	"fmt"
	"strings"
	"unicode"
	"unicode/utf8"
)

type Token struct {
	Type TokenType
	Text string
}

type TokenType int64

const (
	NUMBER TokenType = iota
	EXPONENT
	VARIABLE
	L_PARENT
	R_PARENT
	DOT
	PLUS
	MINUS
	ASTERISK
	SLASH
	PERCENT
	EQUAL
	EOF
	ERROR
)

var TokenTypeStrings = []string{
	"Number",
	"Exponent",
	"Variable",
	"L_Parent",
	"R_Parent",
	"Dot",
	"Plus",
	"Minus",
	"Asterisk",
	"Slash",
	"Percent",
	"Equal",
	"EOF",
	"ERROR"}

type Lexer struct {
	input string
	start int
	pos   int
	width int    // the width of the last read rune
	value string // the text of the last read token
}

const eof = -1

func (tokenType TokenType) String() (ttype string) {
	return TokenTypeStrings[tokenType]
}

func (token Token) String() string {
	return "('" + token.Type.String() + "', '" + token.Text + "')"
}

func (token Token) Equal(b Token) bool {
	return token.Type == b.Type && token.Text == b.Text
}

func (lxr *Lexer) Lex(input string) (tokens []Token) {
	lxr.input = input
	lxr.start = 0
	lxr.pos = 0
	lxr.width = 0
	lxr.value = ""

	for token := lxr.Next(); ; token = lxr.Next() {
		tokens = append(tokens, token)
		if token.Type == ERROR || token.Type == EOF {
			break
		}
	}

	return tokens
}

func (lxr Lexer) Error() string {
	return fmt.Sprintf("Unexpected Token: '%c' at column: %d", lxr.input[lxr.pos], lxr.pos)
}

func (lxr *Lexer) consume() rune {
	if lxr.pos >= len(lxr.input) {
		lxr.width = 0
		return eof
	}
	c, w := utf8.DecodeRuneInString(lxr.input[lxr.pos:])
	lxr.pos += w
	lxr.width = w
	return c
}

func (lxr *Lexer) backup() {
	lxr.pos -= lxr.width
}

func (lxr *Lexer) peek() rune {
	c := lxr.consume()
	lxr.backup()
	return c
}

func (lxr *Lexer) match(c rune) bool {
	if c == lxr.consume() {
		return true
	}
	lxr.backup()
	return false
}

func (lxr *Lexer) matchAndConsumeOneOf(valid string) {
	for strings.ContainsRune(valid, lxr.consume()) {
	}
	lxr.backup()
}

func (lxr *Lexer) matchOneOf(valid string) bool {
	if strings.ContainsRune(valid, lxr.consume()) {
		return true
	}

	lxr.backup()
	return false
}

func (lxr *Lexer) matchOne(f func(c rune) bool) bool {
	c := lxr.consume()
	if f(c) {
		return true
	}

	lxr.backup()
	return false
}

func (lxr *Lexer) matchAndConsumeWhile(f func(c rune) bool) {
	for c := lxr.consume(); f(c); c = lxr.consume() {
	}
	lxr.backup()
}

func (lxr *Lexer) Next() Token {
	tokenType := lxr.next()
	if tokenType == EOF {
		return Token{tokenType, tokenType.String()}
	} else if tokenType == ERROR {
		lxr.backup()
		return Token{tokenType, string(lxr.input[lxr.pos])}
	}

	text := lxr.input[lxr.start:lxr.pos]
	return Token{tokenType, text}
}

func (lxr *Lexer) consumeSpaces() {
	c := ' '
	for unicode.IsSpace(c) && c != eof {
		c = lxr.consume()
	}
	lxr.backup()
}

func (lxr *Lexer) next() TokenType {
	lxr.start = lxr.pos
	c := lxr.consume()
	switch {
	case c == eof:
		return EOF
	case unicode.IsSpace(c):
		lxr.consumeSpaces()
		return lxr.next()
	case c == '(':
		return L_PARENT
	case c == ')':
		return R_PARENT
	case c == '.':
		return DOT
	case c == '+':
		return PLUS
	case c == '-':
		return MINUS
	case c == '*':
		return ASTERISK
	case c == '/':
		return SLASH
	case c == '%':
		return PERCENT
	case c == '=':
		return EQUAL
	case unicode.IsDigit(c):
		return lxr.consumeNumber()
	case c == '^':
		return lxr.consumeExponent()
	case unicode.IsLetter(c):
		return lxr.consumeVariable()
	default:
		return ERROR
	}
}

func (lxr *Lexer) consumeNumber() TokenType {
	lxr.matchAndConsumeWhile(unicode.IsDigit)
	if lxr.match('.') {
		lxr.matchAndConsumeWhile(unicode.IsDigit)
	}
	return NUMBER
}

func (lxr *Lexer) consumeVariable() TokenType {
	lxr.matchAndConsumeWhile(unicode.IsLetter)
	return VARIABLE
}

func (lxr *Lexer) consumeExponent() TokenType {
	lxr.matchOneOf("+-")
	lxr.consumeNumber()
	if lxr.pos-lxr.start == 2 && (lxr.input[lxr.pos-1] == '-' || lxr.input[lxr.pos-1] == '+') {
		return ERROR
	}
	return EXPONENT
}
