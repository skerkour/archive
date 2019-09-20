/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:47:30 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/03 17:47:31 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	register size_t	i;
	register size_t	j;
	size_t			ret;

	if (dst && src)
	{
		ret = ft_strlen((char*)src);
		i = 0;
		j = 0;
		while (dst[i] && i < size)
			++i;
		if (size > 0)
			while (i < size - 1 && src[j])
				dst[i++] = src[j++];
		if (j > 0)
		{
			dst[i] = 0;
			return (ret + i - j);
		}
		return (ret + i);
	}
	return (0);
}
