/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 15:38:39 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/18 22:21:17 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"

int main()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	
	Fixed	c(2.0f);
	Fixed	d(-3.0f);
	std::cout << (c < d) << std::endl;
	std::cout << (c >=  d) << std::endl;
	std::cout << (c <= d) << std::endl;
	std::cout << (c * d) << std::endl;
	std::cout << (c / d) << std::endl;
	std::cout << (c - d) << std::endl;
	std::cout << (c + d) << std::endl;
	std::cout << (c == 3) << std::endl;
	std::cout << (c != d) << std::endl;
	std::cout << (c > d) << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	return 0;
}
