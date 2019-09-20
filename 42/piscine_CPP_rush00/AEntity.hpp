/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 13:27:14 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/21 14:48:02 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AENTITY_HPP
# define AENTITY_HPP

#include <string>
#include <ncurses.h>

class AEntity
{
public:
	AEntity();
	AEntity(const AEntity& src);
	AEntity(std::string pattern, int w, int h, int x, int y, int vx, int vy, int hp, int color);
	virtual ~AEntity() = 0;

	AEntity&	operator=(const AEntity& rhs);

	void		moveX(int n);
	void		moveY(int n);
	int			height() const;
	int			hp() const;
	std::string	pattern() const;
	void		set_x(int x);
	void		set_y(int y);
	void		set_vx(int x);
	void		set_vy(int y);
	int			vx() const;
	int			vy() const;
	int			width() const;
	int			x() const;
	int			y() const;

	virtual void	takeDamage(int amount) = 0;

protected:
	int			_x,
				_y,
				_height,
				_width,
				_hp,
				_vx,
				_vy,
				_color;
	std::string	_pattern;
};

#endif // AENTITY_HPP
