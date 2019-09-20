/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 11:46:48 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/15 16:00:02 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
public:
	Contact();
	~Contact();
	std::string	first_name();
	void		set_first_name(std::string first_name);
	std::string	last_name();
	void		set_last_name(std::string last_name);
	std::string	nickname();
	void		set_nickname(std::string nickname);
	std::string	login();
	void		set_login(std::string login);
	std::string	postal_address();
	void		set_postal_address(std::string postal_address);
	std::string	email_address();
	void		set_email_address(std::string email_address);
	std::string	phone_number();
	void		set_phone_number(std::string phone_number);
	std::string	birthday_date();
	void		set_birthday_date(std::string birthday_date);
	std::string	favorite_meal();
	void		set_favorite_meal(std::string favorite_meal);
	std::string	underwear_color();
	void		set_underwear_color(std::string underwear_color);
	std::string	darkest_secret();
	void		set_darkest_secret(std::string darkest_secret);

private:
	std::string	first_name_,
				last_name_,
				nickname_,
				login_,
				postal_address_,
				email_address_,
				phone_number_,
				birthday_date_,
				favorite_meal_,
				underwear_color_,
				darkest_secret_;
};

#endif // CONTACT_HPP
