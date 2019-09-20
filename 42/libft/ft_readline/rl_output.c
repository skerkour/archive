/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 17:06:25 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/04 18:49:03 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <unistd.h>
#include <stdio.h>

#include "libft.h"
#include "priv_readline.h"

void	rl_putline(t_rl_ctx *ctx)
{
	t_dlst	*tmp;
	t_uint	len;
	t_uint	tpos;

	len = ctx->line ? ft_dlstlen(ctx->line) : 0;
	tpos = ctx->pos;
	tmp = ctx->line;
	while (tmp)
	{
		ft_putchar(*((char*)tmp->data));
		tmp = tmp->next;
	}
	while (++tpos < len)
		tputs(tgetstr("le", NULL), 0, rl_putchar);
}

int		rl_putchar(int c)
{
	ft_putchar(c);
	return (1);
}

void	rl_clear_screen(t_rl_ctx *ctx)
{
	t_dlst	*tmp;
	t_uint	len;
	t_uint	tpos;

	tputs(tgetstr("cl", NULL), 0, rl_putchar);
	rl_putheader(ctx);
	tmp = ctx->line;
	if (tmp)
	{
		while (tmp->prev)
			tmp = tmp->prev;
		while (tmp)
		{
			ft_putchar(*((char*)tmp->data));
			tmp = tmp->next;
		}
		len = ctx->line ? ft_dlstlen(ctx->line) : 0;
		tpos = ctx->pos;
		while (tpos++ < len)
			tputs(tgetstr("le", NULL), 0, rl_putchar);
	}
}

void	rl_putheader(t_rl_ctx *ctx)
{
	if (ctx->header)
		ft_putstr(ctx->header);
}
