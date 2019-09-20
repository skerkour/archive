/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 19:40:47 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/16 19:40:49 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_lst **top, t_lst *elem)
{
	if (!*top)
		*top = elem;
	else
	{
		elem->next = *top;
		*top = elem;
	}
}
