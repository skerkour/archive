/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_dlst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 17:50:02 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/04 18:48:11 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <term.h>

#include "libft.h"
#include "priv_readline.h"

void	rl_addchar_prev(t_rl_ctx *ctx, t_dlst *new_el)
{
	new_el->prev = ctx->line->prev;
	ctx->line->prev = new_el;
	new_el->next = ctx->line;
}

void	rl_addchar_next(t_rl_ctx *ctx, t_dlst *new_el)
{
	if (ctx->line)
		new_el->next = ctx->line->next;
	else
		new_el->next = NULL;
	if (ctx->line)
		ctx->line->next = new_el;
	new_el->prev = ctx->line;
}

void	rl_add_char(t_rl_ctx *ctx, char c)
{
	t_dlst	*new_el;

	new_el = (t_dlst*)ft_xmalloc(sizeof(t_dlst));
	new_el->data = (void*)ft_xmalloc(1);
	*((char*)new_el->data) = c;
	new_el->size = 1;
	if (!ctx->pos && ctx->line)
		rl_addchar_prev(ctx, new_el);
	else
		rl_addchar_next(ctx, new_el);
	ctx->line = new_el;
	tputs(tgetstr("ce", NULL), 0, rl_putchar);
	rl_putline(ctx);
	ctx->pos++;
}

void	rl_del_char(t_rl_ctx *ctx)
{
	t_dlst	*tmp;

	if (ctx->line)
	{
		tmp = ctx->line;
		ctx->line = ctx->line->prev;
		free(tmp->data);
		free(tmp);
	}
}
