/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 11:34:14 by skerkour          #+#    #+#             */
/*   Updated: 2016/02/16 11:41:23 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

static void	ft_str_to_upper_rec(char *str)
{
	if (*str)
	{
		*str = ft_toupper(*str);
		return (ft_str_to_upper_rec(str + 1));
	}
}

char		*ft_str_to_upper(char *str)
{
	char	*ret;

	ret = str;
	ft_str_to_upper_rec(str);
	return (ret);
}
