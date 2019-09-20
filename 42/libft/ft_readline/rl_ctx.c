/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ctx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 14:06:28 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/04 18:38:50 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <term.h>
#include <unistd.h>

#include "priv_readline.h"

void	rl_ctx_del(t_rl_ctx **ctx)
{
	ft_dlst_del(&((*ctx)->line));
	free((void*)*ctx);
	*ctx = NULL;
}

int		rl_ctx_init(t_rl_ctx **ctx, char *header)
{
	struct termios	org_opts;
	struct winsize	w;
	char			buff[1024];

	if (tcgetattr(fileno(stdin), &org_opts) < 0)
		return (0);
	tgetent(buff, getenv("TERM"));
	signal(SIGWINCH, rl_resize_handler);
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	if ((*ctx = (t_rl_ctx*)malloc(sizeof(t_rl_ctx))) == NULL)
		return (0);
	(*ctx)->line = NULL;
	(*ctx)->header = header;
	(*ctx)->pos = 0;
	(*ctx)->term_width = w.ws_col;
	g_rl_ctx = (*ctx);
	return (1);
}
