/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 19:13:51 by ybarbier          #+#    #+#             */
/*   Updated: 2015/06/27 19:13:52 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOST_MODULE_HPP
# define HOST_MODULE_HPP

#include <sys/sysctl.h>
#include <sstream>
#include <unistd.h>
#include <stdexcept>

#include "IMonitorModule.hpp"

class HostModule : public IMonitorModule
{
	private:
		typedef std::map<std::string, std::string> map_string_t;
		typedef std::pair<std::string, std::string> pair_string_t;

		template<typename T>
		std::string sysctlCall(std::string instructionName)
		{
			std::stringstream stream;

			T value;

			size_t len = sizeof(value);
			sysctlbyname(instructionName.c_str(), &value, &len, NULL, 0);

			stream << value;
			return stream.str();
		}

	public:
		HostModule(void);
		HostModule(HostModule const & src);
		~HostModule(void);

		HostModule & operator=(HostModule const & rhs);

		// __Interfaces__
		std::map<std::string, std::string> getAllDynData();
		std::map<std::string, std::string> getAllStaticData();
		std::string getData(std::string name);

	private:
		// __Functions__
		// __Static__
		std::string _hostnameStatic(void);
		std::string _usernameStatic(void);
		std::string _architectureStatic(void);
		std::string _osTypeStatic(void);
		std::string _osReleaseStatic(void);
		std::string _osInfoStatic(void);

		// __Dynamique__
		std::string _dateTimeDyn(void);

		// __Tools__
		std::string	timestamp(void);


};

#endif // END: HOST_MODULE_HPP
