/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/18 18:35:26 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/19 23:05:38 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include "ScavTrap.hpp"
#include "SuperTrap.hpp"

int	main()
{
	std::cout << "############----EX00----###############" << std::endl;
	{
		{
			FragTrap f1;

			while (f1.hit_points() > 0)
			{
				f1.beRepaired(5);
				f1.takeDamage(25);
				f1.meleeAttack("Warior");
				f1.rangedAttack("Robot");
				f1.vaulthunter_dot_exe("Man");
				std::cout << std::endl;
				std::cout << "Hit Points: " << f1.hit_points() << std::endl;
			}
		}

		std::cout << "_________________" << std::endl;

		{
			FragTrap f2("NOOD");
			while (f2.hit_points() > 0)
			{
				f2.beRepaired(5);
				f2.takeDamage(35);
				f2.vaulthunter_dot_exe("Man");

				std::cout << std::endl;
				std::cout << "Hit Points: " << f2.hit_points() << std::endl;
			}
		}
	}
	std::cout << "############----EX01----###############" << std::endl;
	{
		std::cout << "_______FR4G_______" << std::endl;
		{
			FragTrap f1;

			while (f1.hit_points() > 0)
			{
				f1.beRepaired(5);
				f1.takeDamage(25);
				f1.meleeAttack("Warior");
				f1.rangedAttack("Robot");
				f1.vaulthunter_dot_exe("Man");
				std::cout << std::endl;
				std::cout << "Hit Points: " << f1.hit_points() << std::endl;
			}
		}

		std::cout << "_______SC4V_______" << std::endl;
		{
			ScavTrap s1("BOT");
			while (s1.hit_points() > 0)
			{
				s1.beRepaired(5);
				s1.takeDamage(35);
				s1.challengeNewcomer("Woman");

				std::cout << std::endl;
				std::cout << "Hit Points: " << s1.hit_points() << std::endl;
			}
		}
	}
	std::cout << "############----EX02----###############" << std::endl;
	{
		std::cout << "_______FR4G_______" << std::endl;
		FragTrap *f1 = new FragTrap("Yana");

		while (f1->hit_points() > 0)
		{
			f1->beRepaired(5);
			f1->takeDamage(25);
			f1->meleeAttack("Warior");
			f1->rangedAttack("Robot");
			f1->vaulthunter_dot_exe("Man");
			std::cout << std::endl;
			std::cout << "Hit Points: " << f1->hit_points() << std::endl;
		}
		delete f1;

		std::cout << "_______SC4V_______" << std::endl;

		ScavTrap *s1 = new ScavTrap("Paul");
		while (s1->hit_points() > 0)
		{
			s1->beRepaired(5);
			s1->takeDamage(35);
			s1->challengeNewcomer("Woman");

			std::cout << std::endl;
			std::cout << "Hit Points: " << s1->hit_points() << std::endl;
		}
		delete s1;
	}
	std::cout << std::endl << "############----EX03----###############" << std::endl << std::endl;
	{
		std::cout << "_______FR4G_______" << std::endl;
		FragTrap *f1 = new FragTrap("Robot");

		std::cout << "_______SC4V_______" << std::endl;
		ScavTrap *s1 = new ScavTrap("Warior");

		std::cout << "_______NINJA_______" << std::endl;
		NinjaTrap *n1 = new NinjaTrap("Boss");

		n1->takeDamage(20);
		n1->beRepaired(10);

		n1->ninjaShoebox(*n1);
		n1->ninjaShoebox(*f1);
		n1->ninjaShoebox(*s1);

		std::cout << "_______NINJA_______" << std::endl;
		delete n1;
		std::cout << "_______SC4V_______" << std::endl;
		delete s1;
		std::cout << "_______FR4G_______" << std::endl;
		delete f1;
	}
	
	std::cout << std::endl << "############----EX04----###############" << std::endl << std::endl;
	{
		SuperTrap sc("sysy");
		FragTrap lol("lol");

		sc.rangedAttack("yany");
		sc.meleeAttack("yany");
		sc.vaulthunter_dot_exe("popol");
		sc.ninjaShoebox(lol);
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}
	return 0;
}
