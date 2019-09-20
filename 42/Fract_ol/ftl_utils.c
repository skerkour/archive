/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 14:09:28 by skerkour          #+#    #+#             */
/*   Updated: 2016/03/11 15:42:26 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdint.h>

#include "libft.h"
#include "fractol.h"

void	ftl_init_colors(t_ftl_ctx *ctx)
{
	ctx->colors_arr = (t_ftl_colors*)ft_xmalloc(sizeof(t_ftl_colors) * 4);
	ctx->colors_arr[0] = (t_ftl_colors){0x210303, 0x3F0B0B, 0x601F1F, 0x823B3B,
		0xA35D5D, 0xC18989, 0xDDB8B8, 0xF9F2F2, 0xffffff};
	ctx->colors_arr[1] = (t_ftl_colors){0x031121, 0x0B233F, 0x1F3E60, 0x3B5C82,
		0x5D7DA3, 0x89A3C1, 0xB8C9DD, 0xF2F5F9, 0xffffff};
	ctx->colors_arr[2] = (t_ftl_colors){0x150321, 0x2A0B3F, 0x461F60, 0x653B82,
		0x875DA3, 0xAB89C1, 0xCEB8DD, 0xF6F2F9, 0xffffff};
	ctx->colors_arr[3] = (t_ftl_colors){0x000000, 0xEDFF75, 0x000000, 0xCCCCCC,
		0xBBBBBB, 0xAAAAAA, 0x999999, 0x888888, 0xffffff};
	ctx->current_colors = &(ctx->colors_arr[0]);
	ctx->i_colors = 0;
}

void	ftl_fractal_change_colors(t_ftl_ctx *ctx)
{
	if (ctx->i_colors == FTL_N_COLORS - 1)
		ctx->i_colors = 0;
	else
		ctx->i_colors += 1;
	ctx->current_colors = &(ctx->colors_arr[ctx->i_colors]);
}

int32_t	ftl_get_color(int32_t z, t_ftl_colors colors)
{
	int32_t color;

	z = sin(z) * 100;
	color = colors.color_0;
	if (z < 0)
		color = colors.color_0;
	else if (z >= 0 && z < 15)
		color = colors.color_1;
	else if (z >= 15 && z < 25)
		color = colors.color_2;
	else if (z >= 25 && z < 35)
		color = colors.color_3;
	else if (z >= 35 && z < 45)
		color = colors.color_4;
	else if (z >= 55 && z < 65)
		color = colors.color_5;
	else if (z >= 65 && z < 75)
		color = colors.color_6;
	else if (z >= 75 && z < 85)
		color = colors.color_7;
	else if (z >= 85)
		color = colors.color_8;
	return (color);
}

void	ftl_use_fractal(t_ftl_ctx *ctx, char *fractal_name)
{
	if (ft_strcmp(fractal_name, "mandelbrot") == 0)
		ctx->current_fractal = &(ctx->fractals_arr[0]);
	else if (ft_strcmp(fractal_name, "julia") == 0)
		ctx->current_fractal = &(ctx->fractals_arr[1]);
	else if (ft_strcmp(fractal_name, "mandelbar") == 0)
		ctx->current_fractal = &(ctx->fractals_arr[2]);
	else if (ft_strcmp(fractal_name, "carpet") == 0)
		ctx->current_fractal = &(ctx->fractals_arr[3]);
	else if (ft_strcmp(fractal_name, "burning_ship") == 0)
		ctx->current_fractal = &(ctx->fractals_arr[4]);
	else
		ctx->current_fractal = &(ctx->fractals_arr[0]);
}

int32_t	ftl_rgb_ton_int32(int32_t r, int32_t g, int32_t b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + ((b & 0xff)));
}
