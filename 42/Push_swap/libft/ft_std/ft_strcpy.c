/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:11:03 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/23 03:49:36 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(register char *dst, register char *src)
{
	char	*orig;

	orig = dst;
	while (*src)
		*dst++ = *src++;
	*dst = 0;
	return (orig);
}
