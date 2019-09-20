/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/18 17:50:45 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/19 23:17:22 by skerkour         ###   ########.fr       */
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

ScavTrap::ScavTrap() : _armor_damage_reduction(3),
	_energy_points(50), _hit_points(100), _level(1), _max_energy_points(50),
	_max_hit_points(100), _melee_attack_damage(20), _ranged_damage_attack(15),
	_name("anonymous")
{
	srand(time(NULL));

	std::cout << "start copy sequence. His little name is : "
		<< _name << ". BIG DEAL! I CAN USE INNUENDO, TOO! TONIGHT'S FIGHT IS BETWEEN FLYBOY AND THE VAULT HUNTER...BLOWJOBS!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : _armor_damage_reduction(3),
	_energy_points(50), _hit_points(100), _level(1), _max_energy_points(50),
	_max_hit_points(100), _melee_attack_damage(20), _ranged_damage_attack(15),
	_name(name)
{
	srand(time(NULL));

	std::cout << "start copy sequence. His little name is : "
		<< _name << ". BIG DEAL! I CAN USE INNUENDO, TOO! TONIGHT'S FIGHT IS BETWEEN FLYBOY AND THE VAULT HUNTER...BLOWJOBS!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) :
	_armor_damage_reduction(src.armor_damage_reduction()),
	_energy_points(src.energy_points()), _hit_points(src.hit_points()),
	_level(src.level()), _max_energy_points(src.max_energy_points()),
	_max_hit_points(src.max_hit_points()),
	_melee_attack_damage(src.melee_attack_damage()),
	_ranged_damage_attack(src.ranged_damage_attack()), _name(src.name())
{
	srand(time(NULL));

	std::cout << "start copy sequence. His little name is : "
		<< _name << ". BIG DEAL! I CAN USE INNUENDO, TOO! TONIGHT'S FIGHT IS BETWEEN FLYBOY AND THE VAULT HUNTER...BLOWJOBS!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << _name << " was destructed." << std::endl;
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

		std::cout << "New ScavTrap assault robot copied. His little name is : "
			<< _name << std::endl;
	}
	return *this;
}

unsigned int	ScavTrap::armor_damage_reduction() const
{
	return _armor_damage_reduction;
}

unsigned int	ScavTrap::energy_points() const
{
	return _energy_points;
}

unsigned int	ScavTrap::hit_points() const
{
	return _hit_points;
}

unsigned int	ScavTrap::level() const
{
	return _level;
}

unsigned int	ScavTrap::max_energy_points() const
{
	return _energy_points;
}

unsigned int	ScavTrap::max_hit_points() const
{
	return _max_hit_points;
}

unsigned int	ScavTrap::melee_attack_damage() const
{
	return _melee_attack_damage;
}

std::string	ScavTrap::name() const
{
	return _name;
}

unsigned int	ScavTrap::ranged_damage_attack() const
{
	return _ranged_damage_attack;
}

void	ScavTrap::set_name(std::string name)
{
	_name = name;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (_hit_points + amount >= _max_hit_points) {
		_hit_points = _max_hit_points;
	} else {
		_hit_points += amount;
	}

	std::cout << _name << " was successfully repaired, now he gots "
		<< _hit_points << " HP." << std::endl;
}

bool	ScavTrap::meleeAttack(const std::string& target)
{
	std::cout << "ScavTrap " << _name <<
		" attacks " << target << ", causing " << _melee_attack_damage <<
		" points of damage !" << std::endl;
	return true;
}

bool	ScavTrap::rangedAttack(const std::string& target)
{
	std::cout << "ScavTrap " << _name
		<< " attacks " << target << " at range, causing "
		<< _ranged_damage_attack
		<< " points of damage !" << std::endl;
	return true;
}

void	ScavTrap::takeDamage(unsigned int amount)
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

		std::cout << _name << " take " << amount << " damage points"
			<< std::endl;
	}
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
