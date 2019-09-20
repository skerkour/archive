/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftl_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 14:26:47 by skerkour          #+#    #+#             */
/*   Updated: 2016/06/10 11:46:25 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdio.h>
#include <mlx.h>

#include "fractol.h"

int	ftl_hook_mouse(int32_t btn, int32_t x, int32_t y, t_ftl_ctx *ctx)
{
	if (btn == FTL_MOUSE_BTN_LEFT || btn == FTL_MOUSE_SCROLL_UP
		|| btn == FTL_MOUSE_BTN_RIGHT || btn == FTL_MOUSE_SCROLL_DOWN)
	{
		ctx->current_fractal->x1 += ((((double)x - ctx->win_h / 2) / ctx->win_w
			/ 2) / ctx->current_fractal->zoom_ratio * 10) / 3;
		ctx->current_fractal->x2 += ((((double)x - ctx->win_h / 2) / ctx->win_w
			/ 2) / ctx->current_fractal->zoom_ratio * 10) / 3;
		ctx->current_fractal->y1 += ((((double)y - ctx->win_w / 2) / ctx->win_h
			/ 2) / ctx->current_fractal->zoom_ratio * 10) / 3;
		ctx->current_fractal->y2 += ((((double)y - ctx->win_w / 2) / ctx->win_h
			/ 2) / ctx->current_fractal->zoom_ratio * 10) / 3;
		if (btn == FTL_MOUSE_BTN_RIGHT || btn == FTL_MOUSE_SCROLL_DOWN)
			ctx->current_fractal->zoom_ratio *= 1.1;
		else
			ctx->current_fractal->zoom_ratio /= 1.1;
	}
	ftl_redraw(ctx);
	return (0);
}

int	ftl_hook_expose(t_ftl_ctx *ctx)
{
	ftl_redraw(ctx);
	return (0);
}

int	ftl_hook_keys(int key, t_ftl_ctx *ctx)
{
	if (key == FTL_KEY_ESC)
	{
		mlx_destroy_window(ctx->mlx, ctx->win);
		ft_exit(0);
	}
	ftl_hook_keys_change_fractal(key, ctx);
	ftl_hook_keys_controls_fractal(key, ctx);
	ftl_redraw(ctx);
	return (0);
}

int	ftl_hook_motion(int x, int y, t_ftl_ctx *ctx)
{
	if (x >= 0 && y >= 0 && x <= (int)ctx->win_w && y <= (int)ctx->win_h
		&& ctx->is_motion == 1)
	{
		ctx->current_fractal->c.r = (double)x / (double)ctx->win_w * 4 - 2;
		ctx->current_fractal->c.i = (double)y / (double)ctx->win_h * 4 - 2;
		ftl_redraw(ctx);
	}
	return (0);
}
