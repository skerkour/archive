/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:12:42 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/17 19:45:11 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Human.hpp"

Human::Human() : _brain()
{}

Human::~Human()
{}

const Brain&	Human::getBrain()
{
	return _brain;
}

std::string	Human::identify() const
{
	return _brain.identify();
}
