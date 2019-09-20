/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftl_graphics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 10:28:03 by skerkour          #+#    #+#             */
/*   Updated: 2016/03/10 15:02:36 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "fractol.h"

void	ftl_draw_pixel_img(t_ftl_ctx *ctx, t_ftl_point *point, int32_t color)
{
	int32_t	i;

	i = ((int32_t)point->x * 4) + ((int32_t)point->y * ctx->size_line);
	ctx->mlx_img[i] = color;
	ctx->mlx_img[++i] = color >> 8;
	ctx->mlx_img[++i] = color >> 16;
}

void	ftl_apply_func(t_ftl_ctx *ctx, t_ftl_fractal *fractal,
		int32_t (*f)(t_ftl_ctx*, t_ftl_fractal, t_ftl_point*))
{
	t_ftl_point	point;
	int32_t		pixel_color;

	point.y = 0;
	while (point.y < ctx->win_h)
	{
		point.x = 0;
		while (point.x < ctx->win_w)
		{
			pixel_color = (*f)(ctx, *fractal, &point);
			ftl_draw_pixel_img(ctx, &(point), pixel_color);
			point.x += 1;
		}
		point.y += 1;
	}
}

void	ftl_redraw(t_ftl_ctx *ctx)
{
	ctx->img = mlx_new_image(ctx->mlx, ctx->win_w, ctx->win_h);
	ctx->mlx_img = mlx_get_data_addr(ctx->img,
			&(ctx->bpp), &(ctx->size_line), &(ctx->ed));
	ftl_apply_func(ctx, ctx->current_fractal, ctx->current_fractal->func);
	mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img, 0, 0);
	mlx_destroy_image(ctx->mlx, ctx->img);
}
