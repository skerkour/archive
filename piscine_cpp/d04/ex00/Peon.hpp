/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 11:30:45 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/19 16:07:38 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

#include "Victim.hpp"

class Peon : public Victim
{
public:
	Peon(std::string name);
	Peon(const Peon& src);
	~Peon();

	Peon& operator=(const Peon& rhs);

	void	getPolymorphed() const;

private:
	Peon();
};

#endif // PEON_HPP
