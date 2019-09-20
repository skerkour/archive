/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:46:50 by skerkour          #+#    #+#             */
/*   Updated: 2015/02/21 15:43:35 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "libft.h"

size_t	ft_strlen(char *str)
{
	char				*s;
	const uint32_t		*pdw_txt;
	register uint32_t	dw_txt;

	pdw_txt = (uint32_t*)str;
	while (1)
	{
		dw_txt = *pdw_txt;
		if ((dw_txt - 0x01010101UL) & ~dw_txt & 0x80808080UL)
		{
			s = (char*)pdw_txt;
			while (*s)
				s++;
			return (s - str);
		}
		pdw_txt++;
	}
}
