/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 10:25:10 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/19 23:23:07 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

#include <string>

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(const FragTrap& src);
	FragTrap(std::string name);
	~FragTrap();
	
	bool	vaulthunter_dot_exe(const std::string& target);

	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);

private:
	void	_init(std::string name);

private:
	typedef struct	s_attack {
		std::string		name;
		unsigned int	damages;
	}				t_attack;

	static t_attack	_random_vh_attacks[6];
};

#endif // FRAGTRAP_HPP
