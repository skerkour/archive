/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 13:18:13 by skerkour          #+#    #+#             */
/*   Updated: 2014/12/13 13:22:22 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	**ft_arrccpy(char **array)
{
	char	**ret;
	t_uint	i;

	if ((ret = (char**)malloc(sizeof(char*) * (ft_arrlen(array) + 1))) == NULL)
		return (NULL);
	i = 0;
	while (array[i])
	{
		ret[i] = ft_strdup(array[i]);
		++i;
	}
	ret[i] = NULL;
	return (ret);
}
