/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Blast.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 09:31:30 by ybarbier          #+#    #+#             */
/*   Updated: 2015/06/21 09:31:31 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLAST_HPP
# define BLAST_HPP

#include "AEntity.hpp"

class Blast : public AEntity
{
public:
	Blast();
	Blast(const Blast& src);
	Blast(int damage, int x, int y, int height, int width, int hp, int vx, int vy, std::string pattern);
	~Blast();

	Blast& operator=(const Blast& rhs);

	int		damage_cost() const;

	static int color;

	// __Interface__
	void	takeDamage(int);

private:
	int _damageCost;
};

#endif // BLAST_HPP
