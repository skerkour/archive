/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 09:46:15 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/19 23:23:59 by skerkour         ###   ########.fr       */
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

FragTrap::FragTrap()
{
	_init("anonymousFRAGPTRAP");
	_armor_damage_reduction = 5;

	std::cout << " FRAG start bootup sequence. His little name is : "
		<< _name << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	_init(name);
	std::cout << "FRAG start bootup sequence. His little name is : "
		<< _name << std::endl;
}

void	FragTrap::_init(std::string name)
{
	srand(time(NULL));
	_armor_damage_reduction = 5;
	_energy_points = 100;
	_hit_points = 100;
	_level = 1;
	_max_energy_points = 100;
	_max_hit_points = 100;
	_melee_attack_damage = 30;
	_ranged_damage_attack = 20;
	_name = name;
}

FragTrap::FragTrap(const FragTrap& src)
{
	*this = src;
	srand(time(NULL));

	std::cout << "FRAG start copy sequence. His little name is : "
		<< _name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FRAGTRAP "
		<< _name << ":  I'M DEAD I'M DEAD OHMYGOD I'M DEAD!" << std::endl;
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

void FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "FR4G-TP "
			<< this->_name << " attacks "
			<< target << " at range, causing "
			<< this->_ranged_damage_attack << " points of damage !" << std::endl;

}

void FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "FR4G-TP "
			<< this->_name << " attacks "
			<< target << " at mele, causing "
			<< this->_melee_attack_damage << " points of damage !" << std::endl;
}
