/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 11:54:24 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/24 22:01:55 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

template<typename T>
void	swap(T& x, T& y)
{
	T	tmp = x;

	x = y;
	y = tmp;
}

template<typename T>
const T&	min(const T& x, const T& y)
{
	return (x < y) ? x : y;
}

template<typename T>
T&	min(T& x, T& y)
{
	return (x < y) ? x : y;
}

template<typename T>
const T&	max(const T& x, const T& y)
{
	return (x > y) ? x : y;
}

template<typename T>
T&	max(T& x, T& y)
{
	return (x > y) ? x : y;
}

int main()
{
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return 0;
}
