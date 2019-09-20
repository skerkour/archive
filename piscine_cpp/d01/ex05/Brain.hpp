/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:12:18 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/16 17:00:32 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
public:
	Brain();
	Brain(double weight);
	~Brain();

	std::string	identify() const;
	double		weight() const;
	void		set_weight(double weight);

private:
	double	_weight;
};

#endif // BRAIN_HPP
