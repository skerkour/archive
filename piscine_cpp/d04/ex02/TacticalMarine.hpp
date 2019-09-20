/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 09:25:20 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/20 11:12:50 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
public:
	TacticalMarine();
	TacticalMarine(const TacticalMarine& src);
	~TacticalMarine();

	TacticalMarine& operator=(const TacticalMarine& rhs);

	virtual void			battleCry() const;
	virtual ISpaceMarine*	clone() const;
	virtual void			meleeAttack() const;
	virtual void			rangedAttack() const;

private:

};

#endif // TACTICALMARINE_HPP
