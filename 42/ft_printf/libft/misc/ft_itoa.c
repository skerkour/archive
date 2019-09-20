/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 09:52:23 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/05 09:52:25 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

static void	ft_itoa_putnbr(char *buff, t_uint pos, int n)
{
	if (n >= 10 || n <= -10)
	{
		if (n > 0)
			buff[pos] = (n % 10) + '0';
		else
			buff[pos] = -(n % 10) + '0';
		ft_itoa_putnbr(buff, pos - 1, n / 10);
	}
	else
	{
		if (n > 0)
			buff[pos] = n + '0';
		else
			buff[pos] = -n + '0';
	}
}

char		*ft_itoa(int n)
{
	char	*ret;
	size_t	len;
	int		tn;

	tn = n;
	ret = NULL;
	len = 1;
	while (tn /= 10)
		++len;
	if ((ret = (char*)malloc(len + (n < 0 ? 2 : 1))) == NULL)
		return (NULL);
	if (n < 0)
	{
		ret[0] = '-';
		ft_itoa_putnbr(&ret[1], len - 1, n);
	}
	else
		ft_itoa_putnbr(ret, len - 1, n);
	if (n < 0)
		ret[len + 1] = 0;
	else
		ret[len] = 0;
	return (ret);
}
