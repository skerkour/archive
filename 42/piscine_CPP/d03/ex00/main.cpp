/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/18 09:53:51 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/18 17:48:39 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap	robot("Sylvain");
	FragTrap	clone = robot;

	robot.rangedAttack("Nabile");
	robot.meleeAttack("Nabile");
	robot.vaulthunter_dot_exe("Nabile");
	robot.vaulthunter_dot_exe("zine");
	robot.vaulthunter_dot_exe("zine");
	robot.vaulthunter_dot_exe("zine");
	robot.vaulthunter_dot_exe("zine");

	robot.takeDamage(101);
	robot.takeDamage(4);
	robot.takeDamage(101);

	return 0;
}
