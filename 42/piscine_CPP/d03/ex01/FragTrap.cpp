/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/18 09:53:42 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/18 18:01:48 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "FragTrap.hpp"

FragTrap::t_attack	FragTrap::_random_vh_attacks[6] = {
	{"toxic fart", 42},
	{"fatal thought", 20},
	{"mortal knife", 36},
	{"test", 29},
	{"atomic punch", 24},
	{"supersonic kick", 39}
};

FragTrap::FragTrap() : _armor_damage_reduction(5),
	_energy_points(100), _hit_points(100), _level(1), _max_energy_points(100),
	_max_hit_points(100), _melee_attack_damage(30), _ranged_damage_attack(20),
	_name("anonymous")
{
	srand(time(NULL));

	std::cout << "start bootup sequence. His little name is : "
		<< _name << std::endl;
}

FragTrap::FragTrap(std::string name) : _armor_damage_reduction(5),
	_energy_points(100), _hit_points(100), _level(1), _max_energy_points(100),
	_max_hit_points(100), _melee_attack_damage(30), _ranged_damage_attack(20),
	_name(name)
{
	srand(time(NULL));

	std::cout << "start bootup sequence. His little name is : "
		<< _name << std::endl;
}

FragTrap::FragTrap(const FragTrap& src)
{
	*this = src;
	srand(time(NULL));

	std::cout << "start copy sequence. His little name is : "
		<< _name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << _name << ":  I'M DEAD I'M DEAD OHMYGOD I'M DEAD!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
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

unsigned int	FragTrap::armor_damage_reduction() const
{
	return _armor_damage_reduction;
}

unsigned int	FragTrap::energy_points() const
{
	return _energy_points;
}

unsigned int	FragTrap::hit_points() const
{
	return _hit_points;
}

unsigned int	FragTrap::level() const
{
	return _level;
}

unsigned int	FragTrap::max_energy_points() const
{
	return _energy_points;
}

unsigned int	FragTrap::max_hit_points() const
{
	return _max_hit_points;
}

unsigned int	FragTrap::melee_attack_damage() const
{
	return _melee_attack_damage;
}

std::string	FragTrap::name() const
{
	return _name;
}

unsigned int	FragTrap::ranged_damage_attack() const
{
	return _ranged_damage_attack;
}

void	FragTrap::set_name(std::string& name)
{
	_name = name;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (_hit_points + amount >= _max_hit_points) {
		_hit_points = _max_hit_points;
	} else {
		_hit_points += amount;
	}

	std::cout << _name << " was successfully repaired, now he gots "
		<< _hit_points << " HP." << std::endl;
}

bool	FragTrap::meleeAttack(const std::string& target)
{
	std::cout << "FR4G-TP " << _name <<
		" attacks " << target << ", causing " << _melee_attack_damage <<
		" points of damage !" << std::endl;
	return true;
}

bool	FragTrap::rangedAttack(const std::string& target)
{
	std::cout << "FR4G-TP " << _name
		<< " attacks " << target << " at range, causing "
		<< _ranged_damage_attack
		<< " points of damage !" << std::endl;
	return true;
}

void	FragTrap::takeDamage(unsigned int amount)
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

bool	FragTrap::vaulthunter_dot_exe(const std::string& target)
{
	t_attack	random_attack;

	if (_energy_points >= 25) {
		_energy_points -= 25;
		random_attack = FragTrap::_random_vh_attacks[rand() % 6];

		std::cout << "FR4G-TP " << _name << " does his special attack : "
			<< random_attack.name << ", causing " << random_attack.damages
			<< " points of damage to " << target << " !" << std::endl;
		return true;
	} else {
		std::cout << "can't use the super attack, not enought energy points"
			<< std::endl;
		return false;
	}
}
