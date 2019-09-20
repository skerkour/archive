/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 10:25:17 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/19 23:23:31 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

#include <string>

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(const ScavTrap& src);
	ScavTrap(std::string name);
	~ScavTrap();
	
	bool	challengeNewcomer(const std::string& target);
	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);

private:
	void	_init(std::string name);

private:
	static std::string	_sc_challenges[6];
};

#endif // SCAVTRAP_HPP
