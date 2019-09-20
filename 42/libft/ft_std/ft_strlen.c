/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:46:50 by skerkour          #+#    #+#             */
/*   Updated: 2015/05/28 19:42:02 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "libft.h"

#define MAGIC_BIT (0x7efefeffL)
#define MAGIC_BITS (((0x7efefefeL << 16) << 16) | 0xfefefeffL)
#define HIMAGIC (0x80808080L)
#define HIMAGICS (((HIMAGIC << 16) << 16) | HIMAGIC)
#define LOMAGIC (0x01010101L)
#define LOMAGICS (((LOMAGIC << 16) << 16) | LOMAGIC)

/*
** #if UINTPTR_MAX == 0xffffffff
** static inline size_t	pft_strlen(char *s, char *base)
** {
** if ((*(uint32_t*)s - 0x01010101UL) & ~*(uint32_t*)s & 0x80808080UL)
** return (*s ? pft_strlen(++s, base) : (size_t)(s - base));
** else
** return (pft_strlen(s + sizeof(uint32_t), base));
** }
** #else
*/

static inline size_t	pft_strlen(char *s, char *base)
{
	if ((((*(long*)s + MAGIC_BITS) ^ ~*(long*)s) & ~MAGIC_BITS))
		return (*s ? pft_strlen(++s, base) : (size_t)(s - base));
	else
		return (pft_strlen(s + sizeof(long), base));
}

size_t					ft_strlen(register char *str)
{
	return (pft_strlen(str, str));
}
