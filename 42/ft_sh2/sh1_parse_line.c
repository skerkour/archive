/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1_parse_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 17:27:12 by skerkour          #+#    #+#             */
/*   Updated: 2015/07/18 16:33:19 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_sh1.h"

void	sh1_switch_cmd(char *cmd, char **args, char *line, char ***env)
{
	int	tmp;

	if (!ft_strcmp(cmd, "cd"))
		sh1_bltin_cd(env, &(args[1]));
	else if (!ft_strcmp(cmd, "exit"))
		sh1_bltin_exit(args[1]);
	else if (!ft_strcmp(cmd, "env"))
		sh1_bltin_env(env, &(args[1]));
	else if (!ft_strcmp(cmd, "setenv") || !ft_strcmp(cmd, "export"))
		sh1_bltin_setenv(env, &(args[1]));
	else if (!ft_strcmp(cmd, "unsetenv"))
		sh1_bltin_unsetenv(env, &(args[1]));
	else if ((tmp = sh1_isxcut_relative(cmd)) == 1
			&& !sh1_extern_exist(cmd, *env))
		sh1_xcute_relative(cmd, args, *env);
	else if (tmp == 0 && !sh1_extern_exist(cmd, *env))
		sh1_bltin_cd(env, &cmd);
	else
		sh1_xcute_extern(cmd, args, *env);
	UNUSED(line);
}

void	sh1_parse_cmdl_comma(char *line, char ***env)
{
	char	**args;
	t_uint	i;

	args = ft_strsplit(line, ';');
	if (!args || !*args)
	{
		if (!args)
			return ;
		free(args);
		return ;
	}
	i = 0;
	while (args[i])
		sh1_parse_cmdl(args[i], env), free(args[i++]);
	free(args[i]);
	free(args);
}

void	sh1_parse_cmdl(char *line, char ***env)
{
	char	*cmd;
	char	**args;
	t_uint	i;

	args = ft_strsplit(line, ' ');
	if (!*args)
		return ;
	sh1_env_replace(*env, args);
	cmd = args[0];
	sh1_switch_cmd(cmd, args, line, env);
	i = 0;
	while (args[i])
		ft_putstr(args[i]), free(args[i++]);
	free(args[i]);
	free(args);
}
