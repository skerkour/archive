/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 17:19:04 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/23 00:45:18 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	Form("Anonymous", "RobotomyRequestForm", 72, 45)
{
	srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	Form(target, "RobotomyRequestForm", 72, 45)
{
	srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
{
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(
	const RobotomyRequestForm& rhs)
{
	(void)rhs;
	return *this;
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	Form::execute(executor);
	if (rand() & 1) {
		std::cout << "BZZZZZZZZZZ..." << getTarget()
			<< " has been robotomized successfully" << std::endl;
	} else {
		std::cout << "The " << getTarget() << "robotomization failde"
			<< std::endl;
	}
}
