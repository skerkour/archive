/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:29:05 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/04 15:29:06 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	t_uint	i;

	if (s && f)
	{
		i = 0;
		if ((ret = (char*)malloc(ft_strlen((char*)s) + 1)) == NULL)
			return (NULL);
		while (s[i])
		{
			ret[i] = (*f)(i, s[i]);
			++i;
		}
		ret[i] = 0;
		return (ret);
	}
	return (NULL);
}
