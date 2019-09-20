/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 09:32:00 by ybarbier          #+#    #+#             */
/*   Updated: 2015/06/21 09:32:01 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOSS_HPP
# define BOSS_HPP

#include "Starship.hpp"

class Boss : public Starship
{
public:
	Boss();
	Boss(int x, int y);
	Boss(const Boss& src);
	~Boss();

	Boss& operator=(const Boss& rhs);

	static int color;
	//__Interface__
	Blast *attack();
	Blast *attack2();

	void	takeDamage(int amount);

private:

};

#endif // BOSS_HPP
