/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 11:37:28 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/23 11:20:53 by skerkour         ###   ########.fr       */
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
#include "Intern.hpp"

int main()
{
	Bureaucrat b1 = Bureaucrat("The Bureaucrat 1", 40);
	Intern i1;
	Form *f1;
	Form *f2;
	Form *f3;
	Form *f4;


	f1 = i1.makeForm("robotomy request", "Bender");
	f2 = i1.makeForm("presidential pardon", "Bender");
	f3 = i1.makeForm("shrubbery creation", "Bender");
	std::cout << *f1 << std::endl;
	std::cout << *f2 << std::endl;
	std::cout << *f3 << std::endl;

	b1.signForm(*f1);
	b1.executeForm(*f1);

	f4 = i1.makeForm("TEST", "Bender");

	return 0;
}
