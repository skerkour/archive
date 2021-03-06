/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 09:23:54 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/20 20:46:04 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ISpaceMarine.hpp"
#include "TacticalMarine.hpp"
#include "ISquad.hpp"
#include "Squad.hpp"
#include "AssaultTerminator.hpp"

int main()
{
	{
		std::cout << "____Constructor_____" << std::endl;
		ISpaceMarine* bob = new TacticalMarine;
		ISpaceMarine* jim = new AssaultTerminator;
		ISquad* vlc = new Squad;

		std::cout << "____Index and count_____" << std::endl;
		std::cout << vlc->push(bob) << std::endl;
		std::cout << vlc->getCount() << std::endl;

		std::cout << "____Same Object_____" << std::endl;
		std::cout << vlc->push(jim) << std::endl;
		std::cout << vlc->getCount() << std::endl;
		std::cout << vlc->push(jim) << std::endl;
		std::cout << vlc->getCount() << std::endl;

		std::cout << "____New Object Index_____" << std::endl;
		std::cout << vlc->push(new AssaultTerminator) << std::endl;
		std::cout << vlc->push(new TacticalMarine) << std::endl;

		std::cout << vlc->getCount() << std::endl;

		std::cout << "____Attack_____" << std::endl;
		vlc->getUnit(0)->battleCry();
		vlc->getUnit(1)->battleCry();

		vlc->getUnit(0)->rangedAttack();
		vlc->getUnit(1)->rangedAttack();

		vlc->getUnit(0)->meleeAttack();
		vlc->getUnit(1)->meleeAttack();

		std::cout << "____Not Exist_____" << std::endl;
		std::cout << vlc->getUnit(8) << std::endl;

		std::cout << "____Delete_____" << std::endl;
		delete vlc;
		// delete bob;
		// delete jim;
	}
	std::cout << "____Test Subject_____" << std::endl;
	{
		ISpaceMarine* bob = new TacticalMarine;
		ISpaceMarine* jim = new AssaultTerminator;
		ISquad* vlc = new Squad;
		vlc->push(bob);
		vlc->push(jim);
		for (int i = 0; i < vlc->getCount(); ++i)
		{
			ISpaceMarine* cur = vlc->getUnit(i);
			cur->battleCry();
			cur->rangedAttack();
			cur->meleeAttack();
		}
		delete vlc;
	}
	return 0;
}
