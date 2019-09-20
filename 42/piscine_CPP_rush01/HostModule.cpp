/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 19:13:54 by ybarbier          #+#    #+#             */
/*   Updated: 2015/06/27 19:13:55 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HostModule.hpp"

HostModule::HostModule(void)
{
	return;
}

HostModule::HostModule(HostModule const & src)
{
	*this = src;
	return;
}

HostModule::~HostModule(void)
{
	return;
}

HostModule & HostModule::operator=(HostModule const & rhs)
{
	static_cast<void>(rhs);
	return *this;
}

// __Interfaces__
std::map<std::string, std::string> HostModule::getAllDynData()
{
	map_string_t allDynData;
	allDynData.insert(pair_string_t("None", "None"));
	return allDynData;
}

std::map<std::string, std::string> HostModule::getAllStaticData()
{
	map_string_t allStaticData;
	allStaticData.insert(pair_string_t("username", getData("username")));
	allStaticData.insert(pair_string_t("hostname", getData("hostname")));
	return allStaticData;
}

std::string HostModule::getData(std::string name)
{
	std::string (HostModule::*arrFunc[])(void) =
										{
												&HostModule::_hostnameStatic,
												&HostModule::_usernameStatic,
												&HostModule::_architectureStatic,
												&HostModule::_osTypeStatic,
												&HostModule::_osReleaseStatic,
												&HostModule::_osInfoStatic,
												&HostModule::_dateTimeDyn
										};
	const std::string arrNameFunc[] =	{
											"hostname",
											"username",
											"host_arch",
											"os_type",
											"os_release",
											"os_infos",
											"date_time"
										};
	for (int i = 0; i < 7; i++)
	{
		if (arrNameFunc[i].compare(name) == 0)
			return (this->*arrFunc[i])();
	}
	throw std::runtime_error("HostModule: getData: Invalid Name:" + name);
}

// __Functions__

std::string HostModule::_hostnameStatic(void)
{
	std::string ret = sysctlCall<char[100]>("kern.hostname");
	return ret;
}

std::string HostModule::_usernameStatic(void)
{
	char * login = getlogin();
	if (login == NULL)
		throw std::runtime_error("Login not found");
	return std::string(login);
}

std::string HostModule::_architectureStatic(void)
{
	std::string ret = sysctlCall<char[100]>("hw.machine");
	return ret;
}

std::string HostModule::_osTypeStatic(void)
{
	std::string ret = sysctlCall<char[100]>("kern.ostype");
	return ret;
}

std::string HostModule::_osReleaseStatic(void)
{
	std::string ret = sysctlCall<char[100]>("kern.osrelease");
	return ret;
}

std::string HostModule::_osInfoStatic(void)
{
	std::string ret = sysctlCall<char[1000]>("kern.version");
	return ret;
}

std::string HostModule::_dateTimeDyn(void)
{
	std::string ret = timestamp();
	return ret;
}


// __Tools__
std::string	HostModule::timestamp(void)
{
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];

	time (&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer,80,"%d-%m-%Y %X",timeinfo);
	std::string msg(buffer);
	return (msg);
}
