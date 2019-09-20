/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:08:20 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/04 16:08:21 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	slen;
	size_t	i;

	ret = NULL;
	if (s)
	{
		slen = ft_strlen((char*)s);
		if (!slen || start > slen || len > slen)
			return (NULL);
		if ((ret = (char*)malloc(len + 1)) == NULL)
			return (NULL);
		i = 0;
		while (i < len)
			ret[i++] = s[start++];
		ret[i] = 0;
	}
	return (ret);
}
