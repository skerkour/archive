/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 11:34:13 by skerkour          #+#    #+#             */
/*   Updated: 2016/02/16 11:41:23 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

static void	ft_str_to_lower_rec(char *str)
{
	if (*str)
	{
		*str = ft_tolower(*str);
		return (ft_str_to_lower_rec(str + 1));
	}
}

char		*ft_str_to_lower(char *str)
{
	char	*ret;

	ret = str;
	ft_str_to_lower_rec(str);
	return (ret);
}
