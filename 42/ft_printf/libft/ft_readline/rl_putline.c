/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_putline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 10:07:18 by skerkour          #+#    #+#             */
/*   Updated: 2014/12/09 10:38:55 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"
#include "libft.h"

void	rl_putline(t_lst *letter)
{
	while (letter)
	{
		ft_putchar(*((char*)letter->data));
		letter = letter->next;
	}
}

void	rl_putlinei(t_lst *letter, t_uint start)
{
	t_uint	i;

	i = 0;
	while (i++ < start && letter)
		letter = letter->next;
	while (letter)
	{
		ft_putchar(*((char*)letter->data));
		letter = letter->next;
	}
}
