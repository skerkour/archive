/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 10:33:11 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/19 23:35:44 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include <string>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : virtual public ClapTrap
{
public:
	NinjaTrap();
	NinjaTrap(const NinjaTrap& src);
	NinjaTrap(std::string name);
	~NinjaTrap();
	
	NinjaTrap& operator=(const NinjaTrap& rhs);

	void	ninjaShoebox(const FragTrap& frag) const;
	void	ninjaShoebox(const ScavTrap& scav) const;
	void	ninjaShoebox(const NinjaTrap& ninja) const;
	void	ninjaShoebox(const ClapTrap& ninja) const;

	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);

private:
	void	_init(std::string name);
};

#endif // NINJATRAP_HPP
