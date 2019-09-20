/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:20:19 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/03 15:20:20 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	t_uchar	*ptr;
	size_t	i;

	ptr = (t_uchar*)s;
	i = 0;
	if (ptr)
		while (i < n)
		{
			if (ptr[i] == (t_uchar)c)
				return (&ptr[i]);
			++i;
		}
	return (NULL);
}
