/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 11:35:23 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/08 11:35:24 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

int		ft_memreaalloc(void **ptr, t_uint osize, t_uint nsize)
{
	void	*ret;

	if ((ret = (void*)malloc(nsize)) == NULL)
		return (0);
	ft_memcpy(ret, *ptr, osize);
	ft_memdel(ptr);
	*ptr = ret;
	return (1);
}
