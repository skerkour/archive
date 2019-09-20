/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 12:14:02 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/15 18:36:19 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>

#include "Contact.hpp"

// defined in main.cpp
std::string	getLine();

class Phonebook
{
public:
	Phonebook();
	~Phonebook();
	void	run();

private:
	void		addContact();
	void		displayContactsInfos(int i);
	void		executeInput();
	void		exit();
	void		getUserInput();
	Contact		getContactInfos();
	void		inspectContact(int i);
	void		search();

	std::string	user_input_;
	Contact		contacts_[8];
	int			i_contacts_;
};

#endif // PHONEBOOK_HPP
