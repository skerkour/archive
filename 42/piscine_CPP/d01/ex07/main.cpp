/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 19:48:53 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/16 21:00:11 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void	sedify(std::string filename, std::string s1, std::string s2);

void	usage(std::string name)
{
	std::cout << "usage :" << std:: endl
		<< "-------" << std::endl
		<< name << " <filename> <string to replace> <replace string>" << std::endl;
}

int	main(int ac, char **av)
{
	if (ac == 4) {
		sedify(std::string(av[1]), std::string(av[2]), std::string(av[3]));
	} else {
		usage(std::string(av[0]));
	}
	return 0;
}
