/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharx_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 22:51:22 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/06 22:51:26 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putcharx_fd(t_uchar c, int fd)
{
	char	charset[17];

	ft_strcpy(charset, "0123456789abcdef");
	if (c < 16)
	{
		ft_putchar_fd('0', fd);
		ft_putchar_fd(charset[c], fd);
	}
	else
	{
		ft_putchar_fd(charset[c / 16], fd);
		ft_putchar_fd(charset[c % 16], fd);
	}
}
