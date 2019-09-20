/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 09:31:53 by ybarbier          #+#    #+#             */
/*   Updated: 2015/06/21 09:31:54 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

#include "Starship.hpp"

class Enemy : public Starship
{
public:
	Enemy();
	Enemy(int x, int y);
	Enemy(const Enemy& src);
	~Enemy();

	Enemy& operator=(const Enemy& rhs);

	static int color;
	// __Interface__
	Blast*	attack();
	void	takeDamage(int);

private:

};

#endif // ENEMY_HPP
