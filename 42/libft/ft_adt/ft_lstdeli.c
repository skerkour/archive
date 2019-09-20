/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdeli.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 11:08:21 by skerkour          #+#    #+#             */
/*   Updated: 2014/12/09 12:38:48 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

void	ft_lstdeli(t_lst **top, size_t pos, void (*del)(t_lst*))
{
	t_lst	*prev;
	t_lst	*tmp;
	size_t	i;

	if (pos == 0)
	{
		tmp = *top;
		(*del)(tmp);
		*top = (*top)->next;
	}
	else
	{
		i = 0;
		tmp = *top;
		while (i++ < pos && tmp)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		if (tmp)
		{
			prev->next = tmp->next;
			(*del)(tmp);
		}
	}
}
