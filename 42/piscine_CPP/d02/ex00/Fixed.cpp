/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 13:42:54 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/17 15:36:41 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"

// STATIC VARS
const int	Fixed::_n_frac_bits = 8;

// PUBLIC
Fixed::Fixed() : _raw_bits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src)
{
	std::cout << "Copy constructor called" << std::endl;

	*this = src;
}

Fixed::Fixed(int n) : _raw_bits(n)
{
	std::cout << "Parametric constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" <<std::endl;
}

Fixed&	Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Assignation operator called" << std::endl;

	if (this != &rhs)
		_raw_bits = rhs.getRawBits();
	return *this;
}

int		Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;

	return _raw_bits;
}

void	Fixed::setRawBits(const int raw)
{
	_raw_bits = raw;
}
