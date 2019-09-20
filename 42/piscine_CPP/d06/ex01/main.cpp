/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 19:36:17 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/23 20:23:45 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

struct Data {
	std::string	s1;
	int			n;
	std::string	s2;
};


void*	serialize()
{
	static char charset[] =
		"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

	Data	*ret = new Data;
	for (int i = 0; i < 8; ++i) {
		ret->s1 += charset[rand() % sizeof(charset)];
	}
	ret->n = rand() * (rand() & 1 ? 1 : -1);
	for (int i = 0; i < 8; ++i) {
		ret->s2 += charset[rand() % sizeof(charset)];
	}
	return ret;
}

Data*	deserialize(void* raw)
{
	Data*	ret = reinterpret_cast<Data*>(raw);
	return ret;
}

int	main()
{
	srand(time(0));
	void	*s = serialize();
	Data*	d = deserialize(s);
	std::cout << d->s1 << std::endl << d->n << std::endl << d->s2 << std::endl;
	delete d;
	return 0;
}
