/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftl_fractals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 14:09:12 by skerkour          #+#    #+#             */
/*   Updated: 2016/06/10 12:10:23 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <mlx.h>
#include <math.h>

#include "fractol.h"

int32_t	ftl_fracal_mandelbrot(t_ftl_ctx *ctx, t_ftl_fractal fractal,
			t_ftl_point *point)
{
	fractal.c.r = 1.0 * (point->x - ctx->win_w / 2)
		/ (0.5 * fractal.zoom_ratio * ctx->win_w) + fractal.x1;
	fractal.c.i = 1.0 * (point->y - ctx->win_h / 2)
		/ (0.5 * fractal.zoom_ratio * ctx->win_h) + fractal.y1;
	while ((fractal.z.r * fractal.z.r + fractal.z.i * fractal.z.i) < 4 &&
			(fractal.n_iters < fractal.iters_max))
	{
		fractal.tmp = fractal.z.r;
		fractal.z.r = FTL_SQAURE(fractal.z.r) - FTL_SQAURE(fractal.z.i)
			+ fractal.c.r;
		fractal.z.i = 2 * fractal.z.i * fractal.tmp + fractal.c.i;
		fractal.n_iters += 1;
	}
	if (fractal.n_iters == fractal.iters_max)
		return (ftl_get_color(100, *(ctx->current_colors)));
	return (ftl_get_color((fractal.n_iters * fractal.n_iters) * 0.1,
				*(ctx->current_colors)));
}

int32_t	ftl_fractal_mandelbar(t_ftl_ctx *ctx, t_ftl_fractal fractal,
			t_ftl_point *point)
{
	fractal.c.r = 1.0 * (point->x - ctx->win_w / 2)
		/ (0.5 * fractal.zoom_ratio * ctx->win_w) + fractal.x1;
	fractal.c.i = (point->y - ctx->win_h / 2)
		/ (0.5 * fractal.zoom_ratio * ctx->win_h) + fractal.y1;
	while ((FTL_SQAURE(fractal.z.r) + FTL_SQAURE(fractal.z.i)) < 4 &&
			(fractal.n_iters < fractal.iters_max))
	{
		fractal.tmp = fractal.z.r;
		fractal.z.i *= -1;
		fractal.z.r = fractal.z.r * fractal.z.r - fractal.z.i * fractal.z.i
			+ fractal.c.r;
		fractal.z.i = 2 * fractal.z.i * fractal.tmp + fractal.c.i;
		fractal.n_iters += 1;
	}
	if (fractal.n_iters == fractal.iters_max)
		return (ftl_get_color(100, *(ctx->current_colors)));
	return (ftl_get_color((FTL_SQAURE(fractal.n_iters)) * 0.1,
		*(ctx->current_colors)));
}

int32_t	ftl_fractal_julia(t_ftl_ctx *ctx, t_ftl_fractal fractal,
			t_ftl_point *point)
{
	fractal.z.r = 1.0 * (point->x - ctx->win_w / 2)
		/ (0.5 * fractal.zoom_ratio * ctx->win_w) + fractal.x1;
	fractal.z.i = (point->y - ctx->win_h / 2)
		/ (0.5 * fractal.zoom_ratio * ctx->win_h) + fractal.y1;
	while ((FTL_SQAURE(fractal.z.r) + FTL_SQAURE(fractal.z.i)) < 4 &&
			(fractal.n_iters < fractal.iters_max))
	{
		fractal.tmp = fractal.z.r;
		fractal.z.r = FTL_SQAURE(fractal.z.r) - FTL_SQAURE(fractal.z.i)
			+ fractal.c.r;
		fractal.z.i = 2 * fractal.z.i * fractal.tmp + fractal.c.i;
		fractal.n_iters += 1;
	}
	if (fractal.n_iters == fractal.iters_max)
		return (ftl_get_color(100, *(ctx->current_colors)));
	return (ftl_get_color((FTL_SQAURE(fractal.n_iters)) * 0.1,
		*(ctx->current_colors)));
}

int32_t	ftl_fractal_carpet(t_ftl_ctx *ctx, t_ftl_fractal fractal,
			t_ftl_point *point)
{
	int32_t x;
	int32_t y;

	UNUSED(fractal);
	x = point->x;
	y = point->y;
	while (x > 0 || y > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (ftl_get_color(0, *(ctx->current_colors)));
		y /= 3;
		x /= 3;
	}
	return (ftl_get_color(10, *(ctx->current_colors)));
}

int32_t	ftl_fractal_burning_ship(t_ftl_ctx *ctx, t_ftl_fractal fractal,
			t_ftl_point *point)
{
	fractal.c.r = 1.0 * (point->x - ctx->win_w / 2)
		/ (0.5 * fractal.zoom_ratio * ctx->win_w) + fractal.x1;
	fractal.c.i = (point->y - ctx->win_h / 2)
		/ (0.5 * fractal.zoom_ratio * ctx->win_h) + fractal.y1;
	while ((fractal.z.r * fractal.z.r + fractal.z.i * fractal.z.i) < 4 &&
			(fractal.n_iters < fractal.iters_max))
	{
		fractal.tmp = fractal.z.r;
		fractal.z.r = fractal.z.r * fractal.z.r - fractal.z.i * fractal.z.i
			- fractal.c.r;
		fractal.z.i = 2 * fabs(fractal.z.i) * fabs(fractal.tmp) + fractal.c.i;
		fractal.n_iters += 1;
	}
	if (fractal.n_iters == fractal.iters_max)
	{
		return (ftl_rgb_ton_int32(fractal.n_iters * 255 / fractal.iters_max,
			10, 0));
	}
	return (ftl_rgb_ton_int32(fractal.n_iters * 255 / fractal.iters_max,
		fractal.n_iters * 255 / (fractal.iters_max * 2), 0));
}
