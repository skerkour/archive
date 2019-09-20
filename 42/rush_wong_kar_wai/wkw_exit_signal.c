/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_exit_signal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:43:11 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/01 12:18:42 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

#include "libft.h"
#include "wong_kar_wai.h"

void	wkw_exit_signal(int sign)
{
	UNUSED(sign);
	endwin();
	ft_exit(-42);
}
