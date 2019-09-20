/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 11:37:28 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/23 00:02:59 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include <string>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	{
		Bureaucrat					b1("B1", 150);
		try
		{

			ShrubberyCreationForm	 	test01("SCF_1");
			RobotomyRequestForm	 		test02("RRF_1");
			PresidentialPardonForm	 	test03("PDF_1");

			std::cout << b1 << std::endl;
			std::cout << test01 << std::endl;
			std::cout << test02 << std::endl;
			std::cout << test03 << std::endl;

			b1.signForm(test01);
			b1.signForm(test02);
			b1.signForm(test03);

			b1.executeForm(test01);
			b1.executeForm(test02);
			b1.executeForm(test03);

		}
		catch(std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	{
		try
		{

			Bureaucrat					b2("B2", 20);
			ShrubberyCreationForm	 	test01("SCF_2");
			RobotomyRequestForm	 		test02("RRF_2");
			PresidentialPardonForm	 	test03("PDF_2");

			std::cout << b2 << std::endl;
			std::cout << test01 << std::endl;
			std::cout << test02 << std::endl;
			std::cout << test03 << std::endl;

			b2.signForm(test01);
			b2.signForm(test02);
			b2.signForm(test03);

			b2.executeForm(test01);
			b2.executeForm(test02);
			b2.executeForm(test03);

		}
		catch(std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	{
		try
		{
			Bureaucrat					b3("B3", 1);
			PresidentialPardonForm	 	test01("PDF_3");
			std::cout << b3 << std::endl;
			std::cout << test01 << std::endl;


			b3.signForm(test01);

			b3.executeForm(test01);

		}
		catch(std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	{

		try
		{
			Bureaucrat				b4("B4", 70);
			RobotomyRequestForm	 	test01("RRF_4");
			std::cout << b4 << std::endl;
			std::cout << test01 << std::endl;


			b4.signForm(test01);

			b4.executeForm(test01);

		}
		catch(std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	{
		try
		{
			Bureaucrat					b5("B5", 140);
			ShrubberyCreationForm	 	test01("SCF_5");
			std::cout << b5 << std::endl;
			std::cout << test01 << std::endl;


			b5.signForm(test01);

			b5.executeForm(test01);

		}
		catch(std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
