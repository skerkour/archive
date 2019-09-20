/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:46:50 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/23 03:51:20 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "libft.h"

size_t	ft_strlen(char *str)
{
	char				*s;
	const uint32_t		*pdwText;
	register uint32_t	dwText;

	pdwText = (uint32_t*)str;
	while (1)
	{
		dwText = *pdwText;
		if ((dwText - 0x01010101UL) & ~dwText & 0x80808080UL)
		{
			s = (char*)pdwText;
			while (*s)
				s++;
			return (s - str);
		}
		pdwText++;
	}
}
