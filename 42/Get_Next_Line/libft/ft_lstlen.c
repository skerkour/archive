/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 12:10:38 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/06 12:10:40 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_uint	ft_lstlen(t_list *lst)
{
	t_uint	ret;

	ret = 0;
	if (lst)
	{
		while (lst)
			++ret, lst = lst->next;
	}
	return (ret);
}
