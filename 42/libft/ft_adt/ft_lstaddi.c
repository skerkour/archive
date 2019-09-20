/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 20:09:47 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/04 19:00:08 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

void	ft_lstaddi(t_lst **top, t_lst *elem, size_t pos)
{
	size_t	i;
	t_lst	*tmp;

	if (!*top || pos == 0)
		ft_lstpush(top, elem);
	else
	{
		i = 0;
		tmp = *top;
		while (i < pos && tmp->next)
		{
			tmp = tmp->next;
			++i;
		}
		elem->next = tmp->next;
		tmp->next = elem;
	}
}
