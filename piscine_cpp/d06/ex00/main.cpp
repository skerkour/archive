/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 19:10:14 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/24 14:58:28 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

int		main(int ac, char **av)
{
	if (ac >= 2)
	{
		int 		flag;
		int 		len;
		double		nb;

		for (int i = 1; i < ac; i++)
		{
			flag = 0;
			for (int j = 0; av[i][j]; j++)
				flag += isalpha(av[i][j]);
			nb = atof(av[i]);
			len = strlen(av[i]);
			if (flag <= 1 && len >= 1 && isdigit(av[i][0])) {
				if (isprint(nb))
					std::cout << "char   : '" << static_cast<char>(nb)
						<< "'" << std::endl;
				else
					std::cout << "char   : " << "Non displayable" << std::endl;

				std::cout << "int    : " << static_cast<int>(nb) << std::endl;
				std::cout << "float  : " << std::fixed << std::setprecision(1)
					<< static_cast<float>(nb) << "f" << std::endl;
				std::cout << "double : " << static_cast<double>(nb)
					<< std::endl;
			} else if (len == 1) {
				std::cout << "char   : '" << av[i] << "'" << std::endl;
				std::cout << "int    : " << static_cast<int>(av[i][0])
					<< std::endl;
				std::cout << "float  : " << std::fixed << std::setprecision(1)
					<< static_cast<float>(av[i][0]) << "f" << std::endl;
				std::cout << "double : " << static_cast<double>(av[i][0])
					<< std::endl;
			} else {
				std::cout << "char   : Impossible" << std::endl;
				std::cout << "int    : Impossible" << std::endl;
				std::cout << "float  : " << av[i] << "f" << std::endl;
				std::cout << "double : " << av[i] << std::endl;
			}
			if (i < ac - 1)
				std::cout << std::endl;
		}
	}

	return 0;
}
