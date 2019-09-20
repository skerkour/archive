/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 14:55:32 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/21 16:14:48 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "libft.h"
#include "get_next_line.h"

int	main(int ac, char **av)
{
	char	*line;
	int		fds[256];
	char	*lines[256];

	if (ac == 1)
	{
		while (get_next_line(0, &line) > 0)
		{
			puts(line);
			free(line);
		}
	}
	else
	{
		if (ac > 256)
		{
			ft_putendl_fd("Error -- don't try to play with me...", FT_STDERR);
			exit(-42);
		}
		UNUSED(av);
		UNUSED(fds);
		if ((fds[0] = open(av[1], O_RDONLY)) < 0)
		{
			ft_putstr_fd("Error -- can't open the files : ", FT_STDERR);
			ft_putendl_fd(av[1], FT_STDERR);
			exit(-42);
		}
		while (get_next_line(fds[0], &(lines[0])) > 0)
		{
			puts(lines[0]);
			free(lines[0]);
		}
		close(fds[0]);
	}
	return (0);
}
