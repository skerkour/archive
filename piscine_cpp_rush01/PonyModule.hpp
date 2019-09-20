/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PonyModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 17:38:48 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/28 17:46:08 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONYMODULE_HPP
# define PONYMODULE_HPP

# include <string>
# include <map>

# include "IMonitorModule.hpp"

class PonyModule : public IMonitorModule
{
private:
	typedef std::map<std::string, std::string> map_string_t;
	typedef std::pair<std::string, std::string> pair_string_t;

public:
	PonyModule();
	PonyModule(const PonyModule& src);
	~PonyModule();

	PonyModule& operator=(const PonyModule& rhs);

	virtual	std::map<std::string, std::string>	getAllDynData();
	virtual	std::map<std::string, std::string>	getAllStaticData();
	virtual	std::string							getData(std::string name);

private:
	std::string	_getPony();
};

#endif // PONYMODULE_HPP
