/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 12:20:26 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/15 19:23:03 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

#include "Phonebook.hpp"

Phonebook::Phonebook() : i_contacts_(0)
{}

Phonebook::~Phonebook()
{}

void	Phonebook::addContact()
{
	if (i_contacts_ < 8) {
		contacts_[i_contacts_] = getContactInfos();
		i_contacts_++;
	} else {
		std::cerr << "Error : Too many contacts... Sry dude" << std::endl;
	}
}

void	displayFormatediInfo(int i)
{
	std::cout << std::setw(10) << i;
}

void	displayFormatedContactInfo(std::string str)
{
	if (str.size() > 10) {
		str.resize(9);
		str += ".";
	}
	std::cout << std::setw(10) << str;
}

void	Phonebook::displayContactsInfos(int i)
{
	if (i == i_contacts_)
		return ;
	std::cout << "|";
	displayFormatediInfo(i);
	std::cout << "|";
	displayFormatedContactInfo(contacts_[i].first_name());
	std::cout << "|";
	displayFormatedContactInfo(contacts_[i].last_name());
	std::cout << "|";
	displayFormatedContactInfo(contacts_[i].nickname());
	std::cout << "|" << std::endl;
	return displayContactsInfos(i + 1);
}

void	Phonebook::executeInput()
{
	if (user_input_ == "ADD") {
		addContact();
	} else if (user_input_ == "EXIT") {
		exit();
	} else if (user_input_ == "SEARCH") {
		search();
	}
}

void	Phonebook::exit()
{
	::exit(0);
}

void	Phonebook::getUserInput()
{
	std::cout <<"cmd > ";
	user_input_ = getLine();
}

Contact	Phonebook::getContactInfos()
{
	Contact		ret;

	std::cout << "\tFirst name : ";
	ret.set_first_name(getLine());
	std::cout << "\tLast name : ";
	ret.set_last_name(getLine());
	std::cout << "\tNickname : ";
	ret.set_nickname(getLine());
	std::cout << "\tLogin : ";
	ret.set_login(getLine());
	std::cout << "\tPostal address : ";
	ret.set_postal_address(getLine());
	std::cout << "\tEmail address : ";
	ret.set_email_address(getLine());
	std::cout << "\tPhone number : ";
	ret.set_phone_number(getLine());
	std::cout << "\tBirthday date: ";
	ret.set_birthday_date(getLine());
	std::cout << "\tFavorite meal : ";
	ret.set_favorite_meal(getLine());
	std::cout << "\tUnderwear color : ";
	ret.set_underwear_color(getLine());
	std::cout << "\tDarkest secret : ";
	ret.set_darkest_secret(getLine());
	return ret;
}

void	Phonebook::inspectContact(int i)
{
	std::cout << "\tFirst name : " << contacts_[i].first_name() << std::endl;
	std::cout << "\tLast name : " << contacts_[i].last_name() << std::endl;
	std::cout << "\tNickname : " << contacts_[i].nickname() << std::endl;
	std::cout << "\tLogin : " << contacts_[i].login() << std::endl;
	std::cout << "\tPostal address : " << contacts_[i].postal_address() << std::endl;
	std::cout << "\tEmail address : " << contacts_[i].email_address() << std::endl;
	std::cout << "\tPhone number : " << contacts_[i].phone_number() << std::endl;
	std::cout << "\tBirthday date : " << contacts_[i].birthday_date() << std::endl;
	std::cout << "\tFavorite meal : " << contacts_[i].favorite_meal() << std::endl;
	std::cout << "\tUnderwear color : " << contacts_[i].underwear_color() << std::endl;
	std::cout << "\tDarkest secret : " << contacts_[i].darkest_secret() << std::endl;
}

void	Phonebook::run()
{
	getUserInput();
	executeInput();
	return run();
}

void	Phonebook::search()
{
	int	i;

	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|    index |first name| last name|  nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	displayContactsInfos(0);
	std::cout << "+----------+----------+----------+----------+" << std::endl << std::endl;
	std::cout << "Please enter an index to inspect a contact : ";
	std::cin >> i;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

	if (i >= i_contacts_) {
		std::cerr << "Error : index is too large." << std::endl;
	} else if (i < 0) {
		std::cerr << "Error : index can't be negative." << std::endl;
	} else {
		inspectContact(i);
	}
}
