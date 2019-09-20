/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_movecursor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 10:10:07 by skerkour          #+#    #+#             */
/*   Updated: 2014/12/09 11:01:03 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "priv_readline.h"

void	rl_movecurs_right(t_uint n)
{
	if (n > 0)
	{
		ft_putchar(0x1b);
		ft_putchar('[');
		ft_putnbr(n);
		ft_putchar('C');
	}
}

void	rl_movecurs_left(t_uint n)
{
	if (n > 0)
	{
		ft_putchar(0x1b);
		ft_putchar('[');
		ft_putnbr(n);
		ft_putchar('D');
	}
}

void	rl_clear_screen(char *header, t_lst *line)
{
	ft_putstr("\x1b[2J\x1b[0;0H");
	if (header)
		ft_putstr(header);
	rl_putline(line);
}

void	rl_savecurs_pos(void)
{
	ft_putstr("\x1b[s");
}

void	rl_restorecurs_pos(void)
{
	ft_putstr("\x1b[u");
}
