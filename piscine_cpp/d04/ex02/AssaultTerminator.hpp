/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 09:23:56 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/20 11:12:50 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
public:
	AssaultTerminator();
	AssaultTerminator(const AssaultTerminator& src);
	~AssaultTerminator();

	AssaultTerminator& operator=(const AssaultTerminator& rhs);
	
	virtual void			battleCry() const;
	virtual ISpaceMarine*	clone() const;
	virtual void			meleeAttack() const;
	virtual void			rangedAttack() const;

private:

};

#endif // ASSAULTTERMINATOR_HPP
