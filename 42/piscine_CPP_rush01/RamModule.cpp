/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 17:50:46 by ybarbier          #+#    #+#             */
/*   Updated: 2015/06/27 17:50:47 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RamModule.hpp"
#include <mach/vm_statistics.h>
#include <mach/mach_types.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>

RamModule::RamModule(void)
{
	return;
}

RamModule::RamModule(RamModule const & src)
{
	*this = src;
	return;
}

RamModule::~RamModule(void)
{
	return;
}

RamModule & RamModule::operator=(RamModule const & rhs)
{
	static_cast<void>(rhs);
	return *this;
}

// __Interfaces__
std::map<std::string, std::string> RamModule::getAllDynData()
{
	map_string_t allDynData;
	allDynData.insert(pair_string_t("Memsize", "1234"));
	return allDynData;
}

std::map<std::string, std::string> RamModule::getAllStaticData()
{
	map_string_t allStaticData;
	allStaticData.insert(pair_string_t("Memsize", "1234"));
	return allStaticData;
}

std::string RamModule::getData(std::string name)
{
	std::string (RamModule::*arrFunc[])(void) =
										{
												&RamModule::_memsizeStatic,
												&RamModule::_memUsedDyn,
												&RamModule::_memFreeDyn
										};
	const std::string arrNameFunc[] =	{
											"ram_amount",
											"ram_used",
											"ram_free"
										};
	for (int i = 0; i < 3; i++)
	{
		if (arrNameFunc[i].compare(name) == 0)
			return (this->*arrFunc[i])();
	}
	throw std::runtime_error("RamModule: getData: Invalid Name:" + name);
}

// __Functions__

std::string RamModule::_memsizeStatic(void)
{
	std::string ret = sysctlCall<int64_t>("hw.memsize");
	return ret;
}

std::string RamModule::_memUsedDyn(void)
{
	std::stringstream stream;
	stream << _memUsed();
	return stream.str();

}

std::string RamModule::_memFreeDyn(void)
{
	std::stringstream stream;
	stream << _memFree();
	return stream.str();

}

std::string RamModule::test(void)
{

	// std::cout << Usage();
	std::string ret = sysctlCall<int>("vmstat.free_count");


	std::stringstream stream;

	// stream << memUsed() / (1024 ^ 3);
	// std::cout << static_cast<float>(memUsed() / (1024 ^ 3)) << std::endl;
	return stream.str();

	// return ret;
}

// __ToolFunctions__

long long RamModule::_memUsed()
{
	vm_size_t page_size;
	mach_port_t mach_port;
	mach_msg_type_number_t count;
	vm_statistics64_data_t vm_stats;

	mach_port = mach_host_self();
	count = sizeof(vm_stats) / sizeof(natural_t);
	if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
		KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO,
		(host_info64_t)&vm_stats, &count))
	{

		long long used_memory = ((int64_t)vm_stats.active_count +
								(int64_t)vm_stats.inactive_count +
								(int64_t)vm_stats.wire_count) *  (int64_t)page_size;
		return used_memory;
	}
	return 0;
}

long long RamModule::_memFree()
{
	vm_size_t page_size;
	mach_port_t mach_port;
	mach_msg_type_number_t count;
	vm_statistics64_data_t vm_stats;

	mach_port = mach_host_self();
	count = sizeof(vm_stats) / sizeof(natural_t);
	if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
		KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO,
		(host_info64_t)&vm_stats, &count))
	{
		long long free_memory = (int64_t)vm_stats.free_count * (int64_t)page_size;
		return free_memory;
	}
	return 0;
}
