/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:54:18 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/03 14:54:19 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*tdst;

	if (dst && src)
	{
		if ((tdst = (void*)malloc(len)) == NULL)
			return (NULL);
		ft_memcpy(tdst, src, len);
		ft_memcpy(dst, tdst, len);
		free(tdst);
	}
	return (dst);
}
