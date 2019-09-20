/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 14:03:11 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/23 00:40:33 by skerkour         ###   ########.fr       */
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

		virtual const char*	what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException();
		GradeTooLowException(const GradeTooLowException& src);
		virtual ~GradeTooLowException() throw();

		GradeTooLowException&	operator=(const GradeTooLowException& rhs);

		virtual const char*	what() const throw();
	};

	class NotSignedException : public std::exception
	{
	public:
		NotSignedException();
		NotSignedException(const NotSignedException& src);
		virtual ~NotSignedException() throw();

		NotSignedException&	operator=(const NotSignedException& rhs);

		virtual const char*	what() const throw();
	};

public:
	Form();
	Form(std::string target, std::string name, int grade_to_sign,
		int grade_to_execute);
	Form(const Form& src);
	virtual ~Form() = 0;

	Form& operator=(const Form& rhs);

	bool		getIsSigned() const;
	int			getGradeToExecute() const;
	int			getGradeToSign() const;
	std::string	getName() const;
	std::string	getTarget() const;
	void		settarget(std::string target);

	void			beSigned(Bureaucrat& b);
	virtual void	execute(const Bureaucrat& executor) const;

private:
	bool				_is_signed;
	const int			_grade_to_sign,
						_grade_to_execute;
	const std::string	_name;
	std::string			_target;
};

std::ostream&	operator<<(std::ostream& o, const Form& rhs);

#endif // FORM_HPP
