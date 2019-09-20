/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 10:33:42 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/15 11:21:06 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void	cstrToUpper(char *str)
{
	if (*str) {
		*str = toupper(*str);
		return cstrToUpper(str + 1);
	}
}

void	printAv(char **av)
{
	if (*av) {
		cstrToUpper(*av);
		std::cout << *av;
		return printAv(av + 1);
	} else {
		std::cout << std::endl;
	}
}

int		main(int ac, char **av)
{
	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	} else {
		printAv(av + 1);
	}
	return 0;
}
