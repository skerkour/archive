/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_arrows.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 14:45:15 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/04 18:39:25 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <term.h>

#include "priv_readline.h"

void	rl_right_arrow(t_rl_ctx *ctx)
{
	ctx->pos++;
	if (ctx->pos && ((ctx->pos + (ctx->header ? ft_strlen(ctx->header) : 0))
			% ctx->term_width) == 0)
	{
		tputs(tgetstr("do", NULL), 0, rl_putchar);
		tputs(tgetstr("hd", NULL), 0, rl_putchar);
	}
	else
		tputs(tgetstr("nd", NULL), 0, rl_putchar);
	ctx->line = ctx->line->next ? ctx->line->next : ctx->line;
}

void	rl_left_arrow(t_rl_ctx *ctx)
{
	if (ctx->line->prev)
		ctx->line = ctx->line->prev;
	if (ctx->pos)
	{
		tputs(tgetstr("le", NULL), 0, rl_putchar);
		ctx->pos--;
	}
}
