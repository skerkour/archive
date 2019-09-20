/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 12:37:56 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/08 12:37:58 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_stack_destroy(t_ftstack **this)
{
	t_stack_elem	*tmp;

	if (this && *this)
	{
		while ((*this)->top)
		{
			tmp = (*this)->top->next;
			ft_memdel((void**)&(*this)->top);
			(*this)->top = tmp;
		}
	}
	return (FALSE);
}
