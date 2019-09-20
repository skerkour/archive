/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 11:43:40 by skerkour          #+#    #+#             */
/*   Updated: 2014/12/03 11:48:39 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	char pass[] = "monsuperPASS";
	if (ac != 2)
		printf("usage:\n%s <password>\n", av[0]), exit(1);
	if (!strcmp(av[1], pass))
		puts("GG YOU WIN");
	else
		puts("NOOOOB !");
	return (0);
}
