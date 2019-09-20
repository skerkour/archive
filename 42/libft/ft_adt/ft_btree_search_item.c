/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_search_item.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 14:20:21 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/21 16:22:20 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_btree_search_item(t_btree *root, void *data_ref,
			size_t size, int (*cmpf)(void*, void*, size_t))
{
	if (root && cmpf && data_ref)
	{
		if (!(*cmpf)(data_ref, root->data, size))
			return (root);
		else
		{
			if (root->left)
				return (ft_btree_search_item(root->left, data_ref, size, cmpf));
			if (root->right)
				return (ft_btree_search_item(root->left, data_ref, size, cmpf));
		}
	}
	return (NULL);
}
