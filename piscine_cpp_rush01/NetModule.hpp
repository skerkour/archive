/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 14:05:05 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/28 16:52:00 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETMODULE_HPP
# define NETMODULE_HPP

# include "IMonitorModule.hpp"

#include <stdio.h>

/*
 * Data that you can grab :
 * - net_n_ifaces
 * - net_pkts_in
 * - net_pkts_out
 * - net_data_in
 * - net_data_out
 * - net_interface_en0
 * - net_interface_lo0
 */

class NetModule : public IMonitorModule
{
	private:
		typedef std::map<std::string, std::string> map_string_t;
		typedef std::pair<std::string, std::string> pair_string_t;


	public:
		NetModule();
		NetModule(const NetModule& src);
		~NetModule();

		NetModule& operator=(const NetModule& rhs);

		virtual	std::map<std::string, std::string>	getAllDynData();
		virtual	std::map<std::string, std::string>	getAllStaticData();
		virtual	std::string							getData(std::string name);

	private:
		std::string	_getNIfaces();

		//__Functions__
		//__Static__

		//__Dynamique__
		std::string _pktsInt(void);
		std::string _pktsOut(void);
		std::string _dataIn(void);
		std::string _dataOut(void);

		std::string _en0Interface(void);
		std::string _lo0Interface(void);
		//__Tools__
		std::string _parseNetwork(std::string cmd);

};

#endif // NETMODULE_HPP
