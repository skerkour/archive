/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 11:59:12 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/08 11:59:14 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

t_ftstack	*ft_stack_init(void)
{
	t_ftstack	*ret;

	if ((ret = (t_ftstack*)malloc(sizeof(t_ftstack))) == NULL)
		return (NULL);
	ret->top = NULL;
	ret->size = 0;
	ret->push = (t_stack_fpp*)ft_stack_push;
	ret->pop = ft_stack_pop;
	ret->peek = ft_stack_peek;
	ret->destroy = ft_stack_destroy;
	return (ret);
}
