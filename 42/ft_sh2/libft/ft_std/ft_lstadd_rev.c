/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 11:15:17 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/24 11:15:18 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_rev(t_lst **top, t_lst *elem, int (*cmp)(t_lst*, t_lst*))
{
	t_lst	*tmp;
	t_lst	*prev;

	if (!*top)
		ft_lstpush(top, elem);
	else
	{
		prev = *top;
		if ((*cmp)(prev, elem) >= 0)
		{
			elem->next = *top;
			*top = elem;
			return ;
		}
		tmp = (*top)->next;
		while (tmp)
		{
			if ((*cmp)(tmp, elem) >= 0)
				break ;
			prev = tmp;
			tmp = tmp->next;
		}
		elem->next = tmp;
		prev->next = elem;
	}
}
