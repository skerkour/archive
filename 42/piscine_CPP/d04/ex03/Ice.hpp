/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 11:23:09 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/20 23:02:46 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice& src);
	~Ice();

	Ice& operator=(const Ice& rhs);

	AMateria*		clone() const;
	virtual void	use(ICharacter& target);

private:

};

#endif // ICE_HPP
