/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 13:26:48 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/21 19:14:37 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <sys/time.h>
#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#include "Game.hpp"

WINDOW* g_win;
std::string	Game::_error;
int			Game::MIN_X = WIN_WIDTH + 2;
int			Game::MIN_Y = MAP_WIN_H + 2;
int			Game::FPS = 5;
int			Game::TICKS = 1000 / Game::FPS;

void	Game::_displayError()
{
	std::cerr << "Error : " << _error << std::endl << "Aborting.." << std::endl;
}

void	Game::_resizeHandler(int sign)
{
	int	x,
		y;
	(void)sign;

	getmaxyx(g_win, y, x);
	if (x < MIN_X || y < MIN_Y) {
		 endwin();
		_error = "You can't resize the window in game";
		_displayError();
		exit(0);
	}
}

Game::Game() : _total_score(0),
	_default_speed(0), _level(0), _map(NULL), _score_window(NULL)
{
}

Game::Game(const Game& src)
{
	*this = src;
}

Game::~Game()
{
}

Game& Game::operator=(const Game& rhs)
{
	if (this != &rhs) {
		_total_score = rhs._total_score;
	}
	return *this;
}

unsigned int	Game::score() const
{
	if (_map) {
		return _map->score();
	} else {
		return 0;
	}
}

unsigned int	Game::total_score() const
{
	return _total_score;
}

bool	Game::launch()
{
	bool	ret;

	if (_init()) {
		ret = _play();
		_uninit();
		return ret;
	} else {
		_uninit();
		_displayError();
		return false;
	}
}

long long	Game::_getTimeMs()
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (long long)(tv.tv_sec) * 1000 +
		(long long)(tv.tv_usec) / 1000;
}

bool	Game::_init()
{
	int				x = 0,
					y = 0;

	initscr();
	getmaxyx(stdscr, y, x);
	if (x < MIN_X || y < MIN_Y) {
		_error = "Window too small...";
		return false;
	}
	// ncurses initialisations
	noecho();
	start_color();
	keypad(stdscr, TRUE);
	signal(SIGWINCH, _resizeHandler);
	nodelay(stdscr, TRUE);
	cbreak();
	timeout(0);
	curs_set(false);
	return true;
}

bool	Game::_play()
{
	int		k = 0;
	long long		sleep_time = 0;
	long long	next_tick = _getTimeMs();
	int		delta_t;
	WINDOW	*map_win = newwin(MAP_WIN_H, WIN_WIDTH, 0, 0);
	g_win = map_win;
	_score_window = newwin(SCORE_WIN_H, WIN_WIDTH, MAP_WIN_H, 0);

	_map = new Map(map_win);
	(void)_default_speed, (void)_level, (void)k, (void)_score_window;
	
	delta_t = time(NULL);
	while (42) {
		k = getch();
		if (k == KEY_ESC) {
			delete _map;
			delwin(_score_window), delwin(map_win);
			return false;
		} else if (k == KEY_RESIZE) {
			_resizeHandler(0);
		}

		_time = time(NULL) - delta_t;
	//	_time = _getTimeMs();

		next_tick = _getTimeMs();
		_map->lap(k), _refreshScoreWindow();
		next_tick += TICKS;
		sleep_time = next_tick - _getTimeMs();
		_time = sleep_time;

		if (sleep_time >= 0) {
			usleep(sleep_time * 140);
		}
		if (!_map->player_hp()) {
			_total_score += _map->score();
			delete _map;
			delwin(_score_window), delwin(map_win);
			return true;
		}
		//usleep(30000);
	}
}

void	Game::_uninit()
{
    endwin();
}

void	Game::_refreshScoreWindow()
{
	int px = 2 + 20;

	wclear(_score_window);
	mvwprintw(_score_window, 1, 2, "Score : %9u", _map->score());
	for (int i = 0, n = _map->player_hp(); i < n; i++, px += 3) {
		mvwprintw(_score_window, 1, px, "<3 ");
	}
	mvwprintw(_score_window, 1, WIN_WIDTH - 22, "Time : %13llu", _time);
	wborder(_score_window, '|', '|', '-', '-', '+', '+', '+', '+');
	wrefresh(_score_window);
}
