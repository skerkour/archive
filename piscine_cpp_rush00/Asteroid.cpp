/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroid.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 09:47:35 by ybarbier          #+#    #+#             */
/*   Updated: 2015/06/21 15:57:02 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Asteroid.hpp"

int Asteroid::color = COLOR_MAGENTA;

Asteroid::Asteroid() : AEntity("#", 1, 1, 1, 1, -1, 0, 100, Asteroid::color)
{
}

Asteroid::Asteroid(int x, int y) : AEntity("#", 1, 1, x, y, -1, 0, 100, Asteroid::color)
{

}

Asteroid::Asteroid(const Asteroid& src)
{
	*this = src;
}

Asteroid::~Asteroid()
{
}

Asteroid& Asteroid::operator=(const Asteroid& rhs)
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

//__Interface__

void	Asteroid::takeDamage(int amount)
{
	amount = 0;
/*	if (_hp > 0)
	{
		if ((_hp - amount) >= 0)
			_hp -= amount;
		else
		{
			_hp = 0;
			// die();
		}
	}*/
}
