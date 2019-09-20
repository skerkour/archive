/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memreps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:32:09 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/06 10:32:10 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ulong		ft_memreps(void *p, t_ulong n, t_ushort s, t_ushort d)
{
	t_ushort	*tp;
	t_ulong		ret;
	t_ulong		i;

	ret = 0;
	if (p)
	{
		tp = (t_ushort*)p;
		ret = 0;
		i = 0;
		while (i < n)
		{
			if (*tp == s)
				*tp = d, ++ret;
			++tp, i += sizeof(short);
		}
	}
	return (ret);
}
