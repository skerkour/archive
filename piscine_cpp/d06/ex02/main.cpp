/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 20:49:09 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/24 15:53:40 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base*	generate()
{
	Base*	ret;

	switch (rand() % 3) {
		case 0:
			ret = new A();
			break;
		case 1:
			ret = new B();
			break;
		case 2:
			ret = new C();
			break;
	}
	return ret;
}

void identify_from_pointer(Base* p)
{
	A*	a = dynamic_cast<A*>(p);
	B*	b = dynamic_cast<B*>(p);
	C*	c = dynamic_cast<C*>(p);

	if (a != NULL) {
		std::cout << "A" << std::endl;
	} else if (b != NULL) {
		std::cout << "B" << std::endl;
	} else if (c != NULL) {
		std::cout << "C" << std::endl;
	}
}

void	identify_from_reference(Base& p)
{
	try {
		A&	a = dynamic_cast<A&>(p);
		std::cout << "A"  << std::endl;
		static_cast<void>(a);
	} catch (std::bad_cast& bc) {
	}

	try {
		B&	b = dynamic_cast<B&>(p);
		std::cout << "B"  << std::endl;
		static_cast<void>(b);
	} catch (std::bad_cast& bc) {
	}

	try {
		C&	c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		static_cast<void>(c);
	} catch (std::bad_cast& bc) {
	}
}

int main()
{
	srand(time(NULL));

	Base*	b = generate();

	identify_from_pointer(b);
	identify_from_reference(*b);
	return 0;
}
