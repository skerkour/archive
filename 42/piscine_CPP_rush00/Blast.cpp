/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Blast.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 09:31:19 by ybarbier          #+#    #+#             */
/*   Updated: 2015/06/21 09:31:25 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Blast.hpp"

int Blast::color = COLOR_RED;

Blast::Blast(void)
{
}

Blast::Blast(int damage, int x, int y, int height, int width, int hp, int vx, int vy, std::string pattern)
{
	_damageCost = damage;
	_x = x;
	_y = y;
	_height = height;
	_width = width;
	_hp = hp;
	_vx = vx;
	_vy = vy;
	_pattern = pattern;
}

Blast::Blast(const Blast& src)
{
	*this = src;
}

Blast::~Blast()
{
}

Blast& Blast::operator=(const Blast& rhs)
{
	if (this != &rhs)
	{
		_damageCost = rhs._damageCost;
		_x = rhs._x;
		_y = rhs._y;
		_height = rhs._height;
		_width = rhs._width;
		_hp = rhs._hp;
		_vx = rhs._vx;
		_vy = rhs._vy;
		_pattern = rhs._pattern;
	}
	return *this;
}

int		Blast::damage_cost() const
{
	return _damageCost;
}

// __Interface__

void	Blast::takeDamage(int amount)
{
	if (_hp > 0)
	{
		if ((_hp - amount) >= 0)
			_hp -= amount;
		else
		{
			_hp = 0;
			// die();
		}
	}
}
