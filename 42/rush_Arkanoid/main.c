/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 18:40:21 by skerkour          #+#    #+#             */
/*   Updated: 2015/05/03 18:48:16 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
#include "libft_ext.h"

t_ark_ctx	*g_ctx;

char	*ark_buid_path(char *dir, char *file)
{
	char	*tmp;
	char	*ret;

	if (dir && file)
	{
		tmp = ft_strjoin(dir, "/");
		ret = ft_strjoin(tmp, file);
		free(tmp);
		return (ret);
	}
	return (NULL);
}

void	ark_reset_ball_pos_and_speed(t_ark_ctx *ctx)
{
	ctx->ball.x = 0.0f;
	ctx->ball.y = -0.955f + ctx->ball.r;
	ctx->ball.s.x = 0.02f;
	ctx->ball.s.y = 0.02f;
}

void	ark_init_vars(t_ark_ctx *ctx)
{
	ctx->player_hp = 3;
	ctx->bar.x = 0;
	ctx->bar.size = 0.10f;
	ctx->ball.r = 0.005f;
	ark_reset_ball_pos_and_speed(ctx);
}

int		main(int ac, char **av)
{
	t_ark_ctx	ctx;

	ft_bzero((void*)&ctx, sizeof(ctx));
	if (!ark_get_all_levels(&ctx, ac > 1 ? av[1] : "levels"))
	{
		ft_putendl_fd("error reading maps", FT_STDERR);
		exit(-42);
	}
	if (!ark_init_glfw(&ctx))
	{
		ft_putendl_fd("error initializing opengl...", FT_STDERR);
		exit(-42);
	}
	g_ctx = &ctx;
	ark_init_vars(&ctx);
	ark_launch_game(&ctx);
	return (0);
}
