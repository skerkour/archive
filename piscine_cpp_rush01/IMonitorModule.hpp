/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 15:24:44 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/27 16:16:58 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

# include <map>
# include <string>

class IMonitorModule
{
public:
	virtual ~IMonitorModule() {}

	virtual std::map<std::string, std::string>	getAllDynData() = 0;
	virtual std::map<std::string, std::string>	getAllStaticData() = 0;
	virtual std::string							getData(std::string name) = 0;
};

#endif // IMONITORMODULE_HPP
