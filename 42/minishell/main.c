/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 16:20:21 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/08 17:56:42 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "ft_sh1.h"

char	***g_env;

void	sh1_main_loop(char ***env)
{
	char	*header;
	char	*cmd;

	if (!isatty(fileno(stdin)) || !(**env))
		while (42)
		{
			if ((header = sh1_get_header(*env)))
				ft_putstr(header);
			if (ft_gnl(0, &cmd) <= 0)
			{
				free(header);
				ft_exit(0);
			}
			sh1_parse_cmdl_comma(cmd, env), free(cmd), free(header);
		}
	else
	{
		while (42)
		{
			header = sh1_get_header(*env);
			cmd = ft_readline(header);
			sh1_parse_cmdl_comma(cmd, env), free(cmd), free(header);
		}
	}
}

int		main(int ac, char **av, char **env_orig)
{
	char	**env;

	UNUSED(ac), UNUSED(av), sh1_set_signals_hook(), env = ft_arrccpy(env_orig);
	g_env = &env;
	sh1_main_loop(&env);
	return (0);
}
