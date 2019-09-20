/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1_bltin_unsetenv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 16:17:24 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/13 15:15:52 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../ft_sh1.h"

static void	sh1_bltin_unsetenv_usage(void)
{
	ft_putendl_fd("unsetenv: usage: unsetenv varname", FT_STDERR);
}

static void	sh1_bltin_unsetenv_error(void)
{
	ft_putendl_fd("unsetenv: error: argument missing", FT_STDERR);
	sh1_bltin_unsetenv_usage();
}

void		sh1_bltin_unsetenv_cut(char ***env, char *arg)
{
	t_uint	j;
	t_uint	i;
	char	**new;
	char	*name;

	if (sh1_getenv(*env, arg))
	{
		new = (char**)ft_xmalloc(sizeof(char*) * ft_arrlen(*env));
		i = 0;
		j = 0;
		while ((*env)[i])
		{
			name = sh1_getenv_name((*env)[i]);
			if (ft_strcmp(name, arg))
			{
				new[j] = ft_strdup((*env)[i]);
				++j;
			}
			free(name), ++i;
		}
		new[j] = NULL;
		ft_arrcfree(env);
		(*env) = new;
	}
}

void		sh1_bltin_unsetenv(char ***env, char **args)
{
	t_uint	i;

	if (!*args)
	{
		sh1_bltin_unsetenv_error();
		return ;
	}
	else if (!ft_strcmp(*args, "-h") || !ft_strcmp(*args, "--help"))
	{
		sh1_bltin_unsetenv_usage();
		return ;
	}
	else
	{
		i = 0;
		while (args[i])
			sh1_bltin_unsetenv_cut(env, args[i]), ++i;
	}
}
