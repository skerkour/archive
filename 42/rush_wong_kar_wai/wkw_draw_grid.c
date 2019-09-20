/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_draw_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:43:14 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/01 20:17:33 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

#include "libft.h"
#include "wong_kar_wai.h"

void	wkw_draw_grid(t_wkw_ctx *ctx)
{
	int	x;
	int	y;
	int	tn;
	int	t;

	clear(), getmaxyx(stdscr, y, x), tn = ctx->n;
	t = 0;
	while (tn--)
	{
		move(t, 0);
		hline('-', x);
		t += y / ctx->n;
	}
	tn = ctx->n;
	t = 0;
	while (tn--)
	{
		move(0, t);
		vline('|', y);
		t += x / ctx->n;
	}
	move(0, 0), box(stdscr, '|', '-');
	mvprintw(y - 1, 2, " %s : %u ", ctx->player_name, ctx->score);
	refresh(), wkw_display_nbrs(ctx);
}
