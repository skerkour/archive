/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CpuModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 20:31:40 by ybarbier          #+#    #+#             */
/*   Updated: 2015/06/28 15:28:00 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CpuModule.hpp"

CpuModule::CpuModule(void)
{
	prev[0] = updated_ticks_(0);
	prev[1] = updated_ticks_(1);
	prev[2] = updated_ticks_(2);
	prev[3] = updated_ticks_(3);
	usleep(1000000);
	return;
}

CpuModule::CpuModule(CpuModule const & src)
{
	*this = src;
	return;
}

CpuModule::~CpuModule(void)
{
	return;
}

CpuModule & CpuModule::operator=(CpuModule const & rhs)
{
	static_cast<void>(rhs);
	return *this;
}

// __Interfaces__
std::map<std::string, std::string> CpuModule::getAllDynData()
{
	map_string_t allDynData;
	allDynData.insert(pair_string_t("None", "None"));
	return allDynData;
}

std::map<std::string, std::string> CpuModule::getAllStaticData()
{
	map_string_t allStaticData;
	allStaticData.insert(pair_string_t("None", "None"));
	return allStaticData;
}

std::string CpuModule::getData(std::string name)
{
	std::string (CpuModule::*arrFunc[])(void) =
										{
												&CpuModule::_modelCpuStatic,
												&CpuModule::_numberCpuCoreStatic,
												&CpuModule::_loadCpuCore0Dyn,
												&CpuModule::_loadCpuCore1Dyn,
												&CpuModule::_loadCpuCore2Dyn,
												&CpuModule::_loadCpuCore3Dyn,
										};
	const std::string arrNameFunc[] =	{
											"cpu_model",
											"cpu_n_cores",
											"cpu_load_core0",
											"cpu_load_core1",
											"cpu_load_core2",
											"cpu_load_core3",
										};
	for (int i = 0; i < 6; i++)
	{
		if (arrNameFunc[i].compare(name) == 0)
			return (this->*arrFunc[i])();
	}
	throw std::runtime_error("CpuModule: getData: Name invalid.");
}

// __Functions__

std::string CpuModule::_modelCpuStatic(void)
{
	std::string ret = sysctlCall<char[500]>("machdep.cpu.brand_string");
	return ret;
}

std::string CpuModule::_numberCpuCoreStatic(void)
{
	std::string ret = sysctlCall<int32_t>("hw.ncpu");
	return ret;
}

std::string CpuModule::_loadCpuCore0Dyn(void)
{
	std::stringstream stream;
	float total = CpuModule::get(0);
	stream << total;
	return stream.str();
}

std::string CpuModule::_loadCpuCore1Dyn(void)
{
	std::stringstream stream;
	float total = CpuModule::get(1);
	stream << total;
	return stream.str();
}

std::string CpuModule::_loadCpuCore2Dyn(void)
{
	std::stringstream stream;
	float total = CpuModule::get(2);
	stream << total;
	return stream.str();
}

std::string CpuModule::_loadCpuCore3Dyn(void)
{
	std::stringstream stream;
	float total = CpuModule::get(3);
	stream << total;
	return stream.str();
}

// __Tools__
CpuModule::Ticks CpuModule::updated_ticks_(int core) {
	unsigned int cpu_count;
	processor_cpu_load_info_t cpu_load;
	mach_msg_type_number_t cpu_msg_count;

	int rc =  host_processor_info(
		mach_host_self( ),
		PROCESSOR_CPU_LOAD_INFO,
		&cpu_count,
		(processor_info_array_t *) &cpu_load,
		&cpu_msg_count
	);
	if (rc != 0)
		throw std::runtime_error("Error: failed to scan processor info");

	if (static_cast<int>(core) < 0 || static_cast<int>(cpu_count) <= core)
		throw std::runtime_error("Error: invalid core number");
	unsigned long long int usertime = cpu_load[core].cpu_ticks[CPU_STATE_USER];
	unsigned long long int nicetime = cpu_load[core].cpu_ticks[CPU_STATE_NICE];
	unsigned long long int systemtime = cpu_load[core].cpu_ticks[CPU_STATE_SYSTEM];
	unsigned long long int idletime = cpu_load[core].cpu_ticks[CPU_STATE_IDLE];

	Ticks t = {usertime, nicetime, systemtime, idletime};
	return t;
}

float CpuModule::get(int core)
{
	Ticks t = updated_ticks_(core);
	unsigned long long int used = t.used() - prev[core].used();
	unsigned long long int total = t.total() - prev[core].total();
	prev[core] = t;
	return (float)used / (float)total * 100.0f;
}
