/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:23:41 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/03 13:55:13 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	register char	*tdst;
	register char	*tsrc;

	if (dst && src)
	{
		tdst = (char*)dst - 1;
		tsrc = (char*)src - 1;
		while (n--)
			*++tdst = *++tsrc;
	}
	return (dst);
}
