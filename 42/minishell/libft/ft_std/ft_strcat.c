/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:22:54 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/03 17:23:01 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, char *s2)
{
	char	*dst;

	dst = s1;
	while (*dst)
		++dst;
	while (*s2)
		*dst++ = *s2++;
	*dst = 0;
	return (s1);
}