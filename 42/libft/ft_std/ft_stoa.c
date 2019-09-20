/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 18:30:33 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/20 12:34:17 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

static void	ft_stoa_putnbr(char *buff, size_t pos, size_t n)
{
	if (n >= 10)
	{
		if (n > 0)
			buff[pos] = (n % 10) + '0';
		else
			buff[pos] = -(n % 10) + '0';
		ft_stoa_putnbr(buff, pos - 1, n / 10);
	}
	else
		buff[pos] = n + '0';
}

char		*ft_stoa(size_t n)
{
	char	*ret;
	size_t	len;
	int		tn;

	tn = n;
	ret = NULL;
	len = 1;
	while (tn /= 10)
		++len;
	if ((ret = (char*)malloc(len + 1)) == NULL)
		return (NULL);
	ft_stoa_putnbr(ret, len - 1, n);
	ret[len] = 0;
	return (ret);
}
