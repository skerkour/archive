/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexof_any.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 22:49:29 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/22 22:49:29 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_indexof_any(char *str, char *arr)
{
	int		ret;

	while (arr)
	{
		ret = 0;
		while (str[ret])
		{
			if (str[ret] == *arr)
				return (ret);
			++ret;
		}
		++arr;
	}
	return (-1);
}
