/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:12:30 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/17 19:45:05 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

#include <string>

#include "Brain.hpp"

class Human
{
public:
	Human();
	~Human();

	const Brain&	getBrain();
	std::string		identify() const;

private:
	const Brain	_brain;
};

#endif // HUMAN_HPP
