/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 14:39:58 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/19 17:02:30 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <string>

#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
public:
	Character(const std::string& name);
	Character(const Character& src);
	~Character();

	Character&	operator=(const Character& rhs);

	void				recoverAP();
	void				equip(AWeapon* weapon);
	void				attack(Enemy* enemy);
	const std::string	getName() const;
	int					getAp() const;
	AWeapon*			getWeapon() const;

private:
	Character();

	int			_ap;
	std::string	_name;
	AWeapon*	_weapon;
};

std::ostream&	operator<<(std::ostream& o, const Character& rhs);

#endif // CHARACTER_HPP
