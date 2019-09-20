/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:57:15 by skerkour          #+#    #+#             */
/*   Updated: 2017/09/27 16:27:56 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	ft_print_block(t_block *block)
{
	if (block == NULL || block->is_free)
		return ;
	ft_putaddr(BDATA(block));
	ft_putstr(" - ");
	ft_putaddr(BDATA(block) + block->size);
	ft_putstr(" : ");
	ft_putnbr(block->size);
	ft_putendl(" Bytes");
}

void	ft_show_page(t_page *page)
{
	t_block	*block;

	if (page->type == TINY)
		ft_putstr("TINY : ");
	else if (page->type == SMALL)
		ft_putstr("SMALL : ");
	else if (page->type == LARGE)
		ft_putstr("LARGE : ");
	ft_putaddr(page);
	ft_putchar('\n');
	block = page->first;
	while (block != NULL)
	{
		ft_print_block(block);
		block = block->next;
	}
}

void	show_alloc_mem(void)
{
	t_page	*page;

	page = ft_first_page();
	if (page == NULL)
		ft_putendl("Nothing to show");
	while (page != NULL)
	{
		ft_show_page(page);
		page = page->next;
	}
}
