/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftl_utils_fractals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:36:52 by skerkour          #+#    #+#             */
/*   Updated: 2016/03/11 15:42:26 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ftl_fractal_change_iterations(t_ftl_ctx *ctx, int32_t iters)
{
	if (iters <= 0)
	{
		if (ctx->current_fractal->iters_max + iters <= 0)
			ctx->current_fractal->iters_max = 3;
		else
			ctx->current_fractal->iters_max += iters;
	}
	else
		ctx->current_fractal->iters_max += iters;
}

void	ftl_fractal_translate(t_ftl_ctx *ctx, int32_t d, char axis)
{
	double	*one;
	double	*two;

	if (axis == 'x')
	{
		one = &(ctx->current_fractal->x1);
		two = &(ctx->current_fractal->x2);
	}
	else
	{
		one = &(ctx->current_fractal->y1);
		two = &(ctx->current_fractal->y2);
	}
	if (d < 0)
	{
		*one -= -d / (ctx->current_fractal->zoom_ratio * 20);
		*two -= -d / (ctx->current_fractal->zoom_ratio * 20);
	}
	else
	{
		*one += d / (ctx->current_fractal->zoom_ratio * 20);
		*two += d / (ctx->current_fractal->zoom_ratio * 20);
	}
}

void	ftl_fractal_change_scale(t_ftl_ctx *ctx, double zoom_ratio)
{
	if (zoom_ratio >= 0.0)
		ctx->current_fractal->zoom_ratio *= zoom_ratio;
	else
		ctx->current_fractal->zoom_ratio /= -zoom_ratio;
	zoom_ratio = ctx->current_fractal->zoom_ratio;
	ctx->current_fractal->x1 += ((ctx->win_h / 2) / ctx->win_w / 2)
		/ zoom_ratio * 10;
	ctx->current_fractal->x2 += ((ctx->win_h / 2) / ctx->win_w / 2)
		/ zoom_ratio * 10;
	ctx->current_fractal->y1 += ((ctx->win_w / 2) / ctx->win_h / 2)
		/ zoom_ratio * 10;
	ctx->current_fractal->y2 += ((ctx->win_w / 2) / ctx->win_h / 2)
		/ zoom_ratio * 10;
}

void	ftl_init_fractals(t_ftl_ctx *ctx)
{
	ctx->fractals_arr = (t_ftl_fractal*)ft_xmalloc(sizeof(t_ftl_fractal) * 5);
	ctx->fractals_arr[0] = (t_ftl_fractal){{0, 0}, {0, 0}, -0.9, 0, 0, 0,
		ctx->win_w / (0.6 + 2.1), ctx->win_h / (1.2 + 1.2), 0.5, 0, 0, 50,
		ftl_fracal_mandelbrot, ft_strdup("mandelbrot")};
	ctx->fractals_arr[1] = (t_ftl_fractal){{0.285, 0.01}, {0, 0}, 0, 0, 0, 0,
		ctx->win_w / (1.5 + 1.5), ctx->win_h / (1.2 + 1.2),
		0.5, 0, 0, 10, ftl_fractal_julia, ft_strdup("julia")};
	ctx->fractals_arr[2] = (t_ftl_fractal){{0, 0}, {0, 0}, 0, 0, 0, 0,
		ctx->win_w / (0.6 + 2.1), ctx->win_h / (1.2 + 1.2),
		0.5, 0, 0, 50, ftl_fractal_mandelbar, ft_strdup("mandelbar")};
	ctx->fractals_arr[3] = (t_ftl_fractal){{0, 0}, {0, 0}, -2.1, 0.6, -1.2,
		1.2, ctx->win_w / (0.6 - (-2.1)), ctx->win_h / (1.2 - (-1.2)),
		1, 0, 0, 50, ftl_fractal_carpet, ft_strdup("carpet")};
	ctx->fractals_arr[4] = (t_ftl_fractal){{0, 0}, {0, 0}, 0, 0, 0, 0,
		ctx->win_w / (1.6 + 1.1), ctx->win_h / (1.7 + 0.7),
		0.5, 0, 0, 50, ftl_fractal_burning_ship, ft_strdup("burning_ship")};
	ctx->current_fractal = &(ctx->fractals_arr[0]);
}
