/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 16:14:47 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/01 19:35:33 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <signal.h>

#include "libft.h"
#include "wong_kar_wai.h"

void	wkw_init(t_wkw_ctx *ctx)
{
	initscr(), wkw_check_windows_size(ctx->n);
	noecho(), keypad(stdscr, TRUE), signal(SIGWINCH, wkw_resize_handler);
	signal(SIGINT, wkw_exit_signal), curs_set(0), start_color();
	init_pair(8, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	ctx->score = 0;
	ctx->won = 0;
	wkw_spawn_nbr(ctx), wkw_spawn_nbr(ctx);
}
