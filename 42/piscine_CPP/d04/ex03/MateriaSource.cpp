/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 11:23:15 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/20 23:38:27 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _n_index(0)
{
	_inventory[0] = NULL;
	_inventory[1] = NULL;
	_inventory[2] = NULL;
	_inventory[3] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	*this = src;
}

MateriaSource::~MateriaSource()
{
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
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

		_n_index = rhs._n_index;
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria* m)
{
	if (_n_index < 3) {
		_inventory[_n_index] = m;
		_n_index++;
	}
}

AMateria*	MateriaSource::createMateria(const std::string& type)
{
	if (type == "ice") {
		return new Ice();
	} else if (type == "cure") {
		return new Cure();
	} else {
		return NULL;
	}
}
