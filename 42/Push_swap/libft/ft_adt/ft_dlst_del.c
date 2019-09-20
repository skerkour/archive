/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 17:02:04 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/06 23:13:44 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

void	ft_dlst_del(t_dlst **lst)
{
	t_dlst	*tmp;

	if (*lst)
	{
		while ((*lst)->prev)
			*lst = (*lst)->prev;
		while (*lst)
		{
			tmp = (*lst)->next;
			free((*lst)->data), free(*lst);
			*lst = tmp;
		}
		*lst = NULL;
	}
}
