/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CliDisplay.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 16:18:56 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/28 22:27:53 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <ncurses.h>
#include <stdexcept>

#include "CliDisplay.hpp"
#include "CpuModule.hpp"
#include "RamModule.hpp"

int	CliDisplay::MIN_WIN_X = 104;
int	CliDisplay::MIN_WIN_Y = 50;

CliDisplay::CliDisplay()
{
	int	x,
		y;

	initscr();
	getmaxyx(stdscr, y,x);
	if (x < MIN_WIN_X || y < MIN_WIN_Y) {
		endwin();
		throw std::runtime_error("window too small");
	}
	noecho();
	start_color();
	keypad(stdscr, TRUE);
	signal(SIGWINCH, resizeHandler);
	nodelay(stdscr, TRUE);
	cbreak();
	timeout(0);
	curs_set(false);
}

CliDisplay::CliDisplay(const CliDisplay& src)
{
	*this = src;
}

CliDisplay::~CliDisplay()
{
}

CliDisplay& CliDisplay::operator=(const CliDisplay& rhs)
{
	static_cast<void>(rhs);
	return *this;
}

void	CliDisplay::refresh()
{
	int	k;

	k = getch();
	if (k == KEY_ESC) {
		endwin();
		exit(0);
	}	else if (k == KEY_RESIZE) {
		resizeHandler(0);
	}

	clear();
	_refreshHostData();
	mvhline(10, 0, 0, 1042);
	_refreshCpuData();
	mvhline(27, 0, 0, 1042);
	_refreshRamData();
	mvhline(35, 0, 0, 1042);
	_refreshNetworkData();
	//mvhline(38, 0, 0, 1042);
	_refreshPonyData();

	border('|', '|', '-', '-', '+', '+', '+', '+');
	wrefresh(stdscr);
}

void	CliDisplay::resizeHandler(int s)
{
	static_cast<void>(s);
	int	x,
		y;

	endwin();
	//throw std::runtime_error("can't hot resize");
	std::cerr << "Error: can't hot resize" << std::endl;
	exit(-42);
	getmaxyx(stdscr, y, x);
	if (x < MIN_WIN_X || y < MIN_WIN_Y) {
		endwin();
		throw std::runtime_error("window too small");
	}
}

void	CliDisplay::_drawProgressBar(int y, int x, int perc)
{
	mvprintw(y, x, "[");
	for (int j = 0; j < 100; j++) {
		if (j < perc) {
			mvprintw(y, j + x + 1, "|");
		} else {
			mvprintw(y, j + x + 1, " ");
		}
	}
	mvprintw(y, 101 + x, "]");
	mvprintw(y, 103 + x, "%u %%", perc);
}

void	CliDisplay::_refreshCpuData()
{
	mvprintw(11, 2, "CPU :");
	mvprintw(13, 6, _cpu_model.c_str());
	mvprintw(14, 6, "%ld Cores", _n_cores);
	_drawProgressBar(16, 6, _cores_load[0]);
	_drawProgressBar(18, 6, _cores_load[1]);
	_drawProgressBar(20, 6, _cores_load[2]);
	_drawProgressBar(22, 6, _cores_load[3]);

	/*
	for (int i = 0; i < _n_cores; ++i) {
		_drawProgressBar(16 + i, 1, _cores_load[i]);
	}
	*/
}

void	CliDisplay::_refreshHostData()
{
	mvprintw(1, 2, "Host :");
	mvprintw(2, 6, _username.c_str());
	mvprintw(2, _username.length() + 6, " @ ");
	mvprintw(2, _username.length() + 9, _hostname.c_str());
	mvprintw(3, 6, _os_infos.c_str());
	mvprintw(4, 6, _date_time.c_str());
}

void	CliDisplay::_refreshNetworkData()
{
	mvprintw(36, 2, "Net :");
	mvprintw(37, 6, "Nb d'Ifaces : %lu", _net_n_ifaces);
	mvprintw(37, 42, "| lo0 : %s | en0 : %s |", _net_interface_lo0.c_str(),
		_net_interface_en0.c_str());
	mvprintw(38, 6, "Packets in  : %lu", _net_pkts_in);
	mvprintw(39, 6, "Packets out : %lu", _net_pkts_out);
	mvprintw(40, 6, "Data in     : %lu", _net_data_in);
	mvprintw(41, 6, "Data out    : %lu", _net_data_out);
}

void	CliDisplay::_refreshRamData()
{
	mvprintw(28, 2, "RAM :");
	mvprintw(29, 6, "Total: %9lu Mb", _ram_amout / 1048576);
	mvprintw(30, 6, "Used : %9lu Mb", _ram_used / 1048576);
	mvprintw(31, 6, "Free : %9lu Mb", _ram_free / 1048576);
	_drawProgressBar(33, 6, _ram_perc);
}

void	CliDisplay::_refreshPonyData()
{
	mvprintw(42, 6, _pony.c_str());
}
