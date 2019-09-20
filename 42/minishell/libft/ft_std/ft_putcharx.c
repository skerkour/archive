/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 12:58:56 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/08 12:58:59 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putcharx(t_uchar c)
{
	char	charset[17];

	ft_strcpy(charset, "0123456789abcdef");
	if (c < 16)
	{
		ft_putchar('0');
		ft_putchar(charset[c]);
	}
	else
	{
		ft_putchar(charset[c / 16]);
		ft_putchar(charset[c % 16]);
	}
}
