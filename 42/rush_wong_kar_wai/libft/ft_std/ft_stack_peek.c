/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_peek.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 12:35:53 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/08 12:35:55 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ftbuffer	*ft_stack_peek(t_ftstack **this)
{
	if (this && *this)
		return ((*this)->top->data);
	return (NULL);
}
