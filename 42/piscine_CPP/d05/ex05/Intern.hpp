/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 00:48:48 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/23 11:14:26 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP


#include <stdexcept>
#include <string>

#include "Form.hpp"

class Intern
{
public:
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

	static std::string	_forms_names[3];
};

#endif // INTERN_HPP
