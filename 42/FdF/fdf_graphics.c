/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_graphics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:47:44 by skerkour          #+#    #+#             */
/*   Updated: 2016/06/06 14:53:59 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdint.h>

#include "fdf.h"

void	fdf_draw_line_params(double *arr, t_fdf_point p1, t_fdf_point p2)
{
	arr[0] = fabs(p1.x - p2.x);
	arr[1] = p1.x < p2.x ? 1 : -1;
	arr[2] = fabs(p1.y - p2.y);
	arr[3] = p1.y < p2.y ? 1 : -1;
	arr[4] = (arr[0] > arr[2] ? arr[0] : -arr[2]) * 0.5;
}

void	fdf_draw_point(t_fdf_ctx *ctx, t_fdf_point point, int32_t color)
{
	size_t	i;

	i = ((size_t)point.x * 4) + ((size_t)point.y * (size_t)ctx->size_line);
	ctx->mlx_img[i] = color;
	i += 1;
	ctx->mlx_img[i] = color >> 8;
	i += 1;
	ctx->mlx_img[i] = color >> 16;
}

void	fdf_draw_line(t_fdf_ctx *ctx, t_fdf_point p1, t_fdf_point p2, int state)
{
	double	arr[6];

	if (!fdf_is_point_out_of_win(p1) && !fdf_is_point_out_of_win(p2))
		return ;
	fdf_draw_line_params(arr, p1, p2);
	while (state == 1 && !((int)p1.x == (int)p2.x && (int)p1.y == (int)p2.y))
	{
		if (fdf_is_point_out_of_win(p1))
			fdf_draw_point(ctx, p1, fdf_get_color(p1, p2));
		arr[5] = arr[4];
		state = 0;
		if (arr[5] > -arr[0] && (int)p1.x != (int)p2.x)
		{
			arr[4] -= arr[2];
			p1.x += arr[1];
			state = 1;
		}
		if (arr[5] < arr[2] && (int)p1.y != (int)p2.y)
		{
			arr[4] += arr[0];
			p1.y += arr[3];
			state = 1;
		}
	}
}

void	fdf_draw(t_fdf_ctx *ctx)
{
	size_t	i;

	i = 0;
	while (ctx->map_array[i])
	{
		if ((i + 1) < ctx->map_len
			&& ((i + 1) % ctx->map_w) != 0)
			fdf_draw_line(ctx, *(ctx->map_array[i]), *(ctx->map_array[i + 1]),
				1);
		if ((i + ctx->map_w) < ctx->map_len)
			fdf_draw_line(ctx, *(ctx->map_array[i]),
				*(ctx->map_array[i + ctx->map_w]), 1);
		i += 1;
	}
}

void	fdf_redraw(t_fdf_ctx *ctx)
{
	ctx->img = mlx_new_image(ctx->mlx, ctx->win_w + 100, ctx->win_h + 100);
	ctx->mlx_img = mlx_get_data_addr(ctx->img,
		&(ctx->bpp), &(ctx->size_line), &(ctx->ed));
	fdf_draw(ctx);
	mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img, -50, -50);
	mlx_destroy_image(ctx->mlx, ctx->img);
}
