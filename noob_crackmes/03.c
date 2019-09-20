/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 14:03:40 by skerkour          #+#    #+#             */
/*   Updated: 2014/12/03 14:19:08 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void	decipher_pass(char *str)
{
	char	i = 0;

	while (*str)
		*str++ ^= (0x42 + i++);
}

int		main(int ac, char **av)
{
	char	cpass[] = "*\"'.\x19&$%\x15?$(\x11;88<4'";
	
	if (ac != 2)
		printf("usage:\n%s <password>\n", av[0]), exit(1);
	decipher_pass(cpass);
	if (!strcmp(av[1], cpass))
		puts("GG YOU WIN");
	else
		puts("NOOOOB !");
	return (0);
}
