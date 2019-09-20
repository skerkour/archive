/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 20:56:10 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/16 20:56:11 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_end(t_lst **top, void (*del)(t_lst*))
{
	t_lst	*tmp;

	if (*top)
	{
		tmp = *top;
		while (tmp->next)
			tmp = tmp->next;
		(*del)(tmp);
	}
}
