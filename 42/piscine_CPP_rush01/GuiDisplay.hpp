/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GuiDisplay.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 16:19:09 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/28 20:22:52 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUIDISPLAY_HPP
# define GUIDISPLAY_HPP

# include "ADisplay.hpp"
# include "MainWindow.hpp"

class GuiDisplay : public ADisplay
{
public:
	GuiDisplay();
	GuiDisplay(const GuiDisplay& src);
	~GuiDisplay();

	GuiDisplay& operator=(const GuiDisplay& rhs);

	virtual void	refresh();

private:
	virtual void	_refreshCpuData();
	virtual void	_refreshHostData();
	virtual void	_refreshNetworkData();
	virtual void	_refreshRamData();
	virtual void	_refreshPonyData();

	MainWindow*	_window;
};

#endif // GUIDISPLAY_HPP
