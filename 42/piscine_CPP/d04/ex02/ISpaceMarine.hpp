/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISpaceMarine.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 09:23:47 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/20 09:33:37 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISPACEMARINE_HPP
# define ISPACEMARINE_HPP

class ISpaceMarine
{
public:
	virtual			~ISpaceMarine() {}

	virtual void			battleCry() const = 0;
	virtual ISpaceMarine*	clone() const = 0;
	virtual void			meleeAttack() const = 0;
	virtual void			rangedAttack() const = 0;
};

#endif // ISPACEMARINE_HPP
