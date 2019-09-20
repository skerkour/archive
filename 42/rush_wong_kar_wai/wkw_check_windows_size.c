/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_check_windows_size.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:36:42 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/01 22:52:40 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

#include "libft.h"
#include "wong_kar_wai.h"

void	wkw_check_windows_size(int n)
{
	int	x;
	int	y;

	getmaxyx(stdscr, y, x);
	if (x < (n * 9) + 1 || y < (2 * n) + 1)
		endwin(), wkw_error("window too small... Exiting."), ft_exit(-42);
}
