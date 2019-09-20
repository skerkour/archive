/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:52:45 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/03 18:52:47 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
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
			while (*ts1 == *ts2 && *ts2 && *ts1)
				++ts2, ++ts1;
			if (!(*ts2))
				return (ret);
			++tstr;
		}
	}
	return (NULL);
}
