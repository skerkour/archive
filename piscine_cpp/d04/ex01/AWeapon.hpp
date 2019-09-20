/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 14:39:50 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/19 15:50:10 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include <string>

class AWeapon
{
public:
	AWeapon(const std::string& name, int apcost, int damage);
	AWeapon(const AWeapon& src);
	virtual ~AWeapon();

	AWeapon&	operator=(const AWeapon& rhs);

	virtual void	attack() const = 0;

	int					getAPCost() const;
	int					getDamage() const;
	const std::string	getName() const;

protected:
	AWeapon();

	int			_damage,
				_ap_cost;
	std::string	_name;
};

#endif // AWEAPON_HPP
