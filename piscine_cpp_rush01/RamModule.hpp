/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 16:33:58 by ybarbier          #+#    #+#             */
/*   Updated: 2015/06/27 16:33:59 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RAM_MODULE_HPP
# define RAM_MODULE_HPP

#include <sys/sysctl.h>
#include <sstream>
#include <stdexcept>

#include "IMonitorModule.hpp"

class RamModule : public IMonitorModule
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
/*
		template<typename U>
		std::string convertToString(U value)
		{
			std::stringstream stream;
			stream << value;
			return stream.str();
		}
*/

	public:
		RamModule(void);
		RamModule(RamModule const & src);
		~RamModule(void);

		RamModule & operator=(RamModule const & rhs);

		// __Interfaces__
		std::map<std::string, std::string> getAllDynData();
		std::map<std::string, std::string> getAllStaticData();
		std::string getData(std::string name);

		std::string test(void);
	private:
		// __Functions__
		// __Static__
		std::string _memsizeStatic(void);

		// __Dynamique__
		std::string _memUsedDyn(void);
		std::string _memFreeDyn(void);

		// __ToolsFunctions__
		long long _memUsed();
		long long _memFree();
};

#endif // END: RAM_MODULE_HPP
