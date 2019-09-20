/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 11:37:24 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/22 18:49:57 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Form;

class Bureaucrat
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

		GradeTooLowException& operator=(const GradeTooLowException& rhs);

		virtual const char* what() const throw();
	};

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& src);
	~Bureaucrat();

	std::string	getName() const;
	int			getGrade() const;
	
	void	incGrade();
	void	decGrade();

	Bureaucrat& operator=(const Bureaucrat& rhs);

	void	executeForm(const Form& form);
	void	signForm(Form& f);

private:
	std::string	_name;
	int			_grade;
};

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& rhs);

#endif // BUREAUCRAT_HPP
