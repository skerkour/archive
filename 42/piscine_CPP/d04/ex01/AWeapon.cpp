/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 14:39:53 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/19 17:02:08 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon()
{
}

AWeapon::AWeapon(const std::string& name, int apcost, int damage) :
	_damage(damage), _ap_cost(apcost), _name(name)
{
}

AWeapon::AWeapon(const AWeapon& src)
{
	*this = src;
}

AWeapon::~AWeapon()
{
}

AWeapon&	AWeapon::operator=(const AWeapon& rhs)
{
	if (this != &rhs) {
		_damage = rhs._damage;
		_ap_cost = rhs._ap_cost;
		_name = rhs._name;
	}
	return *this;
}

int	AWeapon::getAPCost() const
{
	return _ap_cost;
}

int	AWeapon::getDamage() const
{
	return _damage;
}

const std::string	AWeapon::getName() const
{
	return _name;
}
