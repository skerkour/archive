/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_play_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 17:30:00 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/01 17:41:17 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong_kar_wai.h"

static int	wkw_mv_up_cut(t_wkw_ctx *ctx, int *x_y, int y_trans, int i)
{
	if (y_trans > 0)
	{
		ctx->grid[((x_y[1] - y_trans) * ctx->n) + x_y[0]].v = ctx->grid[i].v;
		ctx->grid[i].v = 0;
		return (1);
	}
	return (0);
}

static int	wkw_mv_cell_up(t_wkw_ctx *ctx, int i)
{
	int	x_y[2];
	int	y_trans;
	int	can_move;

	x_y[0] = i % ctx->n;
	x_y[1] = i / ctx->n;
	y_trans = 0;
	can_move = 1;
	while (can_move)
		if (x_y[1] - y_trans - 1 >= 0
		&& ctx->grid[((x_y[1] - y_trans - 1) * ctx->n) + x_y[0]].v == 0)
			y_trans++;
		else
			can_move = 0;
	if (x_y[1] - y_trans - 1 >= 0 &&
	ctx->grid[((x_y[1] - y_trans - 1) * ctx->n) + x_y[0]].v == ctx->grid[i].v
	&& ctx->grid[((x_y[1] - y_trans - 1) * ctx->n) + x_y[0]].f == 0)
	{
		y_trans++, ctx->grid[i].v = ctx->grid[i].v * 2;
		ctx->grid[((x_y[1] - y_trans) * ctx->n) + x_y[0]].f = 1;
		ctx->score += ctx->grid[i].v;
	}
	return (wkw_mv_up_cut(ctx, x_y, y_trans, i));
}

int			wkw_play_up(t_wkw_ctx *ctx)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (i < (ctx->n * ctx->n))
	{
		if (ctx->grid[i].v > 0)
			if (wkw_mv_cell_up(ctx, i))
				ret = 1;
		++i;
	}
	return (ret);
}
