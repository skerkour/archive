/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 12:00:31 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/16 14:57:26 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include <string>

#include "Zombie.hpp"

class ZombieEvent
{
public:
	ZombieEvent();
	ZombieEvent(std::string type);
	~ZombieEvent();
	Zombie*	newZombie(std::string name);
	Zombie	randomChump();
	void	setZombieType(std::string type);

private:
	std::string	_generateRandomName(int length);
	std::string	_generateRandomNameRec(std::string ret, int length);

	std::string	_zombie_type;
};

#endif // ZOMBIEEVENT_HPP
