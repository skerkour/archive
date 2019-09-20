/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 11:30:06 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/19 14:05:42 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Sorcerer.hpp"

Sorcerer::Sorcerer()
{
}

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name),
	 _title(title)
{
	std::cout << _name << ", " << _title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(const Sorcerer& src)
{
	*this = src;
}

Sorcerer::~Sorcerer()
{
	std::cout << _name << ", " << _title
		<< ", is dead. Consequences will never be the same !" << std::endl;
}

Sorcerer& Sorcerer::operator=(const Sorcerer& rhs)
{
	if (this != &rhs) {
		_name = rhs.name();
		_title = rhs.title();
	}
	return *this;
}

void	Sorcerer::polymorph(const Victim& vic) const
{
	vic.getPolymorphed();
}

std::string	Sorcerer::name() const
{
	return _name;
}

void	Sorcerer::set_name(std::string name)
{
	_name = name;
}

void		Sorcerer::set_title(std::string title)
{
	_title = title;
}

std::string	Sorcerer::title() const
{
	return _title;
}

std::ostream&	operator<<(std::ostream& o, const Sorcerer& rhs)
{
	o << "I am " << rhs.name() << ", " <<
		rhs.title() << ", and I like ponies !" << std::endl;
	return o;
}
