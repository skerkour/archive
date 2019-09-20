/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CpuModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 20:31:43 by ybarbier          #+#    #+#             */
/*   Updated: 2015/06/27 20:31:44 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_MODULE
# define CPU_MODULE

#include <sys/sysctl.h>
#include <sstream>
#include <stdexcept>
#include <mach/mach.h>
#include <unistd.h>
#include <mach/processor_info.h>
#include <mach/mach_host.h>

#include "IMonitorModule.hpp"

#if defined(__APPLE__) && defined(__MACH__)
  #define CP_USER 0
  #define CP_SYS  1
  #define CP_IDLE 2
  #define CP_NICE 3
  #define CP_STATES 4
#endif

class CpuModule : public IMonitorModule
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
		CpuModule(void);
		CpuModule(CpuModule const & src);
		~CpuModule(void);

		CpuModule & operator=(CpuModule const & rhs);

		// __Interfaces__
		std::map<std::string, std::string> getAllDynData();
		std::map<std::string, std::string> getAllStaticData();
		std::string getData(std::string name);

	private:
		// __Functions__
		// __Static__
		std::string _modelCpuStatic(void);
		std::string _numberCpuCoreStatic(void);

		// __Dynamique__
		std::string _loadCpuCore0Dyn(void);
		std::string _loadCpuCore1Dyn(void);
		std::string _loadCpuCore2Dyn(void);
		std::string _loadCpuCore3Dyn(void);

		//__Tool__
		struct Ticks {
			unsigned long long int usertime;
			unsigned long long int nicetime;
			unsigned long long int systemtime;
			unsigned long long int idletime;

			unsigned long long int used() { return usertime + nicetime + systemtime; }
			unsigned long long int total() { return usertime + nicetime + systemtime + idletime; }
		} prev[4];

		Ticks updated_ticks_(int core);
		float get(int core);

		uint8_t		get_cpu_count();
		host_cpu_load_info_data_t get_cpu_percentage();
		float		cpu_percentage(unsigned int cpu_usage_delay);

};

#endif // END: CPU_MODULE
