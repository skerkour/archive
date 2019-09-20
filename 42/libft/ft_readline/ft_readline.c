/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 16:35:05 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/04 18:47:27 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <term.h>
#include <signal.h>

#include "libft.h"
#include "priv_readline.h"

t_rl_ctx *g_rl_ctx;

int		rl_getch(void)
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

void	rl_escaped(t_rl_ctx *ctx)
{
	int	k;

	k = rl_getch();
	k = rl_getch();
	if (k == FT_RL_LEFT && ctx->line)
		rl_left_arrow(ctx);
	else if (k == FT_RL_RIGHT && ctx->line && ctx->pos < ft_dlstlen(ctx->line))
		rl_right_arrow(ctx);
	UNUSED(ctx);
	UNUSED(k);
}

int		rl_switch_input(t_rl_ctx *ctx, char k)
{
	if (k == '\n')
		return (0);
	else if (k == FT_RL_ESC)
		rl_escaped(ctx);
	else if (k == FT_RL_CTRL_D)
		ft_exit(0);
	else if (k == FT_RL_CTRL_L)
		rl_clear_screen(ctx);
	else if (k == FT_RL_DEL)
		rl_delete(ctx);
	else if (k == FT_RL_CTRL_K)
		return (1);
	else
	{
		if (k != FT_RL_TAB)
			rl_add_char(ctx, k);
	}
	return (1);
}

char	*ft_readline(char *header)
{
	char		*ret;
	t_rl_ctx	*ctx;
	int			k;

	ctx = NULL;
	if (!rl_ctx_init(&ctx, header))
		return (NULL);
	rl_putheader(ctx);
	while (42)
	{
		k = rl_getch();
		if (!rl_switch_input(ctx, k))
			break ;
	}
	ret = rl_dlist_to_arr(ctx->line);
	rl_ctx_del(&ctx);
	ft_putchar('\n');
	return (ret);
}
