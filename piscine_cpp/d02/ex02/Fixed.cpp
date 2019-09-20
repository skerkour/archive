/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 13:42:54 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/17 18:51:38 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>

#include "Fixed.hpp"

// STATIC VARS
const int	Fixed::_n_frac_bits = 8;

// PUBLIC
Fixed::Fixed() : _raw_bits(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src)
{
	//std::cout << "Copy constructor called" << std::endl;

	*this = src;
}

Fixed::Fixed(int n) : _raw_bits((long)(n << _n_frac_bits))
{
	//std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : _raw_bits(roundf(f * (1 << _n_frac_bits)))
{
	//std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" <<std::endl;
}

Fixed&	Fixed::operator=(const Fixed& rhs)
{
	//std::cout << "Assignation operator called" << std::endl;

	if (this != &rhs)
		_raw_bits = rhs.getRawBits();
	return *this;
}

bool	Fixed::operator>(const Fixed& rhs) const
{
	return _raw_bits > rhs.getRawBits();
}

bool	Fixed::operator<(const Fixed& rhs) const
{
	return _raw_bits < rhs.getRawBits();
}

bool	Fixed::operator>=(const Fixed& rhs) const
{
	return _raw_bits >= rhs.getRawBits();
}

bool	Fixed::operator<=(const Fixed& rhs) const
{
	return _raw_bits <= rhs.getRawBits();
}

bool	Fixed::operator==(const Fixed& rhs) const
{
	return _raw_bits == rhs.getRawBits();
}

bool	Fixed::operator!=(const Fixed& rhs) const
{
	return _raw_bits != rhs.getRawBits();
}

Fixed	Fixed::operator+(const Fixed& rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(const Fixed& rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(const Fixed& rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(const Fixed& rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed&	Fixed::operator++()
{
	++_raw_bits;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);

	++_raw_bits;
	return tmp;
}

Fixed&	Fixed::operator--()
{
	--_raw_bits;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	--_raw_bits;
	return tmp;
}

int		Fixed::getRawBits() const
{
	//std::cout << "getRawBits member function called" << std::endl;

	return _raw_bits;
}

void	Fixed::setRawBits(const int raw)
{
	_raw_bits = raw;
}

float	Fixed::toFloat() const
{
	return (float)(_raw_bits / (float)(1 << _n_frac_bits));
}

int	Fixed::toInt() const
{
	return (_raw_bits >> _n_frac_bits);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return a < b ? a : b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return a < b ? a : b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return a > b ? a : b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return a > b ? a : b;
}

std::ostream&	operator<<(std::ostream& o, const Fixed& rhs)
{
	o << rhs.toFloat();
	return o;
}
