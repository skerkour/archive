/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:21:47 by skerkour          #+#    #+#             */
/*   Updated: 2017/09/27 17:28:58 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*ft_malloc_memcpy(void *ddest, void *ssrc, size_t n)
{
	char	*dest;
	char	*src;
	size_t	i;

	i = 0;
	dest = (char*)ddest;
	src = (char*)ssrc;
	if (dest == NULL || src == NULL)
		return (NULL);
	while (i < n)
	{
		dest[i] = src[i];
		i += 1;
	}
	return (dest);
}

t_block	*ft_merge(t_block *block, size_t size)
{
	t_block	*next;

	if (block == NULL)
		return (NULL);
	next = block->next;
	if (next == NULL || next->is_free == 0
		|| next->size + BLOCK_SIZE + block->size < size)
		return (NULL);
	block->size = size;
	block->next = next->next;
	ft_set_next_free_block(block, next + next->size + PAGE_SIZE - block);
	return (block);
}

void	*ft_realloc_help(t_block *block, size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (block != NULL && ret != NULL)
	{
		block->is_free = 1;
		ft_malloc_memcpy(ret, BDATA(block), block->size);
	}
	return (ret);
}

void	*realloc(void *ptr, size_t size)
{
	t_block	*block;
	t_block	*ret;

	if (ptr == NULL)
		return (ft_realloc_help(NULL, size));
	block = ft_find_ptr(ptr);
	if (block == NULL)
		return (NULL);
	ret = ft_merge(block, size);
	if (ret == NULL)
		return (ft_realloc_help(block, size));
	return (ptr);
}
