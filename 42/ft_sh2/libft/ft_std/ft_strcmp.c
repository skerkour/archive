/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:23:06 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/17 19:52:49 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1++ == *s2++ && (*s1 || *s2))
		;
	return ((int)(*(t_uchar*)(--s1) - *(t_uchar*)(--s2)));
}