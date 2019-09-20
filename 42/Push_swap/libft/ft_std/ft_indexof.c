/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 11:14:10 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/20 17:04:49 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_indexof(char *str, char c)
{
	char	*start;

	start = str;
	while (*str)
	{
		if (*str == c)
			return ((int)(str - start));
		++str;
	}
	return (-1);
}
