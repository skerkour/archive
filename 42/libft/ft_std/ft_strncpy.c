/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:56:29 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/04 19:05:05 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*tdst;
	char	*tsrc;
	size_t	i;

	tdst = dst;
	tsrc = (char*)src;
	i = 0;
	if (tdst && tsrc)
	{
		while (i < n && tsrc[i])
		{
			tdst[i] = tsrc[i];
			++i;
		}
		while (i < n)
		{
			tdst[i] = 0;
			++i;
		}
	}
	return (dst);
}
