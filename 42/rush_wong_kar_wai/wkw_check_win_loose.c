/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_check_win_loose.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 12:47:58 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/01 19:26:28 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

#include "libft.h"
#include "wong_kar_wai.h"

static int		wkw_got_empty_neighbour(t_wkw_ctx *ctx, int i)
{
	int	x;
	int	y;

	x = i % ctx->n;
	y = i / ctx->n;
	if (x > 0)
		if (!ctx->grid[i - 1].v || ctx->grid[i - 1].v == ctx->grid[i].v)
			return (1);
	if (i < (ctx->n * ctx->n) - 1 && x < ctx->n - 1)
		if (!ctx->grid[i + 1].v || ctx->grid[i + 1].v == ctx->grid[i].v)
			return (1);
	if (y > 0)
		if (!ctx->grid[i - ctx->n].v
			|| ctx->grid[i - ctx->n].v == ctx->grid[i].v)
			return (1);
	if (i < (ctx->n * ctx->n) - ctx->n && y < ctx->n - 1)
		if (!ctx->grid[i + ctx->n].v
			|| ctx->grid[i + ctx->n].v == ctx->grid[i].v)
			return (1);
	return (0);
}

static int		wkw_is_locked(t_wkw_ctx *ctx)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (i < ctx->n)
	{
		if (wkw_got_empty_neighbour(ctx, i))
			ret = 1;
		++i;
	}
	return (ret == 0);
}

static int		wkw_win_lose_msg(t_wkw_ctx *ctx, int msg)
{
	int		x;
	int		y;
	char	*str;
	int		ret;

	clear();
	if (msg == 2)
	{
		ctx->won = 1;
		str = ft_strdup("You WIN ! Press ESC to quit, or any key to continue");
		wkw_color_on(4);
	}
	else
		str = ft_strdup("You LOSE ! Press any key to quit"), wkw_color_on(2);
	getmaxyx(stdscr, y, x);
	mvprintw(y / 2, (x / 2) - (ft_strlen(str)) / 2, str);
	wkw_color_off(msg == 2 ? 4 : 2);
	refresh();
	ret = getch();
	ft_memdel((void**)&str);
	return (ret);
}

void			wkw_chck_w_l(t_wkw_ctx *ctx)
{
	int	i;
	int	is_full;
	int	rep;

	i = 0;
	is_full = 1;
	while (i < (ctx->n * ctx->n))
	{
		if (ctx->grid[i].v >= WIN_VALUE && !ctx->won)
		{
			rep = wkw_win_lose_msg(ctx, 2);
			if (rep == 27)
				wkw_exit(ctx, 0);
			else
				wkw_draw_grid(ctx);
		}
		if (!ctx->grid[i].v)
			is_full = 0;
		++i;
	}
	if (is_full)
		if (wkw_is_locked(ctx))
			wkw_win_lose_msg(ctx, 1), wkw_exit(ctx, -42);
}
