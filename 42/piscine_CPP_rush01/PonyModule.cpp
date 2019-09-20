/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PonyModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 17:38:50 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/28 23:20:45 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <stdexcept>

#include "PonyModule.hpp"

PonyModule::PonyModule()
{
}

PonyModule::PonyModule(const PonyModule& src)
{
	*this = src;
}

PonyModule::~PonyModule()
{
}

PonyModule& PonyModule::operator=(const PonyModule& rhs)
{
	static_cast<void>(rhs);
	return *this;
}

std::map<std::string, std::string>	PonyModule::getAllDynData()
{
	map_string_t allDynData;
	allDynData.insert(pair_string_t("None", "None"));
	return allDynData;
}

std::map<std::string, std::string>	PonyModule::getAllStaticData()
{
	map_string_t allStaticData;
	allStaticData.insert(pair_string_t("None", "None"));
	return allStaticData;
}

std::string	PonyModule::getData(std::string name)
{
	std::string (PonyModule::*arrFunc[])(void) =
										{
											&PonyModule::_getPony
										};
	const std::string arrNameFunc[] =	{
											"pony"
										};
	for (int i = 0; i < 1; i++)
	{
		if (arrNameFunc[i].compare(name) == 0)
			return (this->*arrFunc[i])();
	}
	throw std::runtime_error("PonyModule: getData: invalid name : " + name);
}

std::string	PonyModule::_getPony()
{
	if ((rand() % 2 & 1)) {
		return
			"         -~~,\n"
			"  ,; _ _~ |\\|\n"
			" ;; ( )_, )\n"
			" ;; /|  |.\\\n"
			;
	} else {
		return
			"         _,_\n"
			"        ;'._\\\n"
			"       ';) \\._,\n"
			"        /  /`-'\n"
			"     ~~( )/\n"
			"        )))\n"
			"        \\\\\\\n"
			;
	}
}
