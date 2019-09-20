/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/18 18:34:41 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/19 10:02:59 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _armor_damage_reduction(5),
	_energy_points(100), _hit_points(100), _level(1), _max_energy_points(100),
	_max_hit_points(100), _melee_attack_damage(30), _ranged_damage_attack(20),
	_name("anonymousClapTrap")
{
	srand(time(NULL));

	std::cout << "CLAPTRAP start bootup sequence. His little name is : "
		<< _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	*this = src;
	srand(time(NULL));

	std::cout << "CLAPTRAP start copy sequence. His little name is : "
		<< _name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "CLAPTRAP "
		<< _name << ":  I'M DEAD I'M DEAD OHMYGOD I'M DEAD!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
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

unsigned int	ClapTrap::armor_damage_reduction() const
{
	return _armor_damage_reduction;
}

unsigned int	ClapTrap::energy_points() const
{
	return _energy_points;
}

unsigned int	ClapTrap::hit_points() const
{
	return _hit_points;
}

unsigned int	ClapTrap::level() const
{
	return _level;
}

unsigned int	ClapTrap::max_energy_points() const
{
	return _energy_points;
}

unsigned int	ClapTrap::max_hit_points() const
{
	return _max_hit_points;
}

unsigned int	ClapTrap::melee_attack_damage() const
{
	return _melee_attack_damage;
}

std::string	ClapTrap::name() const
{
	return _name;
}

unsigned int	ClapTrap::ranged_damage_attack() const
{
	return _ranged_damage_attack;
}

void	ClapTrap::set_name(std::string& name)
{
	_name = name;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit_points + amount >= _max_hit_points) {
		_hit_points = _max_hit_points;
	} else {
		_hit_points += amount;
	}

	std::cout << _name << " was successfully repaired, now he gots "
		<< _hit_points << " HP." << std::endl;
}

bool	ClapTrap::meleeAttack(const std::string& target)
{
	std::cout << _name <<
		" attacks " << target << ", causing " << _melee_attack_damage <<
		" points of damage !" << std::endl;
	return true;
}

bool	ClapTrap::rangedAttack(const std::string& target)
{
	std::cout << _name
		<< " attacks " << target << " at range, causing "
		<< _ranged_damage_attack
		<< " points of damage !" << std::endl;
	return true;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount <= _armor_damage_reduction) {
		std::cout << "No damages taken, " << _name << "'s armor is good"
			<< std::endl;
		return ;
	} else {
		amount -= _armor_damage_reduction;
		if (amount >= _hit_points) {
			amount = _hit_points;
			_hit_points = 0;
		} else {
			_hit_points -= amount;
		}

		std::cout << _name << " takes " << amount << " damage points"
			<< std::endl;
	}
}
