/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 18:27:46 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/21 15:54:54 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

size_t	ft_dlstlen(t_dlst *list)
{
	size_t	ret;

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
