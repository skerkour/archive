/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 12:10:38 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/04 19:00:25 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

size_t	ft_lstlen(t_lst *lst)
{
	size_t	ret;

	ret = 0;
	if (lst)
	{
		while (lst)
		{
			++ret;
			lst = lst->next;
		}
	}
	return (ret);
}
