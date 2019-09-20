/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:09:53 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/04 19:11:54 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strnstr_split(const char *s1, const char *s2, t_uint *i,
		size_t n)
{
	while (s1[i[0]] == s2[i[1]] && s1[i[0]] && s2[i[1]] && i[0] < n)
	{
		++(i[0]);
		++(i[1]);
	}
}

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	t_uint	i[2];
	char	*ret;

	if (s1 && s2)
	{
		i[0] = 0;
		i[1] = 0;
		if (!*s2)
			return ((char*)s1);
		while (s1[i[0]] && i[0] < n)
		{
			while (s1[i[0]] != s2[i[1]] && s1[i[0]])
				++(i[0]);
			ret = (char*)&(s1[i[0]]);
			ft_strnstr_split(s1, s2, i, n);
			if (!s2[i[1]])
				return (ret);
			else
				i[1] = 0;
		}
	}
	return (NULL);
}
