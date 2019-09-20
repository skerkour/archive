/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_start_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 23:07:13 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/01 17:39:19 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

#include "libft.h"
#include "wong_kar_wai.h"

#define K_U KEY_UP
#define K_D KEY_DOWN
#define K_L KEY_LEFT
#define K_R KEY_RIGHT

static void	wkw_clear_fusion(t_wkw_ctx *ctx)
{
	int	i;

	i = 0;
	while (i < (ctx->n * ctx->n))
	{
		ctx->grid[i].f = 0;
		++i;
	}
}

void		wkw_start_game(t_wkw_ctx *ctx)
{
	int		k;
	int		moved;

	wkw_chck_w_l(ctx), wkw_draw_grid(ctx), wkw_clear_fusion(ctx);
	while (1)
	{
		k = getch();
		moved = 0;
		if (k == 27)
			wkw_exit(ctx, 0);
		if (k == K_U || k == K_D || k == K_L || k == K_R)
		{
			if (k == K_U)
				moved = wkw_play_up(ctx);
			else if (k == K_D)
				moved = wkw_play_down(ctx);
			else if (k == K_L)
				moved = wkw_play_left(ctx);
			else if (k == K_R)
				moved = wkw_play_right(ctx);
			if (moved)
				wkw_spawn_nbr(ctx);
			wkw_draw_grid(ctx), wkw_chck_w_l(ctx), wkw_clear_fusion(ctx);
		}
	}
}
