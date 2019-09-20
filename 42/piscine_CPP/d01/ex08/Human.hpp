/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 22:02:35 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/18 10:37:13 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

#include <string>

class Human
{
	typedef void (Human::*HumanMethodFPointer)(const std::string&);

public:
	Human(std::string name);
	~Human();

	void	action(const std::string& action_name, const std::string& target);

private:
	void	intimidatingShout(const std::string& target);
	void	meleeAttack(const std::string& target);
	void	rangedAttack(const std::string& target);

	HumanMethodFPointer	_funcs[3];
	//std::string			_names[3];
	std::string			_name;
};

#endif // HUMAN_HPP
