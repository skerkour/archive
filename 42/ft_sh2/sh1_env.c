/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 15:48:12 by skerkour          #+#    #+#             */
/*   Updated: 2015/01/04 15:30:19 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_sh1.h"

void	sh1_env_replace_tield(char **env, char **arg)
{
	char	*home;
	char	*tmp;

	tmp = *arg;
	if ((home = sh1_getenv(env, "HOME")) == NULL)
		*arg = ft_strdup("~");
	else
		*arg = ft_strdup(home);
	*arg = ft_strjoinf(*arg, tmp + 1);
	free(tmp);
}

void	sh1_env_replace(char **env, char **args)
{
	t_uint	i;
	char	*tmp;
	char	*value;

	i = 0;
	while (args[i])
	{
		if (args[i][0] == '$')
		{
			tmp = args[i];
			if ((value = sh1_getenv(env, &(args[i][1]))))
				args[i] = ft_strdup(value);
			else
				args[i] = ft_strdup("");
			free(tmp);
		}
		else if (args[i][0] == '~')
			sh1_env_replace_tield(env, &(args[i]));
		++i;
	}
}

char	*sh1_getenv_name(char *full_var)
{
	char	*ret;
	char	*pos;
	t_uint	i;

	ret = NULL;
	if ((pos = ft_strchr(full_var, '=')))
	{
		i = 0;
		ret = (char*)ft_xmalloc(pos - full_var + 1);
		while (full_var[i] != '=')
		{
			ret[i] = full_var[i];
			++i;
		}
		ret[i] = 0;
	}
	return (ret);
}

char	*sh1_getenv(char **env, char *var)
{
	t_uint	i;
	char	*pos;
	char	tc;

	if (!env)
		return (NULL);
	i = 0;
	while (env[i])
	{
		if ((pos = ft_strchr(env[i], '=')))
		{
			tc = *pos;
			*pos = 0;
			if (!ft_strcmp(var, env[i]))
			{
				*pos = tc;
				return (pos + 1);
			}
			*pos = tc;
			++i;
		}
	}
	return (NULL);
}
