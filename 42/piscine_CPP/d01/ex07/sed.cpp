/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 20:13:06 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/17 20:07:14 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

namespace sed
{

std::string	searchAndReplace(std::string& line, std::string& s1,
	std::string& s2, size_t start)
{
	std::size_t	pos;

	if ((pos = line.find(s1, start)) == std::string::npos)
		return line;
	line.erase(pos, s1.length());
	line.insert(pos, s2);
	return searchAndReplace(line, s1, s2, pos + s2.length());
}

void	readByLine(std::ifstream& inFile, std::ofstream& outFile,
	std::string& s1, std::string& s2)
{
	std::string	line;

	if (!std::getline(inFile, line)) {
		return ;
	}
	line = searchAndReplace(line, s1, s2, 0);
	outFile << line << std::endl;
	return readByLine(inFile, outFile, s1, s2);
}

}

void	sedify(std::string filename, std::string s1, std::string s2)
{
	std::ifstream	inFile;
	std::ofstream	outFile;

	if (s1.length() == 0 || s2.length() == 0) {
		std::cerr << "Error : s1 and s2 can't be empty." << std::endl;
		return ;
	}
	inFile.open(filename, std::ifstream::in);
	if (inFile.fail()) {
		std::cerr << "Error opening : " << filename
			<< " aborting..." << std::endl;
		return ;
	}

	outFile.open(filename + ".replace",
		std::ofstream::out | std::ofstream::trunc);
	if (outFile.fail()) {
		std::cerr << "Error opening : " << filename << ".replace"
			<< " aborting..." << std::endl;
		inFile.close();
		return ;
	}
	sed::readByLine(inFile, outFile, s1, s2);
	inFile.close();
	outFile.close();
}
