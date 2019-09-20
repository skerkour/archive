/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 11:22:46 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/20 22:59:42 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <string>

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class Character : public ICharacter
{
public:
	Character();
	Character(const std::string& name);
	Character(const Character& src);
	~Character();

	Character& operator=(const Character& rhs);

	virtual const std::string&	getName() const;
	virtual void				equip(AMateria* m);
	virtual void				unequip(int idx);
	virtual void				use(int idx, ICharacter& target);

private:
	std::string	_name;
	AMateria*	_inventory[4];
	int			_n_index;
};

#endif // CHARACTER_HPP
