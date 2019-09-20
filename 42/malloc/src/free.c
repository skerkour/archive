/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:20:58 by skerkour          #+#    #+#             */
/*   Updated: 2016/12/15 17:50:47 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_page	*ft_page_of_block(t_block *block)
{
	t_page	*page;

	if (block == NULL)
		return (NULL);
	page = ft_first_page();
	while ((void*)page < (void*)block)
	{
		if ((void*)page < (void*)block
			&& PDATA(page) + page->size > (void*)block)
			return (page);
		page = page->next;
	}
	return (NULL);
}

void	ft_delete_page(t_page *page)
{
	if (page->prev == NULL && page->next != NULL)
		*ft_get_first_page() = NULL;
	if (page->prev != NULL)
		page->prev->next = page->next;
	else
		*ft_get_first_page() = page->next;
	if (page->next != NULL)
	{
		page->next->prev = page->prev;
	}
	munmap(page, page->size + PAGE_SIZE);
}

t_block	*ft_merge_blocks(t_block *start)
{
	t_block	*end;

	end = start;
	while (start->prev != NULL && start->prev->is_free)
		start = start->prev;
	while (end->next != NULL && end->next->is_free)
		end = end->next;
	if (start == end)
	{
		start->is_free = 1;
		return (start);
	}
	start->size = BDATA(end) + end->size - BDATA(start);
	start->next = end->next;
	start->is_free = 1;
	return (start);
}

void	ft_check_page(t_block *block)
{
	t_page	*page;
	t_block	*first_block;

	page = ft_page_of_block(block);
	first_block = page->first;
	if (first_block != NULL && first_block->is_free && first_block->next != NULL
		&& page->prev != NULL && page->next != NULL)
		ft_delete_page(page);
}

void	free(void *ptr)
{
	t_block *block;

	if (ptr == NULL)
		return ;
	block = ft_find_ptr(ptr);
	if (block == NULL)
		return ;
	block = ft_merge_blocks(block);
	ft_check_page(block);
}
