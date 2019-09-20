/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 21:19:59 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/25 11:42:57 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include <string>

#include "Array.hpp"

int main()
{
	{
	Array<int> a(42);
	a[3] = 42;
	Array<int> b(a);

	for (int i = 0; i < 42; ++i) {
		std::cout << b[i] << std::endl;
	}
	try {
		std::cout << "error index start" << std::endl;
		std::cout << a[42] << std::endl;
		std::cout << "error index end" << std::endl;
	} catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	}

	return 0;
};
