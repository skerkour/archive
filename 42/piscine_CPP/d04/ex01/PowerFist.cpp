/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 14:40:17 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/19 17:09:08 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50)
{
}

PowerFist::PowerFist(const PowerFist& src)
{
	*this = src;
}

PowerFist::~PowerFist()
{
}

PowerFist&	PowerFist::operator=(const PowerFist& rhs)
{
	if (this != &rhs) {
		_name = rhs._name;
		_ap_cost = rhs._ap_cost;
		_damage = rhs._damage;
	}
	return *this;
}

void	PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
