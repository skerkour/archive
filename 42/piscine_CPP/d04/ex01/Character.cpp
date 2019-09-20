/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 14:40:00 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/19 17:19:20 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "AWeapon.hpp"
#include "Character.hpp"
#include "Enemy.hpp"

Character::Character()
{
}

Character::Character(const std::string& name) : _ap(40), _name(name),
	_weapon(NULL)
{
}

Character::Character(const Character& src)
{
	*this = src;
}

Character::~Character()
{
}

Character& Character::operator=(const Character& rhs)
{
	if (this != &rhs) {
		_ap = rhs._ap;
		_name = rhs._name;
		_weapon = rhs._weapon;
	}
	return *this;
}

void	Character::recoverAP()
{
	if (_ap + 10 >= 40) {
		_ap = 40;
	} else {
		_ap += 10;
	}
}

void	Character::equip(AWeapon* weapon)
{
	_weapon = weapon;
}

void	Character::attack(Enemy* enemy)
{
	int	ap_cost;

	if (_weapon && enemy) {
		ap_cost = _weapon->getAPCost();
		if (_ap - ap_cost >= 0) {
			std::cout << _name << " attacks " << enemy->getType()
				<< " with a " << _weapon->getName() << std::endl;
			_weapon->attack();
			enemy->takeDamage(_weapon->getDamage());
			if (enemy->getHP() <= 0) {
				delete enemy;
			}
			_ap -= ap_cost;
		}
	}
}

const std::string	Character::getName() const
{
	return _name;
}

int	Character::getAp() const
{
	return _ap;
}

AWeapon*	Character::getWeapon() const
{
	return _weapon;
}

std::ostream&	operator<<(std::ostream& o, const Character& rhs)
{
	if (rhs.getWeapon()) {
		o << rhs.getName() << " has " << rhs.getAp()
			<< " AP and wields a " << rhs.getWeapon()->getName() << std::endl;
	} else {
		o << rhs.getName() << " has " << rhs.getAp()
			<< " AP and is unarmed" << std::endl;
	}
	return o;
}
