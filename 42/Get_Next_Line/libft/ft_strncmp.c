/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:34:53 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/03 12:34:54 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	register t_uchar	*ts1;
	register t_uchar	*ts2;

	if (n == 0)
		return (0);
	if (s1 && s2)
	{
		ts1 = (t_uchar*)s1;
		ts2 = (t_uchar*)s2;
		while (*ts1++ == *ts2++ && (*ts1 || *ts2) && --n)
			;
		--ts1;
		--ts2;
		if (*ts1 == *ts2)
			return (0);
		return ((int)(*ts1 - *ts2));
	}
	return (-1);
}
