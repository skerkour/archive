/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 17:19:10 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/23 00:45:07 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	Form("Anonymous", "PresidentialPardonForm", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	Form(target, "PresidentialPardonForm", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm& src)
{
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(
	const PresidentialPardonForm& rhs)
{
	(void)rhs;
	return *this;
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	Form::execute(executor);
	std::cout << getTarget() << " has been pardoned by Zafod Beebkerox"
		<< std::endl;
}
