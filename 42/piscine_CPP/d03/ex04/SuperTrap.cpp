/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 11:00:45 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/19 22:53:41 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "SuperTrap.hpp"

SuperTrap::SuperTrap()
{
	SuperTrap::_init("anonymousSUPERTRAP");

	std::cout << "SUPERTRAP  start bootup sequence. His little name is : "
		<< _name << std::endl;
}

SuperTrap::SuperTrap(std::string name)
{
	SuperTrap::_init(name);

	std::cout << "SUPERTRAP start bootup sequence. His little name is : "
		<< _name << std::endl;
}

SuperTrap::SuperTrap(const SuperTrap& src)
{
	*this = src;

	std::cout << "SuperTrap start copy sequence. His little name is : "
		<< _name << std::endl;
}

SuperTrap::~SuperTrap()
{
	std::cout << "SPERTRAP "
		<< _name << ":  I'M DEAD I'M DEAD OHMYGOD I'M DEAD!" << std::endl;
}

SuperTrap& SuperTrap::operator=(const SuperTrap& rhs)
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

void	SuperTrap::_init(std::string name)
{
	srand(time(NULL));
	_armor_damage_reduction = 5;
	_energy_points = 50;
	_hit_points = 100;
	_level = 1;
	_max_energy_points = 120;
	_max_hit_points = 100;
	_melee_attack_damage = 60;
	_ranged_damage_attack = 20;
	_name = name;
}

void 	SuperTrap::rangedAttack(std::string const & target)
{
	FragTrap::rangedAttack(target);
}

void	SuperTrap::meleeAttack(std::string const & target)
{
	NinjaTrap::rangedAttack(target);
}
