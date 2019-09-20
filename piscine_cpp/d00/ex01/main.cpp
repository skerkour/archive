/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 11:44:25 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/15 17:56:37 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cstdlib>

#include "Phonebook.hpp"

std::string	getLine()
{
	std::string	ret;

	std::getline(std::cin, ret);
	if (std::cin.eof())
		exit(0);
	return ret;
}

int	main(void)
{
	Phonebook	book;

	book.run();
	return 0;
}
