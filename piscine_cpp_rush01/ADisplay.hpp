/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ADisplay.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 18:29:57 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/28 22:14:15 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADISPLAY_HPP
# define ADISPLAY_HPP

# include <string>
# include <sstream>

# include "IMonitorDisplay.hpp"
# include "CpuModule.hpp"
# include "HostModule.hpp"
# include "RamModule.hpp"
# include "NetModule.hpp"
# include "PonyModule.hpp"

# ifndef SSTR
#  define SSTR( x ) dynamic_cast< std::ostringstream & >( \
		        ( std::ostringstream() << std::dec << x ) ).str()
# endif
class ADisplay : public IMonitorDisplay
{
public:
	ADisplay();
	ADisplay(const ADisplay& src);
	~ADisplay();

	ADisplay& operator=(const ADisplay& rhs);

	virtual void	setData(IMonitorModule& module);
	virtual void	setStaticData(IMonitorModule& module);

protected:
	virtual void	_setCpuData(CpuModule& cpu);
	virtual void	_setHostData(HostModule& os);
	virtual void	_setRamData(RamModule& ram);
	virtual void	_setNetData(NetModule& net);
	virtual void	_setPonyData(PonyModule& pony);
	virtual void	_setStaticCpuData(CpuModule& cpu);
	virtual void	_setStaticHostData(HostModule& os);
	virtual void	_setStaticRamData(RamModule& ram);
	virtual void	_setStaticNetData(NetModule& net);
	
	virtual void	_refreshCpuData() = 0;
	virtual void	_refreshHostData() = 0;
	virtual void	_refreshNetworkData() = 0;
	virtual void	_refreshRamData() = 0;

	std::string		_hostname,
					_username,
					_os_infos,
					_date_time,
					_cpu_model,
					_pony,
					_net_interface_en0,
					_net_interface_lo0;
	long*			_cores_load;
	unsigned long	_n_cores,
					_ram_amout,
					_ram_used,
					_ram_free,
					_ram_perc,
					_net_n_ifaces,
					_net_pkts_in,
					_net_pkts_out,
					_net_data_in,
					_net_data_out;
};

#endif // ADISPLAY_HPP
