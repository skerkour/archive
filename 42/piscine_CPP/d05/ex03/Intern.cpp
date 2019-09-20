/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 00:48:54 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/24 11:35:15 by skerkour         ###   ########.fr       */
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

std::string	Intern::_forms_names[N_FORMS] = {
	"presidential pardon",
	"robotomy request",
	"shrubbery creation"
};

Intern::Intern()
{
	_funcs[0] = &Intern::_newPresidentialPardonForm;
	_funcs[1] = &Intern::_newRobotomyRequestForm;
	_funcs[2] = &Intern::_newShrubberyCreationForm;
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
	try {
		return _searchForm(name, target);
	} catch (std::exception& e) {
		std::cout << name << " : form nout found :(" << std::endl;
		return NULL;
	}
}

Form*	Intern::_searchForm(std::string name, std::string target)
{
	for (int i = 0; i < N_FORMS; ++i)
	{
		if (name == _forms_names[i])
			return (this->*_funcs[i])(target);
	}
	throw FormNotFoundException();
	return NULL;
}


Form*	Intern::_newPresidentialPardonForm(std::string target)
{
	return new PresidentialPardonForm(target);
}

Form*	Intern::_newRobotomyRequestForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

Form*	Intern::_newShrubberyCreationForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}
