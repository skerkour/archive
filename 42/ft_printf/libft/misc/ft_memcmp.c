/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:30:32 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/03 15:30:34 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	t_uchar	*ts1;
	t_uchar	*ts2;
	size_t	i;

	i = 0;
	ts1 = (t_uchar*)s1;
	ts2 = (t_uchar*)s2;
	if (ts1 && ts2)
	{
		while (i < n && ts1[i] == ts2[i])
			++i;
		if (i == n)
			return (0);
		return ((int)(ts1[i] - ts2[i]));
	}
	return (-1);
}
