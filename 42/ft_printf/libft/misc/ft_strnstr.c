/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:09:53 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/03 19:09:55 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	t_uint	i;
	t_uint	y;
	char	*ret;

	if (s1 && s2)
	{
		i = 0;
		y = 0;
		if (!*s2)
			return ((char*)s1);
		while (s1[i] && i < n)
		{
			while (s1[i] != s2[y] && s1[i])
				++i;
			ret = (char*)&(s1[i]);
			while (s1[i] == s2[y] && s1[i] && s2[y] && i < n)
				++i, ++y;
			if (!s2[y])
				return (ret);
			else
				y = 0;
		}
	}
	return (NULL);
}
