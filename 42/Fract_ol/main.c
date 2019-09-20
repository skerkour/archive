/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 11:32:38 by skerkour          #+#    #+#             */
/*   Updated: 2016/06/08 11:09:27 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <stdint.h>

#include "libft.h"
#include "fractol.h"

void	ftl_usage(t_ftl_ctx *ctx, char *filename)
{
	size_t	i;

	ft_putendl("Usage :");
	ft_putstr(filename);
	ft_putstr(" < ");
	i = 0;
	while (i < FTL_N_FRACTALS)
	{
		ft_putstr(ctx->fractals_arr[i].name);
		if (i < FTL_N_FRACTALS - 1)
			ft_putstr(" | ");
		i += 1;
	}
	ft_putendl(" >");
	ft_exit(-1);
}

void	ftl_init_mlx(t_ftl_ctx *ctx, char *title)
{
	ctx->mlx = mlx_init();
	ctx->win = mlx_new_window(ctx->mlx, ctx->win_w, ctx->win_h, title);
}

void	ftl_instructions(void)
{
	ft_putendl("INSTRUCTIONS :");
	ft_putendl("+, -                  : change scale");
	ft_putendl("1, 2, 3, 4, 5         : change fractal");
	ft_putendl("c                     : change colors");
	ft_putendl("p                     : pause/play motion");
	ft_putendl("left, right, up, down : move");
	ft_putendl("q, w                  : change iterations");
}

void	ftl_params(t_ftl_ctx *ctx, int ac, char **av)
{
	size_t	i;

	if (ac != 2)
		ftl_usage(ctx, av[0]);
	i = 0;
	while (i < FTL_N_FRACTALS)
	{
		if (ft_strcmp(ft_str_to_lower(av[1]), ctx->fractals_arr[i].name) == 0)
			return ;
		i += 1;
	}
	ftl_usage(ctx, av[0]);
}

int		main(int ac, char **av)
{
	t_ftl_ctx	ctx;

	ft_bzero(&ctx, sizeof(t_ftl_ctx));
	ctx.win_w = FTL_WIN_W;
	ctx.win_h = FTL_WIN_H;
	ctx.is_motion = 1;
	ftl_init_fractals(&ctx);
	ftl_init_colors(&ctx);
	ftl_params(&ctx, ac, av);
	ftl_instructions();
	ftl_init_mlx(&ctx, av[1]);
	ftl_use_fractal(&ctx, ft_str_to_lower(av[1]));
	mlx_expose_hook(ctx.win, ftl_hook_expose, &ctx);
	mlx_key_hook(ctx.win, ftl_hook_keys, &ctx);
	mlx_mouse_hook(ctx.win, ftl_hook_mouse, &ctx);
	mlx_hook(ctx.win, FTL_MOTION_NOTIFY, FTL_MOTION_MASK, ftl_hook_motion,
		&ctx);
	mlx_loop(ctx.mlx);
	return (0);
}
