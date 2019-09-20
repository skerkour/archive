/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark_collide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 11:40:43 by skerkour          #+#    #+#             */
/*   Updated: 2015/05/03 17:52:22 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

#define LOL0 ((ctx->ball.y <= block_y && ctx->ball.y >= block_y + ARK_BRICK_H))
#define LOL1 ((ctx->ball.x >= block_x && ctx->ball.x <= block_x + ARK_BRICK_W))
#define LOL22 (ball_right + ctx->ball.s.x >= 1.0f)
#define LOL2 (ball_left + ctx->ball.s.x <= -1.0f || LOL22)
#define LOL3 (ball_bot + ctx->ball.s.y <= -1.0f)

int		ark_ball_is_collinding_bar(float ball_y, t_ark_ctx *ctx)
{
	if (ball_y <= -0.965f && ctx->ball.x >= ctx->bar.x - ctx->bar.size
			&& ctx->ball.x <= ctx->bar.x + ctx->bar.size)
		return (1);
	return (0);
}

int		ark_ball_is_colliding_brick_x(t_ark_ctx *ctx)
{
	char			*map;
	float			block_x;
	float			block_y;
	unsigned int	i;

	i = 0;
	map = ctx->lvl.bricks;
	while (*map)
	{
		block_x = -1 + ((float)(i % ARK_NBIRCKS) * ARK_BRICK_W);
		block_y = 0.8 - ((float)(i / ARK_NBIRCKS) * 0.04f);
		if (*map == 'X' || (*map >= '1' && *map <= '3'))
		{
			if (LOL0 && ((ctx->ball.x >= block_x
				&& ctx->ball.x <= block_x + ARK_BRICK_W)))
			{
				*map = *map == 'X' ? *map : *map - 1;
				ctx->score += *map == 'X' ? 0 : 10;
				return (1);
			}
		}
		++map;
		++i;
	}
	return (0);
}

int		ark_ball_is_colliding_brick_y(t_ark_ctx *ctx)
{
	char			*map;
	float			block_x;
	float			block_y;
	unsigned int	i;

	i = 0;
	map = ctx->lvl.bricks;
	while (*map)
	{
		block_x = -1 + ((float)(i % ARK_NBIRCKS) * ARK_BRICK_W);
		block_y = 0.8 - ((float)(i / ARK_NBIRCKS) * 0.04f);
		if (*map == 'X' || (*map >= '1' && *map <= '3'))
		{
			if (LOL1 && ((ctx->ball.y <= block_y
					&& ctx->ball.y >= block_y - ARK_BRICK_H)))
			{
				*map = *map == 'X' ? *map : *map - 1;
				ctx->score += *map == 'X' ? 0 : 10;
				return (1);
			}
		}
		++map;
		++i;
	}
	return (0);
}

void	ark_compute_ball(t_ark_ctx *ctx)
{
	float	ball_top;
	float	ball_bot;
	float	ball_left;
	float	ball_right;

	ball_top = ctx->ball.y + ctx->ball.r;
	ball_bot = ctx->ball.y - ctx->ball.r;
	ball_right = ctx->ball.x + ctx->ball.r;
	ball_left = ctx->ball.x - ctx->ball.r;
	if (ball_bot + ctx->ball.s.y <= -1.0f)
	{
		ctx->player_hp -= 1;
		ark_reset_ball_pos_and_speed(ctx);
	}
	else
	{
		if (LOL2 || ark_ball_is_colliding_brick_x(ctx))
			ctx->ball.s.x *= -1;
		if (LOL3 || ball_top + ctx->ball.s.y >= 0.8f + ARK_BRICK_H
				|| ark_ball_is_collinding_bar(ball_bot, ctx)
				|| ark_ball_is_colliding_brick_y(ctx))
			ctx->ball.s.y *= -1;
		ctx->ball.x += ctx->ball.s.x;
		ctx->ball.y += ctx->ball.s.y;
	}
}
