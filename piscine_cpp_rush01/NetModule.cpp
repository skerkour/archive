/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 14:05:07 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/28 16:50:54 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>

#include "NetModule.hpp"

NetModule::NetModule()
{
}

NetModule::NetModule(const NetModule& src)
{
	*this = src;
}

NetModule::~NetModule()
{
}

NetModule& NetModule::operator=(const NetModule& rhs)
{
	static_cast<void>(rhs);
	return *this;
}

std::map<std::string, std::string>	NetModule::getAllDynData()
{
	map_string_t allDynData;
	allDynData.insert(pair_string_t("None", "None"));
	return allDynData;
}

std::map<std::string, std::string>	NetModule::getAllStaticData()
{
	map_string_t allStaticData;
	allStaticData.insert(pair_string_t("None", "None"));
	return allStaticData;
}

std::string	NetModule::getData(std::string name)
{
	std::string (NetModule::*arrFunc[])(void) =
										{
											&NetModule::_getNIfaces,
											&NetModule::_pktsInt,
											&NetModule::_pktsOut,
											&NetModule::_dataIn,
											&NetModule::_dataOut,
											&NetModule::_en0Interface,
											&NetModule::_lo0Interface,

										};
	const std::string arrNameFunc[] =	{
											"net_n_ifaces",
											"net_pkts_in",
											"net_pkts_out",
											"net_data_in",
											"net_data_out",
											"net_interface_en0",
											"net_interface_lo0"
										};
	for (int i = 0; i < 7; i++)
	{
		if (arrNameFunc[i].compare(name) == 0)
			return (this->*arrFunc[i])();
	}
	throw std::runtime_error("NetModule: getData: invalid name : " + name);
}

//__Functions__
std::string	NetModule::_getNIfaces()
{
	return "2";
}

std::string NetModule::_en0Interface(void)
{
	return _parseNetwork("ifconfig en0 | grep 'inet ' | awk '{print $2}' | tr -d '\n'");
}

std::string NetModule::_lo0Interface(void)
{
	return _parseNetwork("ifconfig lo0 | grep 'inet ' | awk '{print $2}' | tr -d '\n'");
}

//__Dynamique__
std::string NetModule::_pktsInt(void)
{
	return _parseNetwork("netstat -ib en0 | grep Link#4 | awk '{print $5}' | tr -d '\n'");
}

std::string NetModule::_pktsOut(void)
{
	return _parseNetwork("netstat -ib en0 | grep Link#4 | awk '{print $8}' | tr -d '\n'");
}

std::string NetModule::_dataIn(void)
{
	return _parseNetwork("netstat -ib en0 | grep Link#4 | awk '{print $7}' | tr -d '\n'");
}

std::string NetModule::_dataOut(void)
{
	return _parseNetwork("netstat -ib en0 | grep Link#4 | awk '{print $10}' | tr -d '\n'");
}


//__Tools__
std::string NetModule::_parseNetwork(std::string cmd)
{
	FILE *response;
	char buffer[500];
	std::string value;

	response = popen(cmd.c_str(), "r");
	if (!response)
		throw std::runtime_error("NetModule: Error popen");
	while (!feof(response))
		if(fgets(buffer, sizeof(buffer), response) != NULL)
			value += buffer;
	pclose(response);
	return value;
}
