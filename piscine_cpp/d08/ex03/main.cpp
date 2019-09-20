/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 11:42:01 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/26 17:11:55 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdexcept>

#include "Interpreter.hpp"

void	usage(std::string& name)
{
	std::cout << "usage :" << std::end << "~~~~~~~" << std::endl;
	std::cout << name << " <file>" << std::endl;
}

int	main(int ac, char **av)
{
	Interpreter	interpreter;

	if (ac != 2)
		usage(std::string(av[0]));
	else
	{
		try {
			interpreter.readFile(std::string(av[1]));
			interprter.execute();
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
