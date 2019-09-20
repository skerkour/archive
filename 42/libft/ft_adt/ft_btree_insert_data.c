/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 14:17:05 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/21 16:17:25 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_insert_data(t_btree **root, void *data,
			int (*cmpf)(void*, void*, size_t))
{
	t_btree	*new;

	new = ft_btree_create_node(data, (*root)->size);
	if (root)
	{
		if (*root)
		{
			if ((*cmpf)((*root)->data, data, (*root)->size) > 0)
				ft_btree_insert_data(&(*root)->left, data, cmpf);
			else
				ft_btree_insert_data(&(*root)->right, data, cmpf);
		}
		else
			*root = new;
	}
}
