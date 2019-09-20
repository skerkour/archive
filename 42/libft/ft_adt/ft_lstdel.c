/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 20:59:58 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/16 20:59:59 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_lst **top, void (*del)(t_lst*))
{
	t_lst	*tmp;

	if (*top)
	{
		while (*top)
		{
			tmp = (*top)->next;
			if (del)
				(*del)(*top);
			*top = tmp;
		}
	}
}
