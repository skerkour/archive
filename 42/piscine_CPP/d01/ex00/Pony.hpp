/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 11:27:45 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/16 11:54:23 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

#include <string>

class Pony
{
public:
	Pony(std::string name, int size);
	~Pony();
	std::string	name() const;
	void		sayHello(void) const;
	int			size() const;
	void		set_name(std::string name);
	void		set_size(int size);

private:
	int			_size;
	std::string	_name;
};

#endif // PONY_HPP
