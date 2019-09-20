/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EvalExpr.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/18 16:22:44 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/18 22:43:36 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>

#include "EvalExpr.hpp"

EvalExpr::EvalExpr() : _expression_cstr(NULL), _start(NULL), _error(false)
{
}

EvalExpr::EvalExpr(const EvalExpr& src)
{
	*this = src;
}

EvalExpr::~EvalExpr()
{
	if (_start)
		delete[] _start;
}

EvalExpr& EvalExpr::operator=(const EvalExpr& rhs)
{
	if (this != &rhs) {
		_expression = rhs.expression();
	}
	return *this;
}

std::string	EvalExpr::expression() const
{
	return _expression;
}

bool	isFloatStr(char* str)
{
	int	n_dots = 0;
	while (*str && (*str == '.' || (*str >= '0' && *str <= '9'))) {
		if (*str == '.')
			++n_dots;
		++str;
	}
	if (*str && !(*(str - 1) == '.' || (*(str - 1) >= '0' && *(str - 1) <= '9')))
		return false;
	return n_dots <= 1 ? true : false;
}

bool	EvalExpr::checkForInvalidExpression()
{
/*
	std::istringstream	iss(_expression);
	std::string			word;
	int					n_parenthesis = 0;

	while (iss >> word) {
		if (word == "(")
			++n_parenthesis;
		else if (word == ")")
			--n_parenthesis;
		if (!(word == "(" || word == ")" || word == "+"
			|| word == "-" || word == "/" || word == "*"
			|| isFloat(word)))
			return false;
	}
	return !n_parenthesis ? true : false;
*/
	int		n_parenthesis = 0;
	char*	str = _expression_cstr;

	while (*str) {
		if (*str == '(') {
			++n_parenthesis;
		} else if (*str == ')') {
			--n_parenthesis;
		}
		if (!(*str == '(' || *str == ')' || *str == '+'
			|| *str == '-' || *str == '/' || *str == '*'
			|| isFloatStr(str)))
			return false;
		++str;
	}
	return !n_parenthesis ? true : false;
}
/*
void	EvalExpr::computeValue()
{
	std::istringstream	iss(_expression);
	evalParenthesis(iss);

	std::string			word;
	Fixed				ret;
	while (iss >> word) {
		std::cout << word << std::endl;
		if (word == "(") {
			ret = ret + evalParenthesis(iss);
		} else if (word == ")") {
			return (void)ret;
		} else if (word == "+") {
			iss >> word;
			if (!isFloat(word))
				return errorInvalidExp();
			ret = ret + strToFixed(word);
		} else if (word == "-") {
			iss >> word;
			if (!isFloat(word))
				return errorInvalidExp();
			ret = ret - strToFixed(word);
		} else if (word == "/" || word == "0") {
			iss >> word;
			if (!isFloat(word))
				return errorInvalidExp();
			ret = ret / strToFixed(word);
		} else if (word == "*") {
			iss >> word;
			if (!isFloat(word))
				return errorInvalidExp();
			ret = ret * strToFixed(word);
		} else if (isFloat(word)) {
			ret = ret + strToFixed(word);
		}
	}
	std::cout << ret << std::endl;
	
}

Fixed	EvalExpr::evalParenthesis(std::istringstream& iss)
{
	std::string	word;
	Fixed		ret;

	if (!iss >> word) {
		std::cout << ret << std::endl;
		return ret;
	}
	if (word == "(") {

	}


	std::string	word = "(";
	Fixed		ret;

	while (word != ")") {
		iss >> word;
		if (word == "(")
			ret = ret + evalParenthesis(iss);
	}
	return Fixed(21.21f);

}
*/

char	EvalExpr::peek()
{
	return *_expression_cstr;
}

char	EvalExpr::get()
{
	return *_expression_cstr++;
}

Fixed	EvalExpr::getNumber()
{
	std::string	str(_expression_cstr);

	while (peek() == '.' || (peek() >= '0' && peek() <= '9'))
		_expression_cstr++;
	return strToFixed(str);
}

Fixed	EvalExpr::expression()
{
	if (peek() >= '0' && peek() <= '9') {
		return getNumber();
	} else if (peek() == '(') {
		get(); // (
		Fixed	res = computeValue();
		get(); // )
		return res;
	} else if (peek() == '-') {
		get();
		return Fixed(-expression().toFloat());
	}
	_error = true;
	return Fixed(0);
}

Fixed	EvalExpr::term()
{
	Fixed	ret = expression();
	Fixed	tmp;

	while (peek() == '*' || peek() == '/') {
		if (get() == '*') {
			ret = ret * expression();
		} else {
			tmp = expression();
			if (tmp.toFloat() == 0.0f)
				_error = true;
			ret = ret / tmp;
		}
	}
	return ret;
}

Fixed	EvalExpr::computeValue()
{
	Fixed	res = term();

	while (peek() == '+' || peek() == '-') {
		if (get() == '+') {
			res = res + term();
		} else {
			res = res - term();
		}
	}
	if (peek() == '('/* || (peek() == ')'
		&& !(isFloatStr(_expression_cstr + 1) || *(_expression_cstr + 1) == '+'
		|| *(_expression_cstr + 1) == '*' || *(_expression_cstr + 1) == '-'
		|| *(_expression_cstr + 1) == '/'))*/)
		_error = true;
	return res;
}

void	ft_strcpy(char *dest, const char *src)
{
	int i = 0;
	while (src[i]) {
		dest[i] = src[i];
		++i;
	}
	dest[i] = 0;
}

bool	EvalExpr::evaluate(const std::string& expression)
{
	_expression = expression;
	removeWhiteSpaces();
	_expression_cstr = new char[_expression.length()+1];
	ft_strcpy(_expression_cstr, _expression.c_str());
	if (!checkForInvalidExpression()) {
		errorInvalidExp();
		return false;
	}
	Fixed res = computeValue();
	if (_error)
		errorInvalidExp();
	else
		std::cout << res << std::endl;
	return true;
}

void	EvalExpr::errorInvalidExp()
{
	std::cerr << "Error: invalid expression..." << std::endl;
}

static inline bool isFloatRec(const std::string& word, size_t i, int n_dots)
{
	if (!word[i]) {
		return true;
	} else if (!(word[i] >= '0' && word[i] <= '9')) {
		if (word[i] == '.' && !n_dots)
			return isFloatRec(word, i + 1, 1);
		return false;
	} else {
		return isFloatRec(word, i + 1, n_dots);
	}
}

bool	EvalExpr::isFloat(const std::string& word)
{
	return isFloatRec(word, 0, 0);
}

void	EvalExpr::removeWhiteSpaces()
{
	std::istringstream	iss(_expression);
	std::string			word;
	std::string			ret;

	while (iss >> word) {
		ret += word;
	}
	_expression = ret;
}

Fixed	EvalExpr::strToFixed(std::string str)
{
	std::istringstream	iss(str);
	float				tmp;

	iss >> tmp;
	return Fixed(tmp);
}
