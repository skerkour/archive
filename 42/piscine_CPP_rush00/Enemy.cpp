/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 09:31:45 by ybarbier          #+#    #+#             */
/*   Updated: 2015/06/21 17:41:56 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Enemy.hpp"

int Enemy::color = COLOR_CYAN;

Enemy::Enemy() : Starship("o", 1, 1, 1, 1, -1, 0, 1, Enemy::color)
{

}

Enemy::Enemy(int x, int y) : Starship("o", 1, 1, x, y, -1, 0, 1, Enemy::color)
{

}

Enemy::Enemy(const Enemy& src)
{
	*this = src;
}

Enemy::~Enemy()
{
}

Enemy& Enemy::operator=(const Enemy& rhs)
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

Blast* Enemy::attack()
{
	Blast *newBlast = new Blast(2, // Damage
								_x, // position x
								_y, // position y
								1, // height
								4, // width
								1, // hp
								-2, // velocity x
								0, // velocit y
								"-" // pattern
								);
	return newBlast;
}

// __Interface__

void	Enemy::takeDamage(int amount)
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
