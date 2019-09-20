/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 20:56:10 by skerkour          #+#    #+#             */
/*   Updated: 2014/12/09 00:46:04 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_end(t_lst **top, void (*del)(t_lst*))
{
	t_lst	*tmp;
	t_lst	*prev;

	if (*top)
	{
		tmp = *top;
		if (tmp->next)
		{
			while (tmp->next)
			{
				prev = tmp;
				tmp = tmp->next;
			}
			(*del)(tmp);
			prev->next = NULL;
		}
		else
		{
			(*del)(*top);
			*top = NULL;
		}
	}
}
