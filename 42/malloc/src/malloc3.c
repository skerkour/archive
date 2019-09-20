/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:48:11 by skerkour          #+#    #+#             */
/*   Updated: 2016/12/15 17:51:31 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t	ft_page_length(size_t size)
{
	if (size <= TINY_SIZE)
		return (TINY_LENGTH);
	else if (size <= SMALL_SIZE)
		return (SMALL_LENGTH);
	else
		return (size + PAGE_SIZE);
}

size_t	ft_page_length2(t_page_type size)
{
	if (size == TINY)
		return (TINY_LENGTH);
	else if (size == SMALL)
		return (SMALL_LENGTH);
	else
		return (size);
}
