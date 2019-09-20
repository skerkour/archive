/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 14:40:03 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/19 16:12:13 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <string>

class Enemy
{
public:
	Enemy(int hp, const std::string& type);
	Enemy(const Enemy& src);
	virtual ~Enemy();

	Enemy& operator=(const Enemy& rhs);

	const std::string	getType() const;
	int					getHP() const;

	virtual void	takeDamage(int n);

protected:
	Enemy();

	int			_hp;
	std::string	_type;
};

#endif // ENEMY_HPP
