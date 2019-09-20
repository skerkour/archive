/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 11:29:21 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/16 11:54:59 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony*	ponyOnTheHeap(std::string name, int size)
{
	return new Pony(name, size);
}

void	ponyOnTheStack(void)
{
	Pony	lol("yo", 42);
	lol.sayHello();
}

int	main(void)
{
	Pony*	lol = ponyOnTheHeap("lol", 24);

	ponyOnTheStack();
	lol->sayHello();
	delete lol;

	return 0;
}
