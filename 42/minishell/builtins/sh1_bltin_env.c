/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1_bltin_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 16:17:39 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/08 17:51:47 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../ft_sh1.h"

static void	sh1_bltin_env_xcute(char **args, char **env, char **tmp_env)
{
	int		tmp;
	char	*path;

	tmp = sh1_isxcut_relative(args[0]);
	if (tmp == 1)
		sh1_xcute_relative(args[0], &(args[0]), tmp_env);
	else if (tmp == 0)
		ft_putendl_fd("not a file : ", 2), ft_putendl_fd(args[0], 2);
	else if (tmp == -1)
	{
		if ((path = sh1_search_cmd_path(args[0], env)) == NULL)
		{
			ft_putstr_fd("ft_minishell1: command not found: ", FT_STDERR);
			ft_putendl_fd(args[0], FT_STDERR);
			return ;
		}
		sh1_xcute_relative(path, args, tmp_env);
		free(path);
	}
}

static char	**sh1_bltin_env_new_empty_env(void)
{
	char	**ret;

	ret = (char**)ft_xmalloc(sizeof(char*));
	ret[0] = NULL;
	return (ret);
}

void		sh1_bltin_env(char ***env, char **arg)
{
	t_uint	i;
	char	**tmp_env;

	tmp_env = ft_arrccpy(*env);
	i = 0;
	if (arg[i] && !ft_strcmp(arg[i], "-i"))
		ft_arrcfree(&tmp_env), tmp_env = sh1_bltin_env_new_empty_env(), ++i;
	while (arg[i] && ft_strchr(arg[i], '='))
		sh1_bltin_setenv_one(&tmp_env, arg[i], NULL, NULL), ++i;
	if (arg[i])
		sh1_bltin_env_xcute(&(arg[i]), *env, tmp_env);
	else
	{
		i = 0;
		while (tmp_env[i])
			ft_putendl(tmp_env[i++]);
	}
	ft_arrcfree(&tmp_env);
}
