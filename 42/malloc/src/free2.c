/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:37:29 by skerkour          #+#    #+#             */
/*   Updated: 2016/12/15 17:38:35 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_block	*ft_find_ptr_in_page(t_page *page, void *ptr)
{
	t_block	*block;

	block = page->first;
	while (block != NULL)
	{
		if (ptr == BDATA(block))
			return (block);
		block = block->next;
	}
	return (NULL);
}

t_block	*ft_find_ptr(void *ptr)
{
	t_page	*page;
	t_block	*block;

	page = ft_first_page();
	while (page != NULL)
	{
		block = ft_find_ptr_in_page(page, ptr);
		if (block != NULL)
			return (block);
		page = page->next;
	}
	return (NULL);
}

t_page	**ft_get_first_page(void)
{
	static t_page	*first_page = NULL;

	return (&first_page);
}

t_page	*ft_first_page(void)
{
	return (*ft_get_first_page());
}
