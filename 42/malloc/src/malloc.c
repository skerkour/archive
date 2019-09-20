/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:37:11 by skerkour          #+#    #+#             */
/*   Updated: 2017/09/27 14:44:40 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_page	*ft_new_page(size_t size)
{
	t_page	*new_page;
	size_t	page_size;

	page_size = ft_page_length(size);
	new_page = (t_page*)mmap(NULL, page_size, PROT_READ | PROT_WRITE,
			MAP_PRIVATE | MAP_ANON, -1, 0);
	ft_init_page(new_page, page_size - PAGE_SIZE, size);
	ft_add_page(new_page);
	return (new_page);
}

void	ft_init_block(void *ptr, size_t size)
{
	t_block	*block;

	if (ptr == NULL)
		return ;
	block = (t_block*)ptr;
	block->size = size;
	block->next = NULL;
	block->prev = NULL;
	block->is_free = 0;
}

t_block	*ft_add_block_to_page(t_page *page, size_t size)
{
	t_block	*block;

	block = (t_block*)PDATA(page);
	ft_init_block(block, size);
	if (page->type != LARGE)
		ft_set_next_free_block(block, ft_page_length2(page->size) - BLOCK_SIZE);
	page->first = block;
	return (block);
}

t_block	*ft_new_block(size_t size)
{
	t_block	*block;
	t_page	*page;

	page = ft_new_page(size);
	block = ft_add_block_to_page(page, size);
	return (block);
}

void	*malloc(size_t size)
{
	t_block	*block;

	block = ft_find_free_space(size);
	if (block == NULL)
		block = ft_new_block(size);
	if (block == NULL)
		return (NULL);
	return (BDATA(block));
}
