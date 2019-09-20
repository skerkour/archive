/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1_bltin_cd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 12:10:44 by skerkour          #+#    #+#             */
/*   Updated: 2015/01/04 15:37:04 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "../ft_sh1.h"

static void	sh1_bltin_cd_chdir(char *dir)
{
	struct stat	inf;

	if (lstat(dir, &inf) == -1)
		ft_putstr_fd("cd:cd: no such file or directory: ", FT_STDERR)
			, ft_putendl_fd(dir, FT_STDERR);
	else if (!S_ISDIR(inf.st_mode) && !S_ISLNK(inf.st_mode))
		ft_putstr_fd("cd:cd: not a directory: ", FT_STDERR)
			, ft_putendl_fd(dir, FT_STDERR);
	else if (!(inf.st_mode & S_IXUSR) && !(inf.st_mode & S_IXGRP)
			&& !(inf.st_mode & S_IXOTH))
		ft_putstr_fd("cd:cd: permission denied: ", FT_STDERR)
			, ft_putendl_fd(dir, FT_STDERR);
	else
	{
		if (chdir(dir) == -1)
			ft_putstr_fd("cd:cd: not a directory: ", FT_STDERR)
				, ft_putendl_fd(dir, FT_STDERR);
	}
}

static void	sh1_bltin_cd_gotodir(char ***env, char *dir)
{
	static char	prev[1024];
	static char	actu[1024];
	char		**tmp;

	if (!ft_strcmp(dir, "-") && *prev)
	{
		ft_bzero(actu, 1024), getcwd(actu, 1024);
		sh1_bltin_cd_chdir(prev);
		ft_memcpy(prev, actu, 1024);
	}
	else
	{
		ft_bzero(prev, 1024), getcwd(prev, 1024);
		sh1_bltin_cd_chdir(dir);
	}
	ft_bzero(actu, 1024), getcwd(actu, 1024);
	tmp = (char**)ft_xmalloc(sizeof(char*) * 2);
	tmp[0] = ft_strjoin("PWD=", actu);
	tmp[1] = NULL;
	sh1_bltin_setenv(env, tmp);
	free(tmp[0]);
	free(tmp);
}

static void	sh1_bltin_cd_two(char *arg1, char *arg2)
{
	UNUSED(arg1);
	UNUSED(arg2);
}

void		sh1_bltin_cd(char ***env, char **args)
{
	char	*home;
	t_uint	len;

	len = ft_arrlen(args);
	if (len > 2)
	{
		ft_putendl_fd("cd: too many arguments", FT_STDERR);
		return ;
	}
	else if (len == 2)
		sh1_bltin_cd_two(args[0], args[1]);
	else if (len == 1)
		sh1_bltin_cd_gotodir(env, args[0]);
	else
	{
		if ((home = sh1_getenv(*env, "HOME")))
			sh1_bltin_cd_gotodir(env, home);
	}
}
