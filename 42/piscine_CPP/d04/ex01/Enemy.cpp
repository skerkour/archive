/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 14:40:05 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/19 17:09:38 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy()
{
}

Enemy::Enemy(int hp, const std::string& type) : _hp(hp), _type(type)
{
}

Enemy::Enemy(const Enemy& src)
{
	*this = src;
}

Enemy::~Enemy()
{
}

Enemy&	Enemy::operator=(const Enemy& rhs)
{
	if (this != &rhs) {
		_hp = rhs._hp;
		_type = rhs._type;
	}
	return *this;
}

const std::string	Enemy::getType() const
{
	return _type;
}

int	Enemy::getHP() const
{
	return _hp;
}

void	Enemy::takeDamage(int n)
{
	if (n < 0) {
		return ;
	} else if (_hp - n <= 0) {
		_hp = 0;
	} else {
		_hp -= n;
	}
}
