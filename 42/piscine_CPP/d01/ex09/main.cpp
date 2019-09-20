/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 09:58:31 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/18 10:41:07 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

int	main()
{
	Logger	logger("log.txt");

	logger.log("1", "yo");
	logger.log("1", "yoyfewfewfewfwefewfoyoyoyoyolol");
	logger.log("0", "salut");
	logger.log("0", "les");
	logger.log("0", "gens");
	return 0;
}
