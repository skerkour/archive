/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 18:14:52 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/26 15:00:17 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <vector>

#include "easyfind.hpp"
#include "Span.hpp"

Span::NumberExistsException::NumberExistsException()
{
}

Span::NumberExistsException::NumberExistsException(
	const NumberExistsException& src)
{
	*this = src;
}

Span::NumberExistsException::~NumberExistsException() throw()
{
}

Span::NumberExistsException&	Span::NumberExistsException::operator=(
	const NumberExistsException& rhs)
{
	static_cast<void>(rhs);
	return *this;
}

const char*	Span::NumberExistsException::what() const throw()
{
	return ("Error: span is full");
}


Span::SpanEmptyException::SpanEmptyException()
{
}

Span::SpanEmptyException::SpanEmptyException(const SpanEmptyException& rhs)
{
	*this = rhs;
}

Span::SpanEmptyException::~SpanEmptyException() throw()
{
}

Span::SpanEmptyException&	Span::SpanEmptyException::operator=(
	const SpanEmptyException& rhs)
{
	static_cast<void>(rhs);
	return *this;
}

const char*	Span::SpanEmptyException::what() const throw()
{
	return ("Error: Span is empty");
}


Span::SpanFullException::SpanFullException()
{
}

Span::SpanFullException::SpanFullException(const SpanFullException& src)
{
	*this = src;
}

Span::SpanFullException::~SpanFullException() throw()
{
}

Span::SpanFullException&	Span::SpanFullException::operator=(
	const SpanFullException& rhs)
{
	static_cast<void>(rhs);
	return *this;
}

const char*	Span::SpanFullException::what() const throw()
{
	return ("Error: Span is full");
}

////////////////////////////////////////////////////////////////////////////////

Span::Span(unsigned int n) : _n(n)
{
}

Span::Span(const Span& src)
{
	*this = src;
}

Span::~Span()
{
}

Span&	Span::operator=(const Span& rhs)
{
	if (this != &rhs) {
		_n = rhs._n;
		for (unsigned int i = 0; i < _n; ++i) {
			_cont.push_back(rhs._cont[i]);
		}
	}
	return *this;
}

unsigned int	Span::n() const
{
	return _n;
}

void	Span::addNumber(int x)
{
	if (easyfind(_cont, x)) {
		throw NumberExistsException();
	} else {
		_cont.push_back(x);
		std::sort(_cont.begin(), _cont.end());
	}
}

unsigned int	Span::longestSpan()
{
	if (!_n) {
		throw SpanEmptyException();
	} else {
		return _cont[_n - 1];
	}
}

unsigned int	Span::shortestSpan()
{
	if (!_n) {
		throw SpanEmptyException();
	} else {
		return _cont[0];
	}
}

Span::Span() : _n(0)
{
}
