/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 15:24:46 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/27 19:39:04 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

class IMonitorModule;

class IMonitorDisplay
{
public:
	virtual ~IMonitorDisplay() {}

	virtual void	refresh() = 0;
	virtual void	setStaticData(IMonitorModule& module) = 0;
	virtual void	setData(IMonitorModule& module) = 0;
};

#endif // IMONITORDISPLAY_HPP
