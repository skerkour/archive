/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 16:19:00 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/28 17:55:52 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdexcept>
#include <ncurses.h>
#include <exception>
#include <ctime>
#include <cstdlib>

#include "Monitor.hpp"

int main(int ac, char** av)
{
	Monitor	monitor(ac, av);
	srand(time(0));

	try {
		if (ac == 2 && std::string(av[1]) == "-g") {
			monitor.setGuiMode();
		} else {
			monitor.setCliMode();
		}

		monitor.launch();
	} catch (std::exception& e) {
		endwin();
		std::cerr << "Error: " << e.what() << std::endl;
		exit(-42);
	} catch (std::runtime_error& e) {
		endwin();
		std::cerr << "Error: " << e.what() << std::endl;
		exit(-42);
	}
	return 0;
}
