/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroid.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 09:47:29 by ybarbier          #+#    #+#             */
/*   Updated: 2015/06/21 15:53:26 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTEROID_HPP
# define ASTEROID_HPP

#include "AEntity.hpp"

class Asteroid : public AEntity
{
public:
	Asteroid();
	Asteroid(int x, int y);
	Asteroid(const Asteroid& src);
	~Asteroid();

	Asteroid& operator=(const Asteroid& rhs);

	static int color;
	//__Interface__
	void	takeDamage(int amout);
private:

};

#endif // ASTEROID_HPP
