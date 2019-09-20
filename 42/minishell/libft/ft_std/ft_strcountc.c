/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcountc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 13:29:44 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/26 13:35:47 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_uint	ft_strcountc(char *str, char c)
{
	t_uint	ret;

	ret = 0;
	while (*str)
		if (*str++ == c)
			++ret;
	return (ret);
}
