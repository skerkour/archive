/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 00:48:48 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/24 11:36:02 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP


#include <stdexcept>
#include <string>

#include "Form.hpp"

#define N_FORMS 3

class Intern
{
public:
	typedef Form* (Intern::*InternFPointer)(std::string);

	class FormNotFoundException : public std::exception
	{
	public:
		FormNotFoundException();
		FormNotFoundException(const FormNotFoundException& src);
		virtual ~FormNotFoundException() throw();

		FormNotFoundException&	operator=(const FormNotFoundException& rhs);

		virtual const char*	what() const throw();
	};

public:
	Intern();
	Intern(const Intern& src);
	~Intern();

	Intern& operator=(const Intern& rhs);

	Form*	makeForm(std::string name, std::string target);

private:
	Form*	_searchForm(std::string name, std::string target);
	Form*	_newPresidentialPardonForm(std::string target);
	Form*	_newRobotomyRequestForm(std::string target);
	Form*	_newShrubberyCreationForm(std::string target);

	InternFPointer		_funcs[N_FORMS];
	static std::string	_forms_names[N_FORMS];
};

#endif // INTERN_HPP
