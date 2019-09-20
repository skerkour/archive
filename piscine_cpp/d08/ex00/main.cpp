/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 11:03:08 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/25 17:49:04 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

#include "easyfind.hpp"

int	main()
{
	std::vector<int> myIntVector;
	myIntVector.push_back(1);
	myIntVector.push_back(4);
	myIntVector.push_back(8);

	std::cout << easyfind(myIntVector, 42) << std::endl;
	std::cout << easyfind(myIntVector, 4) << std::endl;

	return 0;
}
