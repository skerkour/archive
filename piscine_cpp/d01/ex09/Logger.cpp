/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 09:58:12 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/18 10:41:55 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "Logger.hpp"

Logger::Logger(std::string filename)
{
	_funcs[0] = &Logger::logToConsole;
	_funcs[1] = &Logger::logToFile;

	//_funcs_names[0] = "logToConsole";
	//_funcs_names[1] = "logToFile";

	_file_stream.open(filename, std::ios::out | std::ios::app);
}

Logger::~Logger()
{
	_file_stream.close();
}

// PUBLIC
void	Logger::log(const std::string& dest, const std::string& message)
{
	std::string	log = makeLogEntry(message);
	/*
	int			i = findAction(_funcs_names, dest, 0, 2);

	if (i <= 1) {
		(this->*_funcs[i])(log);
	}
	*/
	(this->*_funcs[dest[0] % 2])(log);
}

// PRIVATE
/*
int	Logger::findAction(std::string* arr, const std::string& str, int start,
	int size)
{
	if (start == size || arr[start] == str)
		return start;
	return findAction(arr, str, start + 1, size);
}
*/
void	Logger::logToConsole(const std::string& str)
{
	std::cout << str << std::endl;
}

void	Logger::logToFile(const std::string& str)
{
	if (!_file_stream.fail())
		_file_stream << str << std::endl;
}

std::string	Logger::makeLogEntry(const std::string& entry)
{
	time_t			t = time(0);
	struct tm*			now = localtime(&t);
	std::stringstream	ss;

	ss << '(' << (now->tm_year + 1900) << '\\'
		<< std::setfill ('0') << std::setw (2) << (now->tm_mon + 1) << '\\'
		<<  now->tm_mday
		<< '-'
		<< now->tm_hour << ':'
		<< now->tm_min << ':'
		<< now->tm_sec << ") " << entry;
	return ss.str();
}
