/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 11:03:10 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/25 17:54:36 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iterator>

template<class T>
bool	easyfind(T& cont, int x)
{
	typename T::iterator	it;

	for (it = cont.begin(); it != cont.end(); it++) {
		if (*it == x)
			return true;
	}
	return false;
}

#endif // EASYFIND_HPP
