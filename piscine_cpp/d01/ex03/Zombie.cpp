/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 12:00:22 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/16 15:10:53 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type) : _name(name), _type(type)
{
	std::cout << _name << " created and is type of " << _type << std::endl;
}

Zombie::Zombie() : _name(""), _type("")
{
	std::cout << "Anonymmous zombie created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << _name << " killed." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << "<" << _name << " ("
		<< _type << ")> Braiiiiiiinnnssss..." << std::endl;
}

std::string	Zombie::name(void) const
{
	return _name;
}

std::string	Zombie::type(void) const
{
	return _type;
}

void		Zombie::set_name(std::string name)
{
	_name = name;
}

void		Zombie::set_type(std::string type)
{
	_type = type;
}
