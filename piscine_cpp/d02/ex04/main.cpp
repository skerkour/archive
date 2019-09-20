/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/18 16:06:58 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/18 19:03:30 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "EvalExpr.hpp"

void	usage(std::string filename)
{
	std::cout << "usage: " << std::endl
		<< "------" << std::endl
		<< filename << "<expression>" << std::endl;
}

int	main(int ac, char **av)
{
	if (ac == 2) {
		EvalExpr	engine;
		engine.evaluate(std::string(av[1]));
	} else {
		usage(std::string(av[0]));
	}
	return 0;
}
