/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 15:56:44 by skerkour          #+#    #+#             */
/*   Updated: 2015/05/03 02:01:10 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <glfw3.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "arkanoid.h"
#include "libft_ext.h"

int		ark_get_all_levels(t_ark_ctx *ctx, char *dir_path)
{
	DIR				*dir;
	struct dirent	*entry;
	struct stat		infos;
	char			*path;

	if ((dir = opendir(dir_path)))
	{
		while ((entry = readdir(dir)))
		{
			path = ark_buid_path(dir_path, entry->d_name);
			if ((stat(path, &infos) == 0) && S_ISREG(infos.st_mode))
				ark_enqueue_lvl(&(ctx->lvl_names), path);
		}
		if (ft_lstlen(ctx->lvl_names) <= 0)
			return (0);
		return (1);
	}
	return (0);
}

int		ark_init_glfw(t_ark_ctx *ctx)
{
	glfwSetErrorCallback(ark_error_callback);
	if (!glfwInit())
		return (0);
	if (!(ctx->window = glfwCreateWindow(ARK_MIN_WIN_X, ARK_MIN_WIN_Y,
			"Arkanoid 42", NULL, NULL)))
	{
		glfwTerminate();
		return (0);
	}
	glfwMakeContextCurrent(ctx->window);
	glfwSwapInterval(1);
	glfwSetKeyCallback(ctx->window, ark_key_callback);
	glfwSetWindowSizeCallback(ctx->window, ark_resize_callback);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	return (1);
}
