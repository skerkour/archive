/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:52:45 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/04 19:17:53 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strstr_split(char **ts1, char **ts2)
{
	while (**ts1 == **ts2 && **ts2 && **ts1)
	{
		++(*ts2);
		++(*ts1);
	}
}

char		*ft_strstr(const char *s1, const char *s2)
{
	char	*ts2;
	char	*ts1;
	char	*ret;
	char	*tstr;

	tstr = (char*)s1;
	if (s1 && s2)
	{
		if (!*s2)
			return ((char*)s1);
		while (*tstr)
		{
			ts1 = (char*)tstr;
			ts2 = (char*)s2;
			while ((*ts1 != *ts2) && *ts1)
				++ts1;
			ret = ts1;
			ft_strstr_split(&ts1, &ts2);
			if (!(*ts2))
				return (ret);
			++tstr;
		}
	}
	return (NULL);
}
