/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 12:26:06 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/08 12:26:09 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ftbuffer	*ft_stack_pop(t_ftstack **this)
{
	t_ftbuffer		*ret;
	t_stack_elem	*tmp;

	if (this && *this)
	{
		ret = (*this)->top->data;
		if (!ret)
			return (NULL);
		tmp = (*this)->top;
		(*this)->top = (*this)->top->next;
		if (tmp)
			ft_memdel((void**)&tmp);
		(*this)->size--;
		return (ret);
	}
	return (NULL);
}
