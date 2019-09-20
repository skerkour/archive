/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 22:21:38 by skerkour          #+#    #+#             */
/*   Updated: 2015/02/25 15:37:05 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <termios.h>
#include <stdlib.h>

#include "priv_readline.h"

int				rl_getch(void)
{
	int				ret;
	struct termios	org_opts;
	struct termios	new_opts;
	int				stdin_fileno;

	stdin_fileno = fileno(stdin);
	tcgetattr(stdin_fileno, &org_opts);
	ft_memcpy(&new_opts, &org_opts, sizeof(struct termios));
	new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT
			| ECHOKE | ICRNL);
	tcsetattr(stdin_fileno, TCSANOW, &new_opts);
	ret = ft_getchar();
	tcsetattr(stdin_fileno, TCSANOW, &org_opts);
	return (ret);
}

void			rl_escaped(t_lst *line, t_uint *pos, t_uint max)
{
	int	k;

	UNUSED(line);
	k = rl_getch();
	k = rl_getch();
	if (k == FT_RL_UP)
		;
	else if (k == FT_RL_DOWN)
		;
	else if (k == FT_RL_LEFT)
	{
		if (*pos > 0)
			rl_movecurs_left(1), --(*pos);
	}
	else if (k == FT_RL_RIGHT)
	{
		if (*pos < max)
			rl_movecurs_right(1), ++(*pos);
	}
}

void			rl_delete(t_lst **line, t_uint *pos, t_uint *max)
{
	if (*pos > 0)
	{
		--(*pos);
		--(*max);
		ft_lstdeli(line, *pos, rl_lstdel_el);
		rl_movecurs_left(1);
		rl_savecurs_pos();
		rl_movecurs_right(*max - *pos);
		ft_putchar(' ');
		rl_restorecurs_pos();
		rl_putlinei(*line, *pos);
		rl_restorecurs_pos();
	}
}

static int		rl_switch(t_rl_ctx *ctx, char k)
{
	if (k == 0x0a)
		return (0);
	else if (k == FT_RL_ESC)
		rl_escaped(ctx->line, &(ctx->pos), ctx->max);
	else if (k == FT_RL_TAB)
		return (1);
	else if (k == FT_RL_CTRL_D)
		exit(0);
	else if (k == FT_RL_CTRL_L)
		rl_clear_screen(ctx->header, ctx->line);
	else if (k == FT_RL_DEL)
		rl_delete(&(ctx->line), &(ctx->pos), &(ctx->max));
	else
	{
		ft_lstaddi(&(ctx->line), rl_lstnewel((char)k),
			(ctx->pos == 0 || ctx->pos == ctx->max) ? ctx->pos : ctx->pos - 1);
		rl_savecurs_pos(), rl_putlinei(ctx->line, ctx->pos);
		rl_restorecurs_pos(), rl_movecurs_right(1);
		++(ctx->max), ++(ctx->pos);
	}
	return (1);
}

char			*ft_readline(char *header)
{
	t_uint		k;
	t_rl_ctx	*ctx;
	char		*ret;

	ctx = rl_ctx_init(header);
	rl_putheader(ctx->header);
	while (1)
	{
		k = rl_getch();
		if (!rl_switch(ctx, k))
			break ;
	}
	ret = rl_list_to_tab(&(ctx->line)), free(ctx), ft_putchar('\n');
	return (ret);
}
