/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 14:00:26 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/15 14:53:43 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "Contact.hpp"

Contact:: Contact()
{}

Contact::~Contact()
{}

std::string	Contact::first_name()
{
	return this->first_name_;
}

void		Contact::set_first_name(std::string first_name)
{
	this->first_name_ = first_name;
}

std::string	Contact::last_name()
{
	return this->last_name_;
}

void		Contact::set_last_name(std::string last_name)
{
	this->last_name_ = last_name;
}

std::string	Contact::nickname()
{
	return this->nickname_;
}

void		Contact::set_nickname(std::string nickname)
{
	this->nickname_ = nickname;
}

std::string	Contact::login()
{
	return this->login_;
}

void		Contact::set_login(std::string login)
{
	this->login_ = login;
}

std::string	Contact::postal_address()
{
	return this->postal_address_;
}

void		Contact::set_postal_address(std::string postal_address)
{
	this->postal_address_ = postal_address;
}

std::string	Contact::email_address()
{
	return this->email_address_;
}

void		Contact::set_email_address(std::string email_address)
{
	this->email_address_ = email_address;
}

std::string	Contact::phone_number()
{
	return this->phone_number_;
}

void		Contact::set_phone_number(std::string phone_number)
{
	this->phone_number_ = phone_number;
}

std::string	Contact::birthday_date()
{
	return this->birthday_date_;
}

void		Contact::set_birthday_date(std::string birthday_date)
{
	this->birthday_date_ = birthday_date;
}

std::string	Contact::favorite_meal()
{
	return this->favorite_meal_;
}

void		Contact::set_favorite_meal(std::string favorite_meal)
{
	this->favorite_meal_ = favorite_meal;
}

std::string	Contact::underwear_color()
{
	return this->underwear_color_;
}

void		Contact::set_underwear_color(std::string underwear_color)
{
	this->underwear_color_ = underwear_color;
}

std::string	Contact::darkest_secret()
{
	return this->darkest_secret_;
}

void		Contact::set_darkest_secret(std::string darkest_secret)
{
	this->darkest_secret_ = darkest_secret;
}
