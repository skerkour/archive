/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Starship.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 00:40:02 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/21 14:52:24 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "AEntity.hpp"
#include "Starship.hpp"

Starship::Starship()
{
}

Starship::Starship(std::string pattern, int w, int h, int x, int y, int vx, int vy, int hp, int color) :
	AEntity(pattern, w, h, x, y, vx, vy, hp, color)
{
}

Starship::Starship(const Starship& src)
{
	*this = src;
}

Starship::~Starship()
{
}

Starship& Starship::operator=(const Starship& rhs)
{
	if (this != &rhs)
	{
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

void	Starship::takeDamage(int amount)
{
	if (_hp > 0)
	{
		if ((_hp - amount) <= 0)
		{
			_hp = 0;
			// die();
		}
		else
			_hp -= amount;
	}
}
