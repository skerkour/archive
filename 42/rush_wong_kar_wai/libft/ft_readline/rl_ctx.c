/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ctx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 13:37:16 by skerkour          #+#    #+#             */
/*   Updated: 2015/01/04 14:03:59 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** struct termios, tcgetattr
*/
#include <termios.h>

/*
** fileno
*/
#include <stdio.h>

/*
** exit
*/
#include <stdlib.h>

#include "priv_readline.h"

t_rl_ctx	*rl_ctx_init(char *header)
{
	t_rl_ctx		*ret;
	struct termios	org_opts;

	ret = (t_rl_ctx*)ft_xmalloc(sizeof(t_rl_ctx));
	ret->line = NULL;
	ret->header = NULL;
	ret->pos = 0;
	ret->max = 0;
	ret->header = header;
	if (tcgetattr(fileno(stdin), &org_opts) < 0)
		exit(-1);
	return (ret);
}
