/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 09:53:16 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/19 22:55:25 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "ScavTrap.hpp"

std::string	ScavTrap::_sc_challenges[6] = {
	"Take a photo every day this year of your cat.",
	"Snap a picture of your cat looking evil.",
	"Throw two pieces of toast into a toaster from 10 feet.",
	"Throw 5 ping-pong balls into a glass in 1 minute.",
	"Throw 5 ping-pong balls in a 12 egg carton as fast as possible.",
	"Eat your cat."
};

ScavTrap::ScavTrap()
{
	_init("anonymousSCAV");

	std::cout << "SCAV start bootup sequence. His little name is : "
		<< _name << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	_init(name);

	std::cout << "SCAV start bootup sequence. His little name is : "
		<< _name << std::endl;
}

void	ScavTrap::_init(std::string name)
{
	srand(time(NULL));
	_armor_damage_reduction = 3;
	_energy_points = 50;
	_hit_points = 100;
	_level = 1;
	_max_energy_points = 50;
	_max_hit_points = 100;
	_melee_attack_damage = 20;
	_ranged_damage_attack = 15;
	_name = name;
}

ScavTrap::ScavTrap(const ScavTrap& src)
{
	*this = src;
	srand(time(NULL));

	std::cout << "SCAV start copy sequence. His little name is : "
		<< _name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "SCAVTRAP "
		<< _name << ":  I'M DEAD I'M DEAD OHMYGOD I'M DEAD!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
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

bool	ScavTrap::challengeNewcomer(const std::string& target)
{
	std::string	random_challenge;

	if (_energy_points >= 25) {
		_energy_points -= 25;
		random_challenge = ScavTrap::_sc_challenges[rand() % 6];

		std::cout << "ScavTrap " << _name << " challenge " << target << ": "
			<< random_challenge << std::endl;
		return true;
	} else {
		std::cout << "can't use the super attack, not enought energy points"
			<< std::endl;
		return false;
	}
}

void ScavTrap::rangedAttack(std::string const & target)
{
	std::cout << "SC4V "
			<< this->_name << " attacks "
			<< target << " at range, causing "
			<< this->_ranged_damage_attack << " points of damage !" << std::endl;

}

void ScavTrap::meleeAttack(std::string const & target)
{
	std::cout << "SC4V "
			<< this->_name << " attacks "
			<< target << " at mele, causing "
			<< this->_melee_attack_damage << " points of damage !" << std::endl;
}
