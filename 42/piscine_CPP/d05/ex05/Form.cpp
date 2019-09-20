/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 14:03:15 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/23 00:44:59 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::GradeTooHighException::GradeTooHighException()
{
}

Form::GradeTooHighException::GradeTooHighException(
	const GradeTooHighException& src)
{
	*this = src;
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
}

Form::GradeTooHighException&	Form::GradeTooHighException::operator=(
	const GradeTooHighException& rhs)
{
	(void)rhs;
	return *this;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Error: grade is too high");
}

Form::GradeTooLowException::GradeTooLowException()
{
}

Form::GradeTooLowException::GradeTooLowException(
	const GradeTooLowException& src)
{
	*this = src;
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
}

Form::GradeTooLowException&	Form::GradeTooLowException::operator=(
	const GradeTooLowException& rhs)
{
	(void)rhs;
	return *this;
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Error: grade is too low");
}

Form::NotSignedException::NotSignedException()
{
}

Form::NotSignedException::NotSignedException(const NotSignedException& src)
{
	*this = src;
}

Form::NotSignedException::~NotSignedException() throw()
{
}

Form::NotSignedException&	Form::NotSignedException::operator=(
	const NotSignedException& rhs)
{
	(void)rhs;
	return *this;
}

const char*	Form::NotSignedException::what() const throw()
{
	return ("Form not signed, yet");
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

Form::Form() : _is_signed(false), _grade_to_sign(1), _grade_to_execute(1),
	_name("AnonymousForm"), _target("Anonymous")
{
}

Form::Form(std::string target, std::string name, int grade_to_sign,
	int grade_to_execute)
	: _is_signed(false), _grade_to_sign(grade_to_sign),
	_grade_to_execute(grade_to_execute), _name(name), _target(target)
{
	if (_grade_to_sign < 1 || _grade_to_execute < 1) {
		throw Form::GradeTooHighException();
	} else if (_grade_to_sign > 150 || _grade_to_execute > 150) {
		throw Form::GradeTooLowException();
	}
}

Form::Form(const Form& src) :
	_is_signed(src._is_signed), _grade_to_sign(src._grade_to_sign),
	_grade_to_execute(src._grade_to_execute), _name(src._name)
{
	if (_grade_to_sign < 1 || _grade_to_execute < 1) {
		throw Form::GradeTooHighException();
	} else if (_grade_to_sign > 150 || _grade_to_execute > 150) {
		throw Form::GradeTooLowException();
	}
}

Form::~Form()
{
}

Form& Form::operator=(const Form& rhs)
{
	if (this != &rhs) {
		_is_signed = rhs.getIsSigned();
		_target = rhs._target;
	}
	return *this;
}

bool	Form::getIsSigned() const
{
	return _is_signed;
}

int	Form::getGradeToExecute() const
{
	return _grade_to_execute;
}

int	Form::getGradeToSign() const
{
	return _grade_to_sign;
}

std::string	Form::getName() const
{
	return _name;
}

std::string	Form::getTarget() const
{
	return _target;
}

void	Form::settarget(std::string target)
{
	_target = target;
}

void	Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() < _grade_to_sign) {
		_is_signed = true;
	} else {
		throw Form::GradeTooLowException();
	}
}

void	Form::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > _grade_to_execute) {
		throw Form::GradeTooLowException();
	} else if (!_is_signed) {
		throw Form::NotSignedException();
	}
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

std::ostream&	operator<<(std::ostream& o, const Form& rhs)
{
	o << "form " << rhs.getName() << " which is "
		<< (rhs.getIsSigned() ? "" : "not ") << " signed, require a grade "
		<< rhs.getGradeToSign() << " to sign, and "
		<< rhs.getGradeToExecute() << " to be executed.";
	return o;
}
