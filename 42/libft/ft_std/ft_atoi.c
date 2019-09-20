/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:29:56 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/04 18:55:33 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_atoi_split(char **str, int *is_neg)
{
	if (**str == '-')
	{
		*is_neg = 1;
		++(*str);
	}
	else if (**str == '+')
		++(*str);
}

int			ft_atoi(const char *nptr)
{
	int		ret;
	int		is_neg;
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
