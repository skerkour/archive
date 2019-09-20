/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 11:28:35 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/17 20:15:19 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftCat.hpp"

int	main(int ac, char **av)
{
	if (ac == 1) { // read on standard entry
		ftCat::readStandardEntry();
	} else { // read files
		ftCat::readFiles(&av[1]);
	}
	return 0;
}
