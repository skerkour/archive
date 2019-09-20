/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 22:21:23 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/18 10:37:03 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Human.hpp"

Human::Human(std::string name) : _name(name)
{
	_funcs[0] = &Human::intimidatingShout;
	_funcs[1] = &Human::meleeAttack;
	_funcs[2] = &Human::rangedAttack;

	//_names[0] = "intimidatingShout";
	//_names[1] = "meleeAttack";
	//_names[2] = "rangedAttack";
}

Human::~Human()
{}
/*
int	findAction(std::string* arr, const std::string& str, int start, int size)
{
	if (start == size || arr[start] == str)
		return start;
	return findAction(arr, str, start + 1, size);
}
*/
// PUBLIC
void	Human::action(const std::string& action_name, const std::string& target)
{
	/*
	int		i = findAction(_names, action_name, 0, 3);

	if (i <= 2) {
		(this->*_funcs[i])(target);
	} else {
		std::cerr << "Bad entry ..." << std::endl;
	}
	*/
	(this->*_funcs[action_name[0] % 3])(target);
}

// PRIVATE
void	Human::intimidatingShout(const std::string& target)
{
	std::cout << _name << " shout to try to intimidate " << target << std::endl;
}

void	Human::meleeAttack(const std::string& target)
{
	std::cout << _name << " attack (melee) " << target << std::endl;
}

void	Human::rangedAttack(const std::string& target)
{
	std::cout << _name << " attack (range) " << target << std::endl;
}
