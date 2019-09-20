/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:10:08 by skerkour          #+#    #+#             */
/*   Updated: 2014/12/09 21:46:50 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

static int		ft_splitstr(char **tab, char *s, char c, t_uint len)
{
	t_uint	i;

	i = 0;
	while (*s == c && *s)
		++s;
	while (i < len)
	{
		if ((tab[i] = ft_strdupc(s, c)) == NULL)
			return (0);
		while (*s != c && *s)
			++s;
		while (*s == c && *s)
			++s;
		++i;
	}
	tab[i] = 0;
	return (1);
}

static t_uint	ft_split_count(char *s, char c)
{
	t_uint	ret;

	ret = 0;
	while (*s == c)
		++s;
	while (*s)
	{
		while (*s != c && *s)
			++s;
		while (*s == c && *s)
			++s;
		++ret;
	}
	return (ret);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ret;
	t_uint	len;

	ret = NULL;
	if (s)
	{
		len = ft_split_count((char*)s, c);
		if ((ret = (char**)malloc(sizeof(char*) * (len + 1))) == NULL)
			return (NULL);
		if (ft_splitstr(ret, (char*)s, c, len))
			return (ret);
		else
		{
			free(ret);
			ret = NULL;
		}
	}
	return (ret);
}
