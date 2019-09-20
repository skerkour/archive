/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_resize_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 17:14:57 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/07 17:23:54 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <unistd.h>

#include "libft.h"
#include "priv_readline.h"

void	rl_resize_handler(int sign)
{
	struct winsize	w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	g_rl_ctx->term_width = w.ws_col;
	UNUSED(sign);
}
