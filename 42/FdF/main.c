/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 10:23:59 by skerkour          #+#    #+#             */
/*   Updated: 2016/06/07 14:06:36 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>

#include "fdf.h"
#include "libft.h"

static void	fdf_commands(void)
{
	ft_putendl("Translation UP : UP");
	ft_putendl("Translation DOWN : DOWN");
	ft_putendl("Translation LEFT : LEFT");
	ft_putendl("Translation RIGHT : RIGHT");
	ft_putendl("Rotation X_UP : 1");
	ft_putendl("Rotation X_DOWN : 2");
	ft_putendl("Rotation Y_UP : 3");
	ft_putendl("Rotation Y_DOWN : 4");
	ft_putendl("Rotation Z_UP : 5");
	ft_putendl("Rotation Z_DOWN : 6");
	ft_putendl("Scale + : +");
	ft_putendl("Scale - : -");
	ft_putendl("Exit : ESC");
}

static void	fdf_usage(char *name)
{
	ft_putendl("Usage:");
	ft_putstr(name);
	ft_putendl(" <file>");
}

void		fdf_init_mlx(t_fdf_ctx *ctx, char *title)
{
	ctx->mlx = mlx_init();
	ctx->win = mlx_new_window(ctx->mlx, ctx->win_w, ctx->win_h, title);
}

void		fdf_adapt_map(t_fdf_ctx *ctx)
{
	int32_t	w;
	int32_t	h;
	double	s;

	w = (ctx->win_w + 100) / 2;
	h = (ctx->win_h + 100) / 2;
	if (ctx->center.x == 0)
		ctx->center.x = 10;
	if (ctx->center.y == 0)
		ctx->center.y = 10;
	if (ctx->map_w > ctx->map_h)
		s = (w - FDF_WIN_W * 0.8) / ctx->center.x;
	else
		s = (h - FDF_WIN_H * 0.8) / ctx->center.y;
	fdf_compute_translation(ctx, -ctx->center.x + w, -ctx->center.y + h);
	fdf_compute_scale(ctx, s);
}

int			main(int ac, char **av)
{
	t_fdf_ctx	ctx;

	if (ac != 2)
	{
		fdf_usage(av[0]);
		return (-42);
	}
	ft_bzero(&ctx, sizeof(t_fdf_ctx));
	ctx.win_h = FDF_WIN_H;
	ctx.win_w = FDF_WIN_W;
	fdf_parse_file(&ctx, av[1]);
	fdf_check_errors(&ctx);
	if ((ctx.map_len = ctx.map_w * ctx.map_h) == 0)
		return (-1);
	fdf_map_lst_to_array(&ctx);
	fdf_init_mlx(&ctx, av[1]);
	fdf_get_center(&ctx);
	fdf_adapt_map(&ctx);
	mlx_expose_hook(ctx.win, fdf_hook_expose, &ctx);
	mlx_key_hook(ctx.win, fdf_hook_keys, &ctx);
	fdf_commands();
	mlx_loop(ctx.mlx);
	return (0);
}
