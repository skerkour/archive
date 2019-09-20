/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrepl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:07:29 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/06 11:07:30 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ulong		ft_memrepl(void *p, t_ulong n, t_ulong s, t_ulong d)
{
	t_ulong		*tp;
	t_ulong		ret;
	t_ulong		i;

	ret = 0;
	if (p)
	{
		tp = (t_ulong*)p;
		i = 0;
		while (i < n)
		{
			if (*tp == s)
				*tp = d, ++ret;
			++tp, i += sizeof(long);
		}
	}
	return (ret);
}
