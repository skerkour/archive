/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 13:27:18 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/21 18:25:24 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

#include <string>
#include <ncurses.h>

# include "AEntity.hpp"
# include "Map.hpp"

# define KEY_ESC 27

# define WIN_WIDTH 136

# define MAP_WIN_H 32
# define SCORE_WIN_H 3

class Game
{
private:
	static std::string	_error;
	
	static void			_displayError();
	static void			_resizeHandler(int sign);

public:
	static int			MIN_X,
						MIN_Y,
						FPS,
						TICKS;

public:
	Game();
	Game(const Game& src);
	~Game();

	Game&	operator=(const Game& rhs);

	unsigned int	score() const;
	unsigned int	total_score() const;

	bool		launch();

private:
	long long			_getTimeMs();
	bool				_init();
	bool				_play();
	void				_uninit();
	void				_refreshScoreWindow();

	unsigned int		_total_score,
						_default_speed,
						_level;
	long long			_time;
	Map*				_map;
	WINDOW*				_score_window;
};

#endif // GAME_HPP
