/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CliDisplay.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 16:18:54 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/28 18:49:35 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIDISPLAY_HPP
# define CLIDISPLAY_HPP

# include <ncurses.h>

# include "ADisplay.hpp"

# define KEY_ESC 27

class CliDisplay : public ADisplay
{
public:
	CliDisplay();
	CliDisplay(const CliDisplay& src);
	~CliDisplay();

	CliDisplay& operator=(const CliDisplay& rhs);

	virtual void	refresh();

private:
	void			_drawProgressBar(int y, int x, int perc);
	virtual void	_refreshCpuData();
	virtual void	_refreshHostData();
	virtual void	_refreshNetworkData();
	virtual void	_refreshRamData();
	virtual void	_refreshPonyData();

public:
	static void	resizeHandler(int s);

private:
	static int	MIN_WIN_X,
				MIN_WIN_Y;
};

#endif // CLIDISPLAY_HPP
