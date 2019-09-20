/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GuiDisplay.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 16:19:10 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/28 23:06:24 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <QCoreApplication>

#include "GuiDisplay.hpp"

GuiDisplay::GuiDisplay() : _window(new MainWindow())
{
	_window->init();
}

GuiDisplay::GuiDisplay(const GuiDisplay& src)
{
	*this = src;
}

GuiDisplay::~GuiDisplay()
{
	if (_window)
		delete _window;
}

GuiDisplay& GuiDisplay::operator=(const GuiDisplay& rhs)
{
	static_cast<void>(rhs);
	return *this;
}

void	GuiDisplay::refresh()
{
	_refreshCpuData();
	_refreshHostData();
	_refreshNetworkData();
	_refreshRamData();
	_refreshPonyData();
	QCoreApplication::processEvents();
}

void	GuiDisplay::_refreshCpuData()
{
	_window->set_cpu_model(_cpu_model);
	std::string s = SSTR(_n_cores);
	_window->set_cpu_n_cores(s);
	std::string	s0 = SSTR(_cores_load[0]);
	std::string	s1 = SSTR(_cores_load[1]);
	std::string	s2 = SSTR(_cores_load[2]);
	std::string	s3 = SSTR(_cores_load[3]);
	_window->set_cpu_load_core(s0, s1, s2 ,s3);
}

void	GuiDisplay::_refreshHostData()
{
	_window->set_hostname(_hostname);
	_window->set_username(_username);
	_window->set_os_infos(_os_infos);
	_window->set_date_time(_date_time);
}

void	GuiDisplay::_refreshNetworkData()
{
	std::string s = SSTR(_net_n_ifaces);
	_window->set_net_n_ifaces(s);
	s = SSTR(_net_pkts_in);
	_window->set_net_pkts_in(s);
	s = SSTR(_net_pkts_out);
	_window->set_net_pkts_out(s);
	s = SSTR(_net_data_in);
	_window->set_net_data_in(s);
	s = SSTR(_net_data_out);
	_window->set_net_data_out(s);
	s = _net_interface_en0;
	_window->set_net_en0_addr(s);
	s = _net_interface_lo0;
	_window->set_net_lo0_addr(s);
}

void	GuiDisplay::_refreshRamData()
{
	std::string s = SSTR(_ram_amout / 1048576);
	_window->set_ram_amount(s);
	s = SSTR(_ram_used / 1048576);
	_window->set_ram_used(s);
	s = SSTR(_ram_free / 1048576);
	_window->set_ram_free(s);
	s = SSTR(_ram_perc);
	_window->set_ram_perc(s);
}

void	GuiDisplay::_refreshPonyData()
{
	_window->set_pony_data();
}
