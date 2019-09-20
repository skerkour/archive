/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 09:32:04 by ybarbier          #+#    #+#             */
/*   Updated: 2015/06/21 09:32:05 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Boss.hpp"

int Boss::color = COLOR_YELLOW;

Boss::Boss() : Starship(
	"+----------------+"
	"|..$$$$$$$$$$$...|"
	"|..$...$.$...$...|"
	"|...$$$..$$$.....|"
	"|................|"
	"|..$$$$$$$$$$$$..|"
	"|..$$........$$..|"
	"|..$$$$$$$$$$$$..|"
	"|................|"
	"|..$$....$$$$$$..|"
	"|..$$...$$...$$..|"
	"|..$$$$$$$...$$..|"
	"|................|"
	"|..$$....$$$$$$..|"
	"|..$$...$$...$$..|"
	"|..$$$$$$$...$$..|"
	"+----------------+"
,  18, 17, 100, 4, 0, 1, 50, Boss::color)
{
}

Boss::Boss(int x, int y) : Starship("O", 1, 1, x, y, -1, -1, 50, Boss::color)
{

}

Boss::Boss(const Boss& src)
{
	*this = src;
}

Boss::~Boss()
{
}

Boss& Boss::operator=(const Boss& rhs)
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

Blast* Boss::attack()
{
	Blast *newBlast = new Blast(2, // Damage
								_x, // position x
								_y + 1, // position y
								1, // height
								4, // width
								1, // hp
								-2, // velocity x
								0, // velocit y
								"$" // pattern
								);
	return newBlast;
}

Blast* Boss::attack2()
{
	Blast *newBlast = new Blast(2, // Damage
								_x, // position x
								_y + _height - 1, // position y
								1, // height
								4, // width
								1, // hp
								-2, // velocity x
								0, // velocit y
								"$" // pattern
								);
	return newBlast;
}

// __Interface__

void	Boss::takeDamage(int amount)
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
