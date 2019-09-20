/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 14:03:11 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/22 15:58:49 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>

#include "Bureaucrat.hpp"

class Form
{
public:
	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException();
		GradeTooHighException(const GradeTooHighException& src);
		virtual ~GradeTooHighException() throw();

		GradeTooHighException&	operator=(const GradeTooHighException& rhs);

		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException();
		GradeTooLowException(const GradeTooLowException& src);
		virtual ~GradeTooLowException() throw();

		GradeTooLowException&	operator=(const GradeTooLowException& rhs);

		virtual const char* what() const throw();
	};

public:
	Form();
	Form(std::string name, int grade_to_sign, int grade_to_execute);
	Form(const Form& src);
	~Form();

	Form& operator=(const Form& rhs);

	bool		getIsSigned() const;
	int			getGradeToExecute() const;
	int			getGradeToSign() const;
	std::string	getName() const;

	void	beSigned(Bureaucrat& b);

private:
	bool				_is_signed;
	const int			_grade_to_sign,
						_grade_to_execute;
	const std::string	_name;
};

std::ostream&	operator<<(std::ostream& o, const Form& rhs);

#endif // FORM_HPP
