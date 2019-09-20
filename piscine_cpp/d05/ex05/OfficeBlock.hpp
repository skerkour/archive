/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 11:37:47 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/23 14:33:59 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP

# include <stdexcept>
# include <string>

# include "Bureaucrat.hpp"
# include "Form.hpp"
# include "Intern.hpp"

class OfficeBlock
{
public:
	class OfficeNotFullException : public std::exception
	{
	public:
		OfficeNotFullException();
		OfficeNotFullException(const OfficeNotFullException& src);
		~OfficeNotFullException() throw();

		OfficeNotFullException	operator=(const OfficeNotFullException& rhs);

		virtual const char*	what() const throw();
	};

public:
	OfficeBlock();
	OfficeBlock(Bureaucrat& signer, Bureaucrat& executor, Intern& intern);
	~OfficeBlock();

	void	setExecutor(Bureaucrat& executor);
	void	setIntern(Intern& intern);
	void	setSigner(Bureaucrat& signer);

	void	doBureaucracy(std::string form_name, std::string target);

private:
	OfficeBlock(const OfficeBlock& src);
	OfficeBlock& operator=(const OfficeBlock& rhs);

	Bureaucrat	_signer,
				_executor;
	Intern		_intern;
	int			_population;
};

#endif // OFFICEBLOCK_HPP
