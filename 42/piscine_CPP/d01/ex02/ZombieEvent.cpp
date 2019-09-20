/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 12:00:27 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/16 15:21:53 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

#include <string>
#include <cstdlib>
#include <ctime>

ZombieEvent::ZombieEvent()
{
	srand(time(NULL));
}

ZombieEvent::ZombieEvent(std::string type) : _zombie_type(type)
{
	srand(time(NULL));
}

ZombieEvent::~ZombieEvent()
{}

std::string	ZombieEvent::_generateRandomName(int length)
{
	std::string	ret;

	return _generateRandomNameRec(ret, length);
}

std::string	ZombieEvent::_generateRandomNameRec(std::string ret, int length)
{
	static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

	if (!length)
		return ret;
	ret += charset[rand() % sizeof(charset)];
	return _generateRandomNameRec(ret, length - 1);
}

Zombie*	ZombieEvent::newZombie(std::string name)
{
	return new Zombie(name, _zombie_type);
}

Zombie	ZombieEvent::randomChump()
{
	Zombie ret(_generateRandomName((rand() % (22 - 5)) + 5),
		_zombie_type);

	ret.announce();
	return ret;
}

void	ZombieEvent::setZombieType(std::string type)
{
	_zombie_type = type;
}
