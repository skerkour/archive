/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 11:30:26 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/19 16:00:02 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Victim.hpp"

Victim::Victim(std::string name) : _name(name)
{
	std::cout << "Some random victim called " << _name
		<< " just popped !" << std::endl;
}

Victim::Victim()
{
}

Victim::Victim(const Victim& src)
{
	*this = src;
}

Victim::~Victim()
{
	std::cout << "Victim " << _name << " just died for no apparent reason !"
		<< std::endl;
}

Victim& Victim::operator=(const Victim& rhs)
{
	if (this != &rhs) {
		_name = rhs._name;
	}
	return *this;
}

void	Victim::getPolymorphed() const
{
	std::cout << _name << " has been turned into a cute little sheep !"
		<< std::endl;
}

std::string	Victim::name() const
{
	return _name;
}

void	Victim::set_name(std::string name)
{
	_name = name;
}

std::ostream&	operator<<(std::ostream& o, const Victim& rhs)
{
	o << "I'm " << rhs.name() << " and i like otters !" << std::endl;
	return o;
}
