/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 15:30:27 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/16 16:04:41 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>

#include "Zombie.hpp"
#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n) : _pool_n(n),
	_zombies_pool(new Zombie[n])
{
	srand(time(NULL));
	_initHorde(0);
}

ZombieHorde::~ZombieHorde()
{
	delete[] _zombies_pool;
}

void	ZombieHorde::announce() const
{
	return _announceForEach(0);
}

void	ZombieHorde::_announceForEach(int i) const
{
	if (i == _pool_n)
		return ;
	_zombies_pool[i].announce();
	return _announceForEach(i + 1);
}

std::string	ZombieHorde::_generateRandomName(int length)
{
	std::string	ret;

	return _generateRandomNameRec(ret, length);
}

std::string	ZombieHorde::_generateRandomNameRec(std::string ret, int length)
{
	static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

	if (!length)
		return ret;
	ret += charset[rand() % sizeof(charset)];
	return _generateRandomNameRec(ret, length - 1);
}

void	ZombieHorde::_initHorde(int i)
{
	if (i == _pool_n)
		return ;
	_zombies_pool[i].set_type(!(i & 1) ? "human" : "dog");
	_zombies_pool[i].set_name(_generateRandomName((rand() % (22 - 5)) + 5));
	return _initHorde(i + 1);
}
