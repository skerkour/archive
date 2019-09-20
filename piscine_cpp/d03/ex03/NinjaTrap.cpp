/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 10:33:13 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/19 23:36:44 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <string>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include "ScavTrap.hpp"

NinjaTrap::NinjaTrap()
{
	_init("anonymousNINJA");

	std::cout << "NINJA start bootup sequence. His little name is : "
		<< _name << std::endl;
}

NinjaTrap::NinjaTrap(std::string name)
{
	_init(name);

	std::cout << "NINJA start bootup sequence. His little name is : "
		<< _name << std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap& src)
{
	*this = src;

	std::cout << "Ninja start copy sequence. His little name is : "
		<< _name << std::endl;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "NINJA "
		<< _name << ":  I'M DEAD I'M DEAD OHMYGOD I'M DEAD!" << std::endl;
}

NinjaTrap& NinjaTrap::operator=(const NinjaTrap& rhs)
{
	if (this != &rhs) {
		_armor_damage_reduction = rhs.armor_damage_reduction();
		_energy_points = rhs.energy_points();
		_hit_points = rhs.energy_points();
		_level = rhs.level();
		_max_energy_points = rhs.max_energy_points();
		_max_hit_points = rhs.max_hit_points();
		_melee_attack_damage = rhs.melee_attack_damage();
		_ranged_damage_attack = rhs.ranged_damage_attack();
		_name = rhs.name();
	}
	return *this;
}

void	NinjaTrap::_init(std::string name)
{
	_armor_damage_reduction = 0;
	_energy_points = 50;
	_hit_points = 60;
	_level = 1;
	_max_energy_points = 120;
	_max_hit_points = 60;
	_melee_attack_damage = 60;
	_ranged_damage_attack = 5;
	_name = name;
}

void	NinjaTrap::ninjaShoebox(const FragTrap& frag) const
{
	std::cout << "NINJA : " << _name
		<< " PUNCH IN BALLS " << frag.name()
		<< " - FRAG -, causing 42 Damage points" << std::endl;
}

void	NinjaTrap::ninjaShoebox(const ScavTrap& scav) const
{
	std::cout << "NINJA : " << _name
		<< " put his SHADOW BLADE in the " << scav.name()
		<< " SCAV weak's body, causing 42 Damage points" << std::endl;
}

void	NinjaTrap::ninjaShoebox(const NinjaTrap& ninja) const
{
	std::cout << "NINJA : " << _name
		<< " POISON the " << ninja.name()
		<< " NINJA, he now got the diarrhea, causing 42 Damage points" << std::endl;
}

void	NinjaTrap::ninjaShoebox(const ClapTrap& ninja) const
{
	std::cout << "NINJA : " << _name
		<< " POISON the " << ninja.name()
		<< " ClaptRAP, he now got the diarrhea, causing 42 Damage points" << std::endl;
}
void NinjaTrap::rangedAttack(std::string const & target)
{
	std::cout << "Ninja "
			<< this->_name << " attacks "
			<< target << " at range, causing "
			<< this->_ranged_damage_attack << " points of damage !" << std::endl;

}

void NinjaTrap::meleeAttack(std::string const & target)
{
	std::cout << "Ninja "
			<< this->_name << " attacks "
			<< target << " at mele, causing "
			<< this->_melee_attack_damage << " points of damage !" << std::endl;
}
