/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EvalExpr.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/18 16:22:40 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/18 22:01:44 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVALEXPR_HPP
# define EVALEXPR_HPP

#include <string>

#include "Fixed.hpp"

class EvalExpr
{
public:
	EvalExpr();
	EvalExpr(const EvalExpr& src);
	~EvalExpr();

	EvalExpr& operator=(const EvalExpr& rhs);

	std::string	expression() const;

	bool		checkForInvalidExpression();
	Fixed		computeValue();
	Fixed		evalParenthesis(std::istringstream& iss);
	bool		evaluate(const std::string& expression);
	void		errorInvalidExp();
	static bool	isFloat(const std::string& word);
	void		removeWhiteSpaces();
	Fixed		strToFixed(std::string str);

	char		peek();
	char		get();
	Fixed		getNumber();
	Fixed		expression();
	Fixed		term();

private:
	std::string	_expression;
	char*		_expression_cstr;
	char*		_start;
	bool		_error;
	
};

#endif // EVALEXPR_HPP
