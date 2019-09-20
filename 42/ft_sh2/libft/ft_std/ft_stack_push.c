/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 12:04:10 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/08 12:04:12 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

t_bool	ft_stack_push(t_ftstack **this, t_ftbuffer *data)
{
	t_stack_elem	*el;

	if (this && *this && data)
	{
		if ((el = (t_stack_elem*)malloc(sizeof(t_stack_elem))) == NULL)
			return (FALSE);
		el->data = data;
		el->next = (*this)->top;
		(*this)->top = el;
		(*this)->size++;
		return (TRUE);
	}
	return (FALSE);
}
