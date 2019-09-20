/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 18:27:46 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/07 12:52:32 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_uint	ft_dlstlen(t_dlst *list)
{
	t_uint	ret;

	while (list->prev)
		list = list->prev;
	ret = 0;
	while (list)
	{
		list = list->next;
		++ret;
	}
	return (ret);
}
