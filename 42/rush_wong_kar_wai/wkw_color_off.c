/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_color_off.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:28:48 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/01 19:35:47 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

#include "wong_kar_wai.h"

void	wkw_color_off(unsigned int nb)
{
	if (nb == 2 || nb == 256)
		attroff(A_BOLD | COLOR_PAIR(8));
	else if (nb == 4 || nb == 512)
		attroff(A_BOLD | COLOR_PAIR(2));
	else if (nb == 8 || nb == 1024)
		attroff(A_BOLD | COLOR_PAIR(3));
	else if (nb == 16 || nb == 2048)
		attroff(A_BOLD | COLOR_PAIR(4));
	else if (nb == 32 || nb == 4096)
		attroff(A_BOLD | COLOR_PAIR(5));
	else if (nb == 64)
		attroff(A_BOLD | COLOR_PAIR(6));
	else
		attroff(A_BOLD | COLOR_PAIR(7));
}
