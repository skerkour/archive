/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 18:05:37 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/08 17:36:32 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <term.h>

#include "priv_readline.h"

void	rl_delete(t_rl_ctx *ctx)
{
	t_dlst	*tmp;
	t_uint	len;
	t_uint	tpos;

	if (ctx->pos && ctx->line)
	{
		tmp = ctx->line;
		if (tmp->prev)
			tmp->prev->next = tmp->next;
		if (tmp->next)
			tmp->next->prev = tmp->prev;
		ctx->line = tmp->prev ? tmp->prev : tmp->next;
		free(tmp->data), free(tmp), tmp = NULL;
		ctx->pos--;
		tputs(tgetstr("le", NULL), 0, rl_putchar);
		tputs(tgetstr("cd", NULL), 0, rl_putchar);
		tmp = ctx->line ? ctx->line->next : NULL;
		len = ctx->line ? ft_dlstlen(ctx->line) : 0;
		tpos = ctx->pos;
		while (tmp)
			ft_putchar(*((char*)tmp->data)), tmp = tmp->next;
		while (tpos++ < len)
			tputs(tgetstr("le", NULL), 0, rl_putchar);
	}
}
