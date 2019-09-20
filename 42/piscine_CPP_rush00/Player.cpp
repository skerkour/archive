/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 00:43:15 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/21 17:18:05 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "Player.hpp"
#include "Starship.hpp"

int Player::color = COLOR_GREEN;

Player::Player() : Starship(
//	"   __    
//	\\ \\_  ###[==_)>   /_/ ",
//"   __       \\ \\_   ###[==_)>/_/   ",
"  \\ \\ "
"~~[=_)"
"  /_/ ",
 6, 3, 1, 1, 0, 0, 3, Player::color)
{
}

Player::Player(const Player& src)
{
	*this = src;
}

Player::~Player()
{
}

Player& Player::operator=(const Player& rhs)
{
	if (this != &rhs) {
		_x = rhs._x;
		_y = rhs._y;
		_height = rhs._height;
		_width = rhs._width;
		_hp = rhs._hp;
		_vx = rhs._vx;
		_vy = rhs._vy;
		_color = rhs._color;
	}
	return *this;
}

Blast* Player::attack(void)
{
	Blast *newBlast = new Blast(2, // Damage
								_x + _width + 1, // position x
								_y + _height / 2, // position y
								1, // height
								1, // width
								1, // hp
								1, // velocity x
								0, // velocit y
								")" // pattern
								);
	return newBlast;
}

// __Interface__

void	Player::takeDamage(int amount)
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
