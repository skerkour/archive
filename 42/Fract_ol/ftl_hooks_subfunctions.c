/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftl_hooks_subfunctions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:34:13 by skerkour          #+#    #+#             */
/*   Updated: 2016/03/11 15:35:40 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ftl_hook_keys_change_fractal(int key, t_ftl_ctx *ctx)
{
	if (key == FTL_KEY_PAD_1)
		ctx->current_fractal = &(ctx->fractals_arr[0]);
	else if (key == FTL_KEY_PAD_2)
		ctx->current_fractal = &(ctx->fractals_arr[1]);
	else if (key == FTL_KEY_PAD_3)
		ctx->current_fractal = &(ctx->fractals_arr[2]);
	else if (key == FTL_KEY_PAD_4)
		ctx->current_fractal = &(ctx->fractals_arr[3]);
	else if (key == FTL_KEY_PAD_5)
		ctx->current_fractal = &(ctx->fractals_arr[4]);
}

void	ftl_hook_keys_controls_fractal(int key, t_ftl_ctx *ctx)
{
	if (key == FTL_KEY_P)
		ctx->is_motion = ctx->is_motion == 1 ? 0 : 1;
	else if (key == FTL_KEY_C)
		ftl_fractal_change_colors(ctx);
	else if (key == FTL_KEY_PAD_PLUS)
		ftl_fractal_change_scale(ctx, 1.1);
	else if (key == FTL_KEY_PAD_MINUS)
		ftl_fractal_change_scale(ctx, -1.1);
	else if (key == FTL_KEY_LEFT)
		ftl_fractal_translate(ctx, 5, 'x');
	else if (key == FTL_KEY_RIGHT)
		ftl_fractal_translate(ctx, -5, 'x');
	else if (key == FTL_KEY_UP)
		ftl_fractal_translate(ctx, 5, 'y');
	else if (key == FTL_KEY_DOWN)
		ftl_fractal_translate(ctx, -5, 'y');
	else if (key == FTL_KEY_Q)
		ftl_fractal_change_iterations(ctx, -5);
	else if (key == FTL_KEY_W)
		ftl_fractal_change_iterations(ctx, 5);
}
