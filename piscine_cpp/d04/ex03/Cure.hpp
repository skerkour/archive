/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 11:22:59 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/20 23:02:46 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure& src);
	~Cure();

	Cure& operator=(const Cure& rhs);

	AMateria*		clone() const;
	virtual void	use(ICharacter& target);

private:

};

#endif // CURE_HPP
