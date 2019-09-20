/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:17:47 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/04 18:17:48 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

static char	*ft_strtrim_start(char *s)
{
	while (*s == ' ' || *s == '\n' || *s == '\t')
		++s;
	return (s);
}

static char	*ft_strtrim_end(char *s)
{
	while (*s)
		++s;
	--s;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		--s;
	return (s);
}

static char	*ft_strtrimcut(char *start, char *end)
{
	char	*ret;
	size_t	i;

	i = 0;
	if (start <= end)
	{
		if ((ret = (char*)malloc((size_t)(end - start) + 1)) == NULL)
			return (NULL);
		while (start <= end)
			ret[i++] = *start++;
		ret[i] = 0;
	}
	else
	{
		if ((ret = (char*)malloc(1)) == NULL)
			return (NULL);
		ret[i] = 0;
	}
	return (ret);
}

char		*ft_strtrim(char const *s)
{
	char	*ret;
	char	*start;
	char	*end;

	ret = NULL;
	if (s)
	{
		start = ft_strtrim_start((char*)s);
		if (*s)
			end = ft_strtrim_end((char*)s);
		else
			end = (char*)s;
		if (start && end)
			return (ft_strtrimcut(start, end));
	}
	return (ret);
}
