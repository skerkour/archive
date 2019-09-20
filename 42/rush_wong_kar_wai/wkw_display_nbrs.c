/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_display_nbrs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 11:12:00 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/01 19:30:49 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

#include "libft.h"
#include "wong_kar_wai.h"

static void	wkw_print_nbr_in_case(t_wkw_ctx *ctx, int i)
{
	int	height;
	int	width;
	int	x;
	int	y;

	getmaxyx(stdscr, height, width);
	x = ((i % ctx->n) * (width / ctx->n)) + ((width / ctx->n) / 2);
	y = ((i / ctx->n) * (height / ctx->n)) + ((height / ctx->n) / 2);
	wkw_color_on(ctx->grid[i].v);
	mvprintw(y, x, "%u", ctx->grid[i].v);
	wkw_color_off(ctx->grid[i].v);
}

void		wkw_display_nbrs(t_wkw_ctx *ctx)
{
	int	i;

	i = 0;
	while (i < ctx->n * ctx->n)
	{
		if (ctx->grid[i].v > 0)
			wkw_print_nbr_in_case(ctx, i);
		++i;
	}
	refresh();
}
