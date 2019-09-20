/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:12:24 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/16 18:50:55 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <string>

#include "Brain.hpp"

Brain::Brain()
{}

Brain::Brain(double weight) : _weight(weight)
{}

Brain::~Brain()
{}

std::string	Brain::identify() const
{
	std::stringstream	stream;

	stream << static_cast<const void*>(this);
	return stream.str();
}

double	Brain::weight() const
{
	return _weight;
}

void	Brain::set_weight(double weight)
{
	_weight = weight;
}
