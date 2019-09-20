/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 14:40:27 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/19 17:08:33 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::SuperMutant(const SuperMutant& src)
{
	*this = src;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh ..." <<std::endl;
}

SuperMutant& SuperMutant::operator=(const SuperMutant& rhs)
{
	if (this != &rhs) {
		_hp = rhs._hp;
		_type = rhs._type;
	}
	return *this;
}
void	SuperMutant::takeDamage(int n)
{
	n -= 3;

	if (n < 0) {
		return ;
	} else if (_hp - n <= 0) {
		_hp = 0;
	} else {
		_hp -= n;
	}
}
