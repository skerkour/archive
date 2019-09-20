/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 12:00:33 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/16 15:23:08 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

void	createZombieRandomRec(ZombieEvent& factory, int n)
{
	if (!n)
		return ;
	Zombie tmp = factory.randomChump();
	return createZombieRandomRec(factory, n - 1);
}

void	randomArmy(ZombieEvent& factory)
{
	return createZombieRandomRec(factory, 12);
}

int	main()
{
	ZombieEvent	factory;
	Zombie*		lol;
	Zombie*		yo;

	factory.setZombieType("humain");
	lol = factory.newZombie("Popaulette");
	randomArmy(factory);
	factory.setZombieType("chien");
	yo = factory.newZombie("Popaul");
	lol->announce();
	delete lol;
	delete yo;
	return 0;
}
