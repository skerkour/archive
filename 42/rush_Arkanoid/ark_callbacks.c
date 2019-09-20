/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark_callbacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 17:37:04 by skerkour          #+#    #+#             */
/*   Updated: 2015/05/03 21:05:45 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <glfw3.h>

#include "arkanoid.h"
#include "libft_ext.h"

void	ark_error_callback(int error, const char *description)
{
	(void)error;
	ft_putendl_fd((char*)description, FT_STDERR);
}

void	ark_key_callback(GLFWwindow *win, int key, int code, int act, int mod)
{
	(void)code, (void)mod, (void)win;
	if (key == GLFW_KEY_RIGHT && (act == GLFW_PRESS || act == GLFW_REPEAT)
			&& g_ctx->bar.x + g_ctx->bar.size + 0.10f <= 1.0f
			&& !g_ctx->is_pause)
		g_ctx->bar.x += 0.10f;
	else if (key == GLFW_KEY_LEFT && (act == GLFW_PRESS || act == GLFW_REPEAT)
			&& g_ctx->bar.x - g_ctx->bar.size - 0.10f >= -1.1f
			&& !g_ctx->is_pause)
		g_ctx->bar.x -= 0.10f;
	else if (key == GLFW_KEY_ESCAPE && act == GLFW_PRESS)
		ark_finish_game(g_ctx);
	else if (key == GLFW_KEY_P && act == GLFW_PRESS)
		g_ctx->is_pause = !g_ctx->is_pause;
}

void	ark_resize_callback(GLFWwindow *window, int w, int h)
{
	if (w < ARK_MIN_WIN_X || h < ARK_MIN_WIN_Y)
	{
		w = w < ARK_MIN_WIN_X ? ARK_MIN_WIN_X : w;
		h = h < ARK_MIN_WIN_Y ? ARK_MIN_WIN_Y : h;
		glfwSetWindowSize(window, w, h);
	}
}
