/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 11:37:15 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/24 10:48:12 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException()
{
}

Bureaucrat::GradeTooHighException::GradeTooHighException(
	const GradeTooHighException& src)
{
	*this = src;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
}

Bureaucrat::GradeTooHighException&	Bureaucrat::GradeTooHighException::operator=(
	const GradeTooHighException& rhs)
{
	(void)rhs;
	return *this;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error: grade is too high");
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException(
	const GradeTooLowException& src)
{
	*this = src;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
}

Bureaucrat::GradeTooLowException&	Bureaucrat::GradeTooLowException::operator=(
	const GradeTooLowException& rhs)
{
	(void)rhs;
	return *this;
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error: grade is too low");
}

Bureaucrat::Bureaucrat() : _name("AnonymousBureaucrat"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	} else if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	} else {
		_grade = grade;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
{
	*this = src;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs) {
		_name = rhs._name;
		_grade = rhs._grade;
	}
	return *this;
}

std::string	Bureaucrat::getName() const
{
	return _name;
}

int	Bureaucrat::getGrade() const
{
	return _grade;
}

void	Bureaucrat::incGrade()
{
	if (_grade <= 1) {
		throw Bureaucrat::GradeTooHighException();
	} else {
		--_grade;
	}
}

void	Bureaucrat::decGrade()
{
	if (_grade >= 150) {
		throw Bureaucrat::GradeTooLowException();
	} else {
		++_grade;
	}
}

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return o;
}
