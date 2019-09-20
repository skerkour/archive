/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 18:15:32 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/26 14:57:34 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <stdexcept>
#include <vector>

class Span
{
public:
	class NumberExistsException : public std::exception
	{
	public:
		NumberExistsException();
		NumberExistsException(const NumberExistsException& src);
		virtual ~NumberExistsException() throw();

		NumberExistsException&	operator=(const NumberExistsException& rhs);

		virtual const char*	what() const throw();
	};

	class SpanEmptyException : public std::exception
	{
	public:
		SpanEmptyException();
		SpanEmptyException(const SpanEmptyException& rhs);
		virtual ~SpanEmptyException() throw();

		SpanEmptyException&	operator=(const SpanEmptyException& rhs);

		virtual const char*	what() const throw();
	};

	class SpanFullException : public std::exception
	{
	public:
		SpanFullException();
		SpanFullException(const SpanFullException& src);
		virtual ~SpanFullException() throw();

		SpanFullException&	operator=(const SpanFullException& rhs);

		virtual const char*	what() const throw();
	};

public:
	Span(unsigned int n);
	Span(const Span& src);
	~Span();

	Span& operator=(const Span& rhs);

	unsigned int	n() const;

	void			addNumber(int x);
	unsigned int	longestSpan();
	unsigned int	shortestSpan();

private:
	Span();

	std::vector<int>	_cont;
	unsigned int		_n;
};

#endif // SPAN_HPP
