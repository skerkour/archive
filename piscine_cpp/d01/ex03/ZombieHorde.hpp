/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 15:31:15 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/16 16:04:52 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include "Zombie.hpp"

class ZombieHorde
{
public:
	ZombieHorde(int n);
	~ZombieHorde();
	void	announce() const;

private:
	void		_announceForEach(int i) const;
	std::string	_generateRandomName(int length);
	std::string	_generateRandomNameRec(std::string ret, int length);
	void		_initHorde(int i);

	int		_pool_n;
	Zombie*	_zombies_pool;

};

#endif // ZOMBIEHORDE_HPP
