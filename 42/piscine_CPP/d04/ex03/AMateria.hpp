/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 11:22:34 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/20 23:20:46 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>

#include "ICharacter.hpp"

class AMateria
{
public:
	AMateria();
	AMateria(const std::string& type);
	AMateria(const AMateria& src);
	virtual ~AMateria();

	AMateria& operator=(const AMateria& rhs);

	const std::string&	getType() const; //Returns the materia type
	unsigned int		getXP() const; //Returns the Materia's XP
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target) = 0;

protected:
	unsigned int	xp_;
	std::string		_type;
};

#endif // AMATERIA_HPP
