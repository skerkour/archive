/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_play_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 17:12:13 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/01 17:41:29 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong_kar_wai.h"

static int	wkw_mv_right_cut(t_wkw_ctx *ctx, int *x_y, int x_trans, int i)
{
	if (x_trans > 0)
	{
		ctx->grid[(x_y[1] * ctx->n) + (x_y[0] + x_trans)].v = ctx->grid[i].v;
		ctx->grid[i].v = 0;
		return (1);
	}
	return (0);
}

static int	wkw_mv_cell_right(t_wkw_ctx *ctx, int i)
{
	int	x_y[2];
	int	x_trans;
	int	can_move;

	x_y[0] = i % ctx->n;
	x_y[1] = i / ctx->n;
	x_trans = 0;
	can_move = 1;
	while (can_move)
		if (x_y[0] + x_trans + 1 < ctx->n
			&& ((x_y[1] * ctx->n) + (x_y[0] + x_trans + 1)) < (ctx->n * ctx->n)
			&& ctx->grid[(x_y[1] * ctx->n) + (x_y[0] + x_trans + 1)].v == 0)
			x_trans++;
		else
			can_move = 0;
	if (x_y[0] + x_trans + 1 < ctx->n
	&& ((x_y[1] * ctx->n) + (x_y[0] + x_trans + 1)) < (ctx->n * ctx->n) &&
	ctx->grid[(x_y[1] * ctx->n) + (x_y[0] + x_trans + 1)].v == ctx->grid[i].v
	&& ctx->grid[(x_y[1] * ctx->n) + (x_y[0] + x_trans + 1)].f == 0)
	{
		x_trans++, ctx->grid[i].v = ctx->grid[i].v * 2;
		ctx->grid[(x_y[1] * ctx->n) + (x_y[0] + x_trans)].f = 1;
		ctx->score += ctx->grid[i].v;
	}
	return (wkw_mv_right_cut(ctx, x_y, x_trans, i));
}

int			wkw_play_right(t_wkw_ctx *ctx)
{
	int	i;
	int	ret;

	i = ctx->n * ctx->n;
	ret = 0;
	while (i--)
	{
		if (ctx->grid[i].v > 0)
			if (wkw_mv_cell_right(ctx, i))
				ret = 1;
	}
	return (ret);
}
