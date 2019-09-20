/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 11:30:23 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/19 13:59:42 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

#include <string>

#include "Victim.hpp"

class Sorcerer
{
public:
	Sorcerer(std::string name, std::string title);
	Sorcerer(const Sorcerer& src);
	~Sorcerer();

	Sorcerer& operator=(const Sorcerer& rhs);

	void	polymorph(const Victim& vic) const;

	std::string	name() const;
	void		set_name(std::string name);
	void		set_title(std::string title);
	std::string	title() const;

private:
	Sorcerer();
	std::string	_name,
				_title;
};

std::ostream&	operator<<(std::ostream& o, const Sorcerer& rhs);

#endif // SORCERER_HPP
