/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 11:27:01 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/16 11:54:37 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Pony.hpp"

Pony::Pony(std::string name, int size)
{
	_name = name;
	_size = size;

	std::cout << "Pony \"" << _name << "\" born." << std::endl;
}

Pony::~Pony()
{
	std::cout << "Pony \"" << _name << "\" killed." << std::endl;
}

std::string	Pony::name() const
{
	return _name;
}

void	Pony::sayHello(void) const
{
	std::cout << "Pony \"" << _name << "\" say Hello !" << std::endl;
}

void	Pony::set_name(std::string name)
{
	_name = name;
}

void	Pony::set_size(int size)
{
	_size = size;
}

int	Pony::size() const
{
	return _size;
}
