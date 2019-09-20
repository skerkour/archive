/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monitor.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 16:19:03 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/28 21:52:56 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITOR_HPP
# define MONITOR_HPP

# include "CpuModule.hpp"
# include "HostModule.hpp"
# include "RamModule.hpp"
# include "ADisplay.hpp"

class Monitor
{
public:
	Monitor(int ac, char** av);
	Monitor(const Monitor& src);
	~Monitor();

	Monitor& operator=(const Monitor& rhs);

	void	launch();
	void	setGuiMode();
	void	setCliMode();

private:
	Monitor();
	
	CpuModule	_cpu;
	HostModule	_os;
	RamModule	_ram;
	PonyModule	_pony;
	NetModule	_net;
	int			_mode;
	ADisplay*	_display;
	int			_ac;
	char**		_av;
};

#endif // MONITOR_HPP
