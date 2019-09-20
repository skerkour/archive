/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi32.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 12:26:38 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/21 11:15:01 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "libft.h"

static void	ft_atoi_split(char **str, int32_t *is_neg)
{
	if (**str == '-')
	{
		*is_neg = 1;
		++(*str);
	}
	else if (**str == '+')
		++(*str);
}

int32_t		ft_atoi32(const char *nptr)
{
	int32_t	ret;
	int32_t	is_neg;
	char	*str;

	is_neg = 0;
	ret = 0;
	str = (char*)nptr;
	if (str)
	{
		while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
				|| *str == '\v' || *str == '\f')
			++str;
		ft_atoi_split(&str, &is_neg);
		while (*str >= '0' && *str <= '9')
		{
			ret += *str++ - '0';
			if (*str >= '0' && *str <= '9')
				ret *= 10;
		}
	}
	return (is_neg ? -ret : ret);
}
