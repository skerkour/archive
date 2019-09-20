/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 11:22:39 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/20 23:33:43 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include "AMateria.hpp"
#include "Character.hpp"

Character::Character()
{
}

Character::Character(const std::string& name) : _name(name), _n_index(0)
{
	_inventory[0] = NULL;
	_inventory[1] = NULL;
	_inventory[2] = NULL;
	_inventory[3] = NULL;
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
		_inventory[0] = NULL;
		_inventory[1] = NULL;
		_inventory[2] = NULL;
		_inventory[3] = NULL;

		_inventory[0] = rhs._inventory[0]->clone();
		_inventory[1] = rhs._inventory[1]->clone();
		_inventory[2] = rhs._inventory[2]->clone();
		_inventory[3] = rhs._inventory[3]->clone();

		_name = rhs._name;
		_n_index = rhs._n_index;
	}
	return *this;
}

const std::string&	Character::getName() const
{
	return _name;
}

void	Character::equip(AMateria* m)
{
	if (_n_index < 3) {
		_inventory[_n_index] = m;
		_n_index++;
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3) {
		_inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < _n_index) {
		_inventory[idx]->use(target);
	}
}
