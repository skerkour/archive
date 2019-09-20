/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 13:26:44 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/21 14:50:19 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AEntity.hpp"

AEntity::AEntity()
{
}

AEntity::AEntity(std::string pattern, int w, int h, int x, int y, int vx, int vy, int hp, int color) :
	_x(x), _y(y), _height(h), _width(w), _hp(hp), _vx(vx), _vy(vy), _color(color), _pattern(pattern)
{
}

AEntity::AEntity(const AEntity& src)
{
	*this = src;
}

AEntity::~AEntity()
{
}

AEntity& AEntity::operator=(const AEntity& rhs)
{
	if (this != &rhs) {
		_x = rhs._x;
		_y = rhs._y;
		_height = rhs._height;
		_width = rhs._width;
		_hp = rhs._hp;
		_vx = rhs._vx;
		_vy = rhs._vy;
	}
	return *this;
}

void	AEntity::moveX(int n)
{
	_x += n;
}

void	AEntity::moveY(int n)
{
	_y += n;
}

int	AEntity::height() const
{
	return _height;
}

int	AEntity::hp() const
{
	return _hp;
}

std::string	AEntity::pattern() const
{
	return _pattern;
}

void	AEntity::set_x(int x)
{
	_x = x;
}

void	AEntity::set_y(int y)
{
	_y = y;
}

void	AEntity::set_vx(int vx)
{
	_vx = vx;
}

void	AEntity::set_vy(int vy)
{
	_vy = vy;
}


int	AEntity::vx() const
{
	return _vx;
}

int	AEntity::vy() const
{
	return _vy;
}

int	AEntity::width() const
{
	return _width;
}

int	AEntity::x() const
{
	return _x;
}

int	AEntity::y() const
{
	return _y;
}
