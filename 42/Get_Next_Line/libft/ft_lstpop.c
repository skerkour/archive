/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 19:48:32 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/16 19:48:33 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lstpop(t_lst **top)
{
	t_lst	*ret;

	if (!*top)
		return (NULL);
	else
	{
		ret = *top;
		*top = ret->next;
	}
	return (ret);
}
