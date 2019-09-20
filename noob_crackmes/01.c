/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 10:47:42 by skerkour          #+#    #+#             */
/*   Updated: 2014/12/03 12:00:37 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	char *s;
	if (ac != 2)
		printf("usage:\n%s <password>\n", av[0]), exit(1);
	s = av[1];
	if (s[0] == 's' && *s)
		if (s[1] == 'a' && *s)
			if (s[2] == 'l' && *s)
				if (s[3] == 'u' && *s)
					if (s[4] == 't' && *s)
						if (s[5] == ' ' && *s)
							if (s[6] == '=' && *s)
								if (s[7] == ')' && *s)
									puts("GG, you WIN !"), exit(0);

	puts("NOOOOB !");
	return (1);
}
