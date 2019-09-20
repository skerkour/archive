/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 00:48:54 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/23 14:41:15 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <string>
#include <stdexcept>

#include "Form.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::FormNotFoundException::FormNotFoundException()
{
}

Intern::FormNotFoundException::FormNotFoundException(
	const FormNotFoundException& src)
{
	*this = src;
}

Intern::FormNotFoundException::~FormNotFoundException() throw()
{
}

Intern::FormNotFoundException&	Intern::FormNotFoundException::operator=(
	const FormNotFoundException& rhs)
{
	(void)rhs;
	return *this;
}

const char*	Intern::FormNotFoundException::what() const throw()
{
	return ("Error: form was not found");
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

std::string	Intern::_forms_names[3] = {
	"presidential pardon",
	"robotomy request",
	"shrubbery creation"
};

Intern::Intern()
{
}

Intern::Intern(const Intern& src)
{
	*this = src;
}

Intern::~Intern()
{
}

Intern& Intern::operator=(const Intern& rhs)
{
	(void)rhs;
	return *this;
}

Form*	Intern::makeForm(std::string name, std::string target)
{
		return _searchForm(name, target);
}

Form*	Intern::_searchForm(std::string name, std::string target)
{
	if (name == _forms_names[0]) {
		return new PresidentialPardonForm(target);
	} else if (name == _forms_names[1]) {
		return new RobotomyRequestForm(target);
	} else if (name == _forms_names[2]) {
		return new ShrubberyCreationForm(target);
	} else {
		throw FormNotFoundException();
		return NULL;
	}
}
