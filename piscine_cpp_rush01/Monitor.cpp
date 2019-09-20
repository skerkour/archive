/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monitor.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 16:19:05 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/28 23:28:59 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <QApplication>
#include <stdexcept>
#include <unistd.h>
#include <ctime>

#include "CliDisplay.hpp"

#undef scroll

#include "GuiDisplay.hpp"
#include "Monitor.hpp"

Monitor::Monitor(int ac, char** av) : _mode(0), _display(0), _ac(ac), _av(av)
{
}

Monitor::Monitor(const Monitor& src)
{
	*this = src;
}

Monitor::~Monitor()
{
	if (_display)
		delete _display;
}

Monitor& Monitor::operator=(const Monitor& rhs)
{
	if (this != &rhs) {
		_mode = rhs._mode;
	}
	return *this;
}

void	Monitor::launch()
{
	QApplication	a(_ac, _av);
	
	if (_mode == 4) {
		_display = new GuiDisplay();
		//return static_cast<void>(a.exec());
	} else if (_mode == 2) {
		_display = new CliDisplay();
	} else {
		throw std::runtime_error("unknown monitor mode");
	}

	_display->setStaticData(_cpu);
	_display->setStaticData(_ram);
	_display->setStaticData(_os);
	_display->setData(_pony);
	_display->setData(_cpu);
	_display->setData(_ram);
	_display->setData(_net);
	_display->setData(_os);

	time_t	oldtime = time(0);
	while (42)
	{
		time_t	timee = time(0);
		if (timee >= oldtime + 1) {
			_display->setData(_cpu);
			oldtime = time(0);
			_display->setData(_ram);
			_display->setData(_pony);
			_display->setData(_net);
		}
		_display->setData(_os);
		_display->refresh();
		usleep(10000);
	}
	exit(a.exec());
}

void	Monitor::setGuiMode()
{
	_mode = 4;
}

void	Monitor::setCliMode()
{
	_mode = 2;
}

Monitor::Monitor() : _mode(0), _display(0)
{
}
