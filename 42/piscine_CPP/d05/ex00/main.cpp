/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 11:37:28 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/22 13:58:55 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>

#include "Bureaucrat.hpp"

int main()
{
	{
	Bureaucrat	sisi("sysy", 42);
	try {
		for(int i = 0; i < 150; i++) {
			sisi.incGrade();
			std::cout << sisi << std::endl;
		}
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << sisi << std::endl;
	}

	{
	Bureaucrat	sisi("sysy", 42);
	try {
		for(int i = 0; i < 150; i++) {
			sisi.decGrade();
			std::cout << sisi << std::endl;
		}
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << sisi << std::endl;
	}
	
	{
	try {
		Bureaucrat	sisi("sysy", 0);
		for(int i = 0; i < 150; i++) {
			sisi.decGrade();
			std::cout << sisi << std::endl;
		}
		std::cout << sisi << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	}

	return 0;
}
