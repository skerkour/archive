/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpyc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:36:05 by skerkour          #+#    #+#             */
/*   Updated: 2014/12/09 21:47:46 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpyc(char *dst, char *src, char c)
{
	char	*orig;

	orig = dst;
	while (*src != c && *src)
		*dst++ = *src++;
	*dst = 0;
	return (orig);
}
