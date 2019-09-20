/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrepc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:26:17 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/06 10:26:18 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ulong	ft_memrepc(void *p, t_ulong n, t_uchar s, t_uchar d)
{
	t_uchar	*tp;
	t_ulong	ret;

	ret = 0;
	if (p)
	{
		tp = (t_uchar*)p;
		while (n--)
		{
			if (*tp == s)
				*tp = d, ++ret;
			++tp;
		}
	}
	return (ret);
}
