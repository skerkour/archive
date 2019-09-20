/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ADisplay.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 18:30:08 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/28 22:24:31 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <stdexcept>
#include <string>

#include "ADisplay.hpp"

ADisplay::ADisplay() : _cores_load(NULL), _n_cores(0),
	_ram_amout(0), _ram_used(0)
{
}

ADisplay::ADisplay(const ADisplay& src)
{
	*this = src;
}

ADisplay::~ADisplay()
{
	if (_cores_load)
		delete[] _cores_load;
}

ADisplay& ADisplay::operator=(const ADisplay& rhs)
{
	static_cast<void>(rhs);
	return *this;
}

void ADisplay::setData(IMonitorModule& module)
{
	try {
		CpuModule& cpu = dynamic_cast<CpuModule&>(module);
		_setCpuData(cpu);
	} catch (std::exception& e) {
		if (std::string(e.what()) != "std::bad_cast")
			throw std::runtime_error(e.what());
	}

	try {
		RamModule&	ram = dynamic_cast<RamModule&>(module);
		_setRamData(ram);
	} catch (std::exception& e) {
		if (std::string(e.what()) != "std::bad_cast")
			throw std::runtime_error(e.what());
	}
	try {
		HostModule&	os = dynamic_cast<HostModule&>(module);
		_setHostData(os);
	} catch (std::exception& e) {
		if (std::string(e.what()) != "std::bad_cast")
			throw std::runtime_error(e.what());
	}

	try {
		NetModule& net = dynamic_cast<NetModule&>(module);
		_setNetData(net);
	} catch (std::exception& e) {
		if (std::string(e.what()) != "std::bad_cast")
			throw std::runtime_error(e.what());
	}
	
	try {
		PonyModule& pony = dynamic_cast<PonyModule&>(module);
		_setPonyData(pony);
	} catch (std::exception& e) {
		if (std::string(e.what()) != "std::bad_cast")
			throw std::runtime_error(e.what());
	}
}

void	ADisplay::setStaticData(IMonitorModule& module)
{
	try {
		CpuModule&	cpu = dynamic_cast<CpuModule&>(module);
		_setStaticCpuData(cpu);
	} catch (std::exception& e) {
		if (std::string(e.what()) != "std::bad_cast")
			throw std::runtime_error(e.what());
	}

	try {
		RamModule&	ram = dynamic_cast<RamModule&>(module);
		_setStaticRamData(ram);
	} catch (std::exception& e) {
		if (std::string(e.what()) != "std::bad_cast")
			throw std::runtime_error(e.what());
	}

	try {
		HostModule&	os = dynamic_cast<HostModule&>(module);
		_setStaticHostData(os);
	} catch (std::exception& e) {
		if (std::string(e.what()) != "std::bad_cast")
			throw std::runtime_error(e.what());
	}

	try {
		NetModule& net = dynamic_cast<NetModule&>(module);
		_setStaticNetData(net);
	} catch (std::exception& e) {
		if (std::string(e.what()) != "std::bad_cast")
			throw std::runtime_error(e.what());
	}
}

void	ADisplay::_setCpuData(CpuModule& cpu)
{
	//_cpu_load_core = atol(cpu.getData("cpu_load_core").c_str());
	if (_cores_load) {
		for (unsigned long i = 0; i < _n_cores; ++i) {
			_cores_load[i] = atol(cpu.getData("cpu_load_core"
				+ SSTR(i)).c_str());
		}
	}
}

void	ADisplay::_setHostData(HostModule& os)
{
	_os_infos = os.getData("os_infos");
	_date_time = os.getData("date_time");
}

void	ADisplay::_setRamData(RamModule& ram)
{
	_ram_used = strtoul(ram.getData("ram_used").c_str(), NULL, 0);
	//_ram_free = strtoul(ram.getData("ram_free").c_str(), NULL, 0);
	_ram_free = _ram_amout - _ram_used;
	_ram_perc = static_cast<unsigned long>((
			static_cast<double>(static_cast<double>(_ram_used) / static_cast<double>(_ram_amout)))
			* 100);
}

void	ADisplay::_setNetData(NetModule& net)
{
	_net_n_ifaces = strtoul(net.getData("net_n_ifaces").c_str(), NULL, 0);
	_net_pkts_in = strtoul(net.getData("net_pkts_in").c_str(), NULL, 0);
	_net_pkts_out = strtoul(net.getData("net_pkts_out").c_str(), NULL, 0);
	_net_data_in = strtoul(net.getData("net_data_in").c_str(), NULL, 0);
	_net_data_out = strtoul(net.getData("net_data_out").c_str(), NULL, 0);
	_net_interface_en0 = net.getData("net_interface_en0");
	_net_interface_lo0 = net.getData("net_interface_lo0");
}

void	ADisplay::_setPonyData(PonyModule& pony)
{
	_pony = pony.getData("pony");
}

void	ADisplay::_setStaticCpuData(CpuModule& cpu)
{
	_n_cores = strtoul(cpu.getData("cpu_n_cores").c_str(), NULL, 0);
	_cpu_model = cpu.getData("cpu_model");
	_cores_load = new long[_n_cores];
}

void	ADisplay::_setStaticHostData(HostModule& os)
{
	_hostname = os.getData("hostname");
	_username = os.getData("username");
}

void	ADisplay::_setStaticRamData(RamModule& ram)
{
	_ram_amout = strtoul(ram.getData("ram_amount").c_str(), NULL, 0);
}

void	ADisplay::_setStaticNetData(NetModule& net)
{
	_net_n_ifaces = strtoul(net.getData("net_n_ifaces").c_str(), NULL, 0);
}
