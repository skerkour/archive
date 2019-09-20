/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 11:43:12 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/21 13:40:03 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <ncurses.h>

#include "Game.hpp"

void	replay(Game& game)
{
	std::string	rep;

	if (game.launch()) {
		std::cout << "Your score : " << game.score() << " (Total : "
			<< game.total_score() << ')' << std::endl
			<< "Do you want to replay ? (y/ *) ";
			std::getline(std::cin, rep);
		if (rep == "y" || rep == "Y")
			return replay(game);
	}
	return ;
}

int	main() {
	Game		game;

	replay(game);
	return 0;
}
