/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:35:59 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/03 18:36:01 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	register char	*str;

	str = (char*)s;
	if (str)
	{
		while (*str)
			++str;
		if ((char)c == 0)
			return (str);
		while (str >= s)
		{
			if (*str == (char)c)
				return (str);
			--str;
		}
	}
	return (NULL);
}
