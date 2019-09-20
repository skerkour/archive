/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 12:00:24 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/16 15:11:11 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
public:
	Zombie(std::string name, std::string type);
	Zombie();
	~Zombie();
	void		announce();
	std::string	name() const;
	std::string	type() const;
	void		set_name(std::string name);
	void		set_type(std::string type);

private:
	std::string	_name;
	std::string	_type;
};

#endif // ZOMBIE_HPP
