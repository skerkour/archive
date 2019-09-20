/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 11:00:42 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/19 22:52:24 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{
public:
	SuperTrap();
	SuperTrap(std::string iname);
	SuperTrap(const SuperTrap& src);
	~SuperTrap();

	SuperTrap& operator=(const SuperTrap& rhs);

	void	_init(std::string name);
	void 	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);

private:

};

#endif // SUPERTRAP_HPP
