/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1_xcute.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 14:22:58 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/19 13:52:07 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#include "ft_sh1.h"

int		sh1_isxcut_relative(char *path)
{
	struct stat	infos;
	DIR			*dir;

	if (lstat(path, &infos) == -1)
		return (-1);
	if (S_ISDIR(infos.st_mode) || S_ISLNK(infos.st_mode)
			|| S_ISREG(infos.st_mode))
	{
		if ((dir = opendir(path)))
		{
			closedir(dir);
			return (0);
		}
		return (1);
	}
	return (-1);
}

void	sh1_xcute_relative(char *cmd_path, char **args, char **env)
{
	int			status;
	pid_t		pid;
	struct stat	infos;

	lstat(cmd_path, &infos);
	if (!(infos.st_mode & S_IXUSR) || sh1_isxcut_relative(cmd_path) == 0)
	{
		ft_putstr_fd("ft_minishell1: permission denied: ", FT_STDERR);
		ft_putendl_fd(cmd_path, FT_STDERR);
		return ;
	}
	pid = fork();
	if (pid == 0)
	{
		execve(cmd_path, args, env);
		ft_exit(0);
	}
	else
		waitpid(pid, &status, 0);
}

int		sh1_search_cmd_indir(char *dir_path, char *cmd)
{
	DIR				*dir;
	struct dirent	*direntv;

	if ((dir = opendir(dir_path)))
	{
		while ((direntv = readdir(dir)))
		{
			if (!ft_strcmp(cmd, direntv->d_name))
			{
				closedir(dir);
				return (1);
			}
		}
		closedir(dir);
	}
	return (0);
}

char	*sh1_search_cmd_path(char *cmd, char **env)
{
	char	*paths_list;
	char	**paths_array;
	t_uint	i;
	char	*ret;

	if ((paths_list = sh1_getenv(env, "PATH")) == NULL)
		return (NULL);
	if ((paths_array = ft_strsplit(paths_list, ':')) == NULL)
		return (NULL);
	i = 0;
	ret = NULL;
	while (paths_array[i])
	{
		if (sh1_search_cmd_indir(paths_array[i], cmd))
		{
			ret = ft_strjoinsf(paths_array[i], ft_strjoin("/", cmd));
			break ;
		}
		++i;
	}
	i = 0;
	while (paths_array[i])
		free(paths_array[i++]);
	free(paths_array[i]), free(paths_array);
	return (ret);
}

void	sh1_xcute_extern(char *cmd, char **args, char **env)
{
	char		*path;

	if ((path = sh1_search_cmd_path(cmd, env)) == NULL)
	{
		ft_putstr_fd("ft_minishell1: command not found: ", FT_STDERR);
		ft_putendl_fd(cmd, FT_STDERR);
		return ;
	}
	sh1_xcute_relative(path, args, env);
	free(path);
}
