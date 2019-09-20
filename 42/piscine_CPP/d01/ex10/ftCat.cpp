/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftCat.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 19:59:01 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/17 23:02:41 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>

#include "ftCat.hpp"

void	ftCat::readByLine(std::ifstream& inFile)
{
	std::string	line;

	if (!std::getline(inFile, line))
		return ;
	std::cout << line << std::endl;
	return readByLine(inFile);
}

void	ftCat::readFile(std::string filename)
{
	std::ifstream	inFile;

	inFile.open(filename, std::ifstream::in);
	if (inFile.fail()) {
		std::cerr << "cat: filename: No such file or directory"
			<< std::endl;
		return ;
	}
	readByLine(inFile);
	inFile.close();
}

void	ftCat::readFiles(char** files)
{
	if (!*files)
		return;
	readFile(std::string(*files));
	return readFiles(files + 1);
}

void	ftCat::readStandardEntry()
{
	//std::string	line;

	/*
	std::getline(std::cin, line);
	if (std::cin.eof()) {
		std::cout << "EOF" ;
		if (!line.length()) {
			return ;
		}
		std::cout << line;
	} else {
		std::cout << line << std::endl;
	}
	return readStandardEntry();
	*/
	char	c = '\n';
	int		rdret,
			rdret_prev;
	bool	t = true;
	
	while (t) {
		rdret_prev = rdret;
		if (!(rdret = read(0, &c, 1)) && (c == '\n' || rdret_prev == rdret))
			return ;
		write(1, &c, 1);
	}
}
