/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 11:37:55 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/23 14:42:53 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OfficeBlock.hpp"

OfficeBlock::OfficeNotFullException::OfficeNotFullException()
{
}

OfficeBlock::OfficeNotFullException::OfficeNotFullException(
		const OfficeNotFullException& src)
{
	*this = src;
}

OfficeBlock::OfficeNotFullException::~OfficeNotFullException() throw()
{
}

OfficeBlock::OfficeNotFullException	OfficeBlock::OfficeNotFullException::operator=(
		const OfficeNotFullException& rhs)
{
	(void)rhs;
	return *this;
}

const char*	OfficeBlock::OfficeNotFullException::what() const throw()
{
	return ("Error: Not state employees are all here.");
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

OfficeBlock::OfficeBlock() : _population(0)
{
}

OfficeBlock::OfficeBlock(Bureaucrat& signer, Bureaucrat& executor,
		Intern& intern) : _signer(signer), _executor(executor), _intern(intern),
	_population(0)
{
}

OfficeBlock::~OfficeBlock()
{
}

void	OfficeBlock::setExecutor(Bureaucrat& executor)
{
	_executor = executor;
	_population++;
}

void	OfficeBlock::setIntern(Intern& intern)
{
	_intern = intern;
	_population++;
}

void	OfficeBlock::setSigner(Bureaucrat& signer)
{
	_signer = signer;
	_population++;
}

void	OfficeBlock::doBureaucracy(std::string form_name, std::string target)
{
	Form*	f = NULL;

	if (_population >= 3) {
		f = _intern.makeForm(form_name, target);
		_signer.signForm(*f);
		_executor.executeForm(*f);
		delete f;
		f = NULL;
	} else {
		throw OfficeNotFullException();
	}
}

OfficeBlock::OfficeBlock(const OfficeBlock& src)
{
	*this = src;
}

OfficeBlock& OfficeBlock::operator=(const OfficeBlock& rhs)
{
	(void)rhs;
	return *this;
}
