/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 11:22:17 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/20 23:39:38 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(const std::string& type) : xp_(0), _type(type)
{
}

AMateria::AMateria(const AMateria& src)
{
	*this = src;
}

AMateria::~AMateria()
{
}

AMateria& AMateria::operator=(const AMateria& rhs)
{
	if (this != &rhs) {
		xp_ = rhs.xp_;
		_type = rhs._type;
	}
	return *this;
}

const std::string&	AMateria::getType() const //Returns the materia type
{
	return _type;
}

unsigned int	AMateria::getXP() const //Returns the Materia's XP
{
	return xp_;
}
