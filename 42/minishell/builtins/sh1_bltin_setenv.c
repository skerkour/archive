/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1_bltin_setenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 16:16:44 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/08 17:52:31 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../ft_sh1.h"

static void	sh1_bltin_setenv_usage(void)
{
	ft_putendl_fd("setenv: usage: setenv [name=value]", FT_STDERR);
}

static void	sh1_bltin_setenv_error(void)
{
	ft_putendl_fd("setenv: error: argument missing", FT_STDERR);
	sh1_bltin_setenv_usage();
}

static void	sh1_bltin_setenv_cut_newenv(char ***env, char *arg)
{
	char	**new;
	t_uint	i;

	new = (char**)ft_xmalloc(sizeof(char*) * (ft_arrlen(*env) + 2));
	i = 0;
	while ((*env)[i])
	{
		new[i] = ft_strdup((*env)[i]);
		++i;
	}
	new[i++] = ft_strdup(arg);
	new[i] = NULL;
	ft_arrcfree(env);
	(*env) = new;
}

void		sh1_bltin_setenv_one(char ***env, char *arg, char *pos, char *name)
{
	char	*env_found;
	char	*tname;
	t_uint	i;

	if ((pos = ft_strchr(arg, '=')))
	{
		name = sh1_getenv_name(arg);
		env_found = sh1_getenv(*env, name);
		if (env_found && !(i = 0))
			while ((*env)[i])
			{
				tname = sh1_getenv_name((*env)[i]);
				if (!ft_strcmp(tname, name))
				{
					free((*env)[i]), (*env)[i] = ft_strdup(arg), free(tname);
					break ;
				}
				free(tname), ++i;
			}
		else
			sh1_bltin_setenv_cut_newenv(env, arg);
		free(name);
	}
	else
		sh1_bltin_setenv_usage();
}

void		sh1_bltin_setenv(char ***env, char **args)
{
	t_uint	i;

	if (!*args)
	{
		sh1_bltin_setenv_error();
		return ;
	}
	else if (!ft_strcmp(*args, "-h") || !ft_strcmp(*args, "--help"))
	{
		sh1_bltin_setenv_usage();
		return ;
	}
	else
	{
		i = 0;
		while (args[i])
			sh1_bltin_setenv_one(env, args[i++], NULL, NULL);
	}
}
