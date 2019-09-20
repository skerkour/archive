/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 10:49:37 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/08 10:49:39 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*str_e;
	char	*str_s;

	if (*str)
	{
		str_s = str - 1;
		str_e = str;
		while (*str_e)
			++str_e;
		while (str_e-- > ++str_s)
			if (str_s != str_e)
			{
				*str_e ^= *str_s;
				*str_s ^= *str_e;
				*str_e ^= *str_s;
			}
	}
	return (str);
}
