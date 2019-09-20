/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:56:31 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/03 15:56:33 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_strdup(char *s1)
{
	char	*ret;

	ret = NULL;
	if (s1)
	{
		if ((ret = (char*)malloc(ft_strlen((char*)s1) + 1)) == NULL)
			return (NULL);
		ft_strcpy(ret, (char*)s1);
	}
	return (ret);
}
