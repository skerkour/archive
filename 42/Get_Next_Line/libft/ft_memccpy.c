/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:14:23 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/03 14:14:24 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	t_uchar	*tdst;
	t_uchar	*tsrc;
	size_t	i;

	tdst = (t_uchar*)dst;
	tsrc = (t_uchar*)src;
	i = 0;
	if (tdst && tsrc)
		while (i < n)
		{
			tdst[i] = tsrc[i];
			if (tdst[i] == (t_uchar)c)
				return ((void*)&tdst[i + 1]);
			++i;
		}
	return (NULL);
}
