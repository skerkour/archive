/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 18:59:52 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/16 19:31:01 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>

#include "Weapon.hpp"

class HumanB
{
public:
	HumanB(std::string name);
	HumanB(std::string name, Weapon& weapon);
	~HumanB();

	void	attack();
	void	setWeapon(Weapon& weapon);

private:
	std::string	_name;
	Weapon*		_weapon;
};

#endif // HUMANB_HPP
