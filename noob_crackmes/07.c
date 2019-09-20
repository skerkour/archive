/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 11:47:40 by skerkour          #+#    #+#             */
/*   Updated: 2014/12/03 11:47:42 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int check_len(char *str)
{
	int	len = 0;

	while (*str)
		++str, ++len;
	return (len == 0x20 ? 1 : 0);
}

int checksum(char *str)
{
	int	sum = 0;

	while (*str)
		sum += *str++;
	return (sum == 0xb42 ? 1 : 0);
}

int main(int ac, char **av)
{
	if (ac != 2)
		printf("usage:\n%s [serial key]\n", av[0]), exit(1);
	if (check_len(av[1]) && checksum(av[1]))
		puts("GG, the key is valid !"), exit(0);
	puts("the serial key is not valid");
	return (0);
}
