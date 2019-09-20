/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_color_on.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:26:56 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/01 19:35:42 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

#include "wong_kar_wai.h"

void	wkw_color_on(unsigned int nb)
{
	if (nb == 2 || nb == 256)
		attron(A_BOLD | COLOR_PAIR(8));
	else if (nb == 4 || nb == 512)
		attron(A_BOLD | COLOR_PAIR(2));
	else if (nb == 8 || nb == 1024)
		attron(A_BOLD | COLOR_PAIR(3));
	else if (nb == 16 || nb == 2048)
		attron(A_BOLD | COLOR_PAIR(4));
	else if (nb == 32 || nb == 4096)
		attron(A_BOLD | COLOR_PAIR(5));
	else if (nb == 64)
		attron(A_BOLD | COLOR_PAIR(6));
	else
		attron(A_BOLD | COLOR_PAIR(7));
}
