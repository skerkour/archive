/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_resize_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 23:23:37 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/01 17:04:02 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

#include "libft.h"
#include "wong_kar_wai.h"

void	wkw_resize_handler(int sign)
{
	UNUSED(sign);
	endwin(), refresh(), clear();
	wkw_check_windows_size(g_ctx->n);
	wkw_draw_grid(g_ctx);
}
