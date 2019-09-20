/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 11:30:34 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/19 15:04:47 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <string>

class Victim
{
public:
	Victim(std::string name);
	Victim(const Victim& src);
	virtual ~Victim();

	Victim& operator=(const Victim& rhs);
	
	virtual void	getPolymorphed() const;
	
	std::string	name() const;
	void		set_name(std::string name);


protected:
	Victim();

	std::string	_name;

};

std::ostream&	operator<<(std::ostream& o, const Victim& rhs);

#endif // VICTIM_HPP
