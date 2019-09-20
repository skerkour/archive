/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 09:58:29 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/18 10:41:33 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
# define LOGGER_HPP

#include <fstream>
#include <string>

class Logger
{
	typedef void (Logger::*LoggerMethodFPointer)(const std::string&);

public:
	Logger(std::string filename);
	~Logger();

	void	log(const std::string& dest, const std::string& message);

private:
	//int			findAction(std::string* arr, const std::string& str, int start, int size);
	void		logToConsole(const std::string& str);
	void		logToFile(const std::string& str);
	std::string	makeLogEntry(const std::string& entry);

	std::string				_filename;
	LoggerMethodFPointer	_funcs[2];
	//std::string				_funcs_names[2];
	std::ofstream			_file_stream;
};

#endif
