/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpyb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 21:46:46 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/05 21:46:48 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpyb(void *dst, const void *src, size_t n)
{
	char	*tdst;
	char	*tsrc;

	if (dst && src)
	{
		tdst = (char*)dst;
		tsrc = (char*)src;
		while (n--)
			tdst[n] = tsrc[n];
	}
	return (dst);
}
