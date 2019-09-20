/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arkanoid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 14:45:20 by skerkour          #+#    #+#             */
/*   Updated: 2015/05/03 22:02:32 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <glfw3.h>
#include <stdlib.h>

#include "arkanoid.h"
#include "libft_ext.h"

#include <stdio.h>

void	ark_set_time(t_ark_ctx *ctx, char *tmp)
{
	static double	last_time;
	static int		n_frames;
	double			current_time;
	char			*title;
	char			*tmp2;

	current_time = glfwGetTime();
	n_frames++;
	if (current_time - last_time >= 1.0)
	{
		tmp = ft_strdup("Arkanoid 42 @ [");
		tmp2 = ft_itoa(n_frames);
		title = tmp;
		tmp = ft_strjoin(title, tmp2);
		free(tmp2), free(title);
		title = ft_strjoin(tmp, "] fps");
		free(tmp);
		glfwSetWindowTitle(ctx->window, title);
		free(title);
		n_frames = 0;
		last_time += 1.0;
	}
}

int		ark_map_is_empty(char *map)
{
	while (*map)
	{
		if (*map >= '1' && *map <= '3')
			return (0);
		++map;
	}
	return (1);
}

void	ark_finish_game(t_ark_ctx *ctx)
{
	if (ctx->player_hp)
		ft_printf("{grn}GG YOU WIN, SCORE : %u{eoc}\n", ctx->score);
	else
		ft_printf("{red}BG YOU LOOSE, SCORE : %u{eoc}\n", ctx->score);
	glfwDestroyWindow(ctx->window);
	glfwTerminate();
	ft_putendl("+---------------+\n| Latest scores |\n+---------------+");
	ark_display_latest_scores(SCORES_FILE);
	ark_save_score(ctx);
	exit(0);
}

void	ark_launch_game(t_ark_ctx *ctx)
{
	while (!glfwWindowShouldClose(ctx->window) && ctx->lvl_names
			&& ctx->player_hp > 0)
	{
		if (ark_get_next_lvl(ctx) > 0)
		{
			while (!glfwWindowShouldClose(ctx->window) && ctx->player_hp > 0)
			{
				ark_set_time(ctx, NULL);
				if (!ctx->is_pause)
				{
					ark_compute_ball(ctx);
					if (ark_map_is_empty(ctx->lvl.bricks))
					{
						ark_reset_ball_pos_and_speed(ctx);
						break ;
					}
					ark_draw_map(ctx);
				}
				glfwPollEvents();
			}
		}
	}
	ark_finish_game(ctx);
}
