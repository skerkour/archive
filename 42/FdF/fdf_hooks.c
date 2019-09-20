/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 13:17:13 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/31 15:02:25 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "fdf.h"
#include "libft.h"

int	fdf_hook_expose(t_fdf_ctx *ctx)
{
	fdf_redraw(ctx);
	return (0);
}

int	fdf_key_hook_translate(t_fdf_ctx *ctx, int key)
{
	if (key == FDF_KEY_TRANS_UP)
		fdf_compute_translation(ctx, 0, FDF_TRANS_UP);
	else if (key == FDF_KEY_TRANS_DOWN)
		fdf_compute_translation(ctx, 0, FDF_TRANS_DOWN);
	else if (key == FDF_KEY_TRANS_LEFT)
		fdf_compute_translation(ctx, FDF_TRANS_LEFT, 0);
	else if (key == FDF_KEY_TRANS_RIGHT)
		fdf_compute_translation(ctx, FDF_TRANS_RIGHT, 0);
	if (key == FDF_KEY_TRANS_UP || key == FDF_KEY_TRANS_DOWN
		|| key == FDF_KEY_TRANS_LEFT || key == FDF_KEY_TRANS_RIGHT)
		return (1);
	return (0);
}

int	fdf_key_hook_rotate(t_fdf_ctx *ctx, int key)
{
	if (key == FDF_KEY_ROT_X_UP)
		fdf_compute_rotation(ctx, FDF_ROT_X_UP, FDF_AXIS_X);
	else if (key == FDF_KEY_ROT_X_DOWN)
		fdf_compute_rotation(ctx, FDF_ROT_X_DOWN, FDF_AXIS_X);
	else if (key == FDF_KEY_ROT_Y_UP)
		fdf_compute_rotation(ctx, FDF_ROT_Y_UP, FDF_AXIS_Y);
	else if (key == FDF_KEY_ROT_Y_DOWN)
		fdf_compute_rotation(ctx, FDF_ROT_X_DOWN, FDF_AXIS_Y);
	else if (key == FDF_KEY_ROT_Z_UP)
		fdf_compute_rotation(ctx, FDF_ROT_Z_UP, FDF_AXIS_Z);
	else if (key == FDF_KEY_ROT_Z_DOWN)
		fdf_compute_rotation(ctx, FDF_ROT_Z_DOWN, FDF_AXIS_Z);
	if (key == FDF_KEY_ROT_X_UP || key == FDF_KEY_ROT_X_DOWN
		|| key == FDF_KEY_ROT_Y_UP || key == FDF_KEY_ROT_Y_DOWN
		|| key == FDF_KEY_ROT_Z_UP || key == FDF_KEY_ROT_Z_DOWN)
		return (1);
	return (0);
}

int	fdf_key_hook_scale(t_fdf_ctx *ctx, int key)
{
	if (key == FDF_KEY_SCALE_PLUS)
		fdf_compute_scale(ctx, FDF_ZOOM_IN);
	else if (key == FDF_KEY_SCALE_LESS)
		fdf_compute_scale(ctx, FDF_ZOOM_OUT);
	if (key == FDF_KEY_SCALE_PLUS || key == FDF_KEY_SCALE_LESS)
		return (1);
	return (0);
}

int	fdf_hook_keys(int key, t_fdf_ctx *ctx)
{
	if (key == FDF_KEY_ESC)
	{
		mlx_destroy_window(ctx->win, ctx->win);
		ft_exit(0);
	}
	if (fdf_key_hook_translate(ctx, key) || fdf_key_hook_rotate(ctx, key)
		|| fdf_key_hook_scale(ctx, key))
		fdf_redraw(ctx);
	return (0);
}
