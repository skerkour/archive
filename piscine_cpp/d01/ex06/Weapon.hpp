/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 17:41:06 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/16 18:44:54 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
public:
	Weapon();
	Weapon(std::string type);
	~Weapon();

	const std::string&	getType() const;
	void				setType(std::string type);

private:
	std::string	_type;
};

#endif // WEAPON_HPP
