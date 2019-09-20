/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrepi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:06:07 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/04 19:02:42 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ulong		ft_memrepi(void *p, t_ulong n, t_uint s, t_uint d)
{
	t_uint		*tp;
	t_ulong		ret;
	t_ulong		i;

	ret = 0;
	if (p)
	{
		tp = (t_uint*)p;
		i = 0;
		while (i < n)
		{
			if (*tp == s)
			{
				*tp = d;
				++ret;
			}
			++tp;
			i += sizeof(int);
		}
	}
	return (ret);
}
