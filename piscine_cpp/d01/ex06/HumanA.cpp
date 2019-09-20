/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 17:42:20 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/16 19:31:11 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{}

HumanA::~HumanA()
{}

void	HumanA::attack()
{
	std::cout << _name << " attacks with his "
		<< _weapon.getType() << std::endl;
}

void	HumanA::setWeapon(Weapon& weapon)
{
	_weapon = weapon;
}
