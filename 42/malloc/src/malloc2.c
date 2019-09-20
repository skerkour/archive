/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:47:12 by skerkour          #+#    #+#             */
/*   Updated: 2016/12/15 17:48:42 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	ft_set_next_free_block(t_block *block, size_t block_size)
{
	t_block	*next_block;

	if (block->size + BLOCK_SIZE == block_size)
		return ;
	if (block_size < block->size + BLOCK_SIZE * 2)
	{
		block->size = block_size - BLOCK_SIZE;
		return ;
	}
	next_block = (t_block*)(BDATA(block) + block->size - 1);
	ft_init_block(next_block, block_size - BLOCK_SIZE * 2 - block->size);
	next_block->next = block->next;
	block->next = next_block;
	next_block->prev = block;
	next_block->is_free = 1;
}

t_block	*ft_find_free_space_in_page(t_page *page, size_t size)
{
	t_block	*block;

	block = page->first;
	while (block != NULL)
	{
		if (block->is_free == 1 && block->size >= size)
			return (block);
		block = block->next;
	}
	return (block);
}

t_block	*ft_find_free_space(size_t size)
{
	t_page		*page;
	t_page_type	page_type;
	t_block		*ret;
	size_t		block_size;

	page_type = ft_get_page_type(size);
	page = ft_first_page();
	ret = NULL;
	while (page != NULL)
	{
		if (ret != NULL)
			break ;
		if (page->type == page_type)
			ret = ft_find_free_space_in_page(page, size);
		page = page->next;
	}
	if (ret == NULL)
		return (NULL);
	block_size = ret->size + BLOCK_SIZE;
	ret->size = size;
	ft_set_next_free_block(ret, block_size);
	ret->is_free = 0;
	return (ret);
}

void	ft_add_page(t_page *page)
{
	t_page	*last_page;

	if (ft_first_page() == NULL)
		*ft_get_first_page() = page;
	else
	{
		last_page = ft_first_page();
		while (last_page->next != NULL)
			last_page = last_page->next;
		page->prev = last_page;
		last_page->next = page;
	}
}

void	ft_init_page(void *ptr, t_page_type size, size_t block_size)
{
	t_page	*page;

	page = (t_page*)ptr;
	page->type = ft_get_page_type(block_size);
	page->size = size;
	page->prev = NULL;
	page->next = NULL;
	page->first = NULL;
}
