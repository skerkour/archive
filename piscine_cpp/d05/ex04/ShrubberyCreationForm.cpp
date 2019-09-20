/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 17:18:58 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/23 00:44:15 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
	Form("Anonymous", "ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	Form(target, "ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
{
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
	const ShrubberyCreationForm& rhs)
{
	(void)rhs;
	return *this;
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	std::ofstream	outFile;

	Form::execute(executor);
	outFile.open(getTarget() + "_shrubbery",
					std::ofstream::out | std::ofstream::trunc);
	if (outFile.fail()) {
		std::cerr << "Error openning the outfile" << std::endl;
	}
	outFile << "Y Y Y Y Y Y Y" << std::endl <<"Y Y Y Y Y Y Y" << std::endl;
	outFile.close();
}
