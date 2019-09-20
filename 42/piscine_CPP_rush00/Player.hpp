/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 00:43:18 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/21 00:54:45 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

#include "Starship.hpp"
#include "Blast.hpp"

class Player : public Starship
{
public:
	Player();
	Player(const Player& src);
	~Player();

	Player& operator=(const Player& rhs);

	static int color;
	// __Interface__
	Blast*	attack();
	void	takeDamage(int);

private:

};

#endif // PLAYER_HPP
