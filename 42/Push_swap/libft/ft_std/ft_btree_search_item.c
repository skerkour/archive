/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_search_item.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 14:20:21 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/09 14:20:22 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_btree_search_item(t_btree *root, t_ftbuffer *data_ref,
			int (*cmpf)(t_ftbuffer *, t_ftbuffer *))
{
	if (root && cmpf && data_ref)
	{
		if (!(*cmpf)(data_ref, root->data))
			return (root);
		else
		{
			if (root->left)
				return (ft_btree_search_item(root->left, data_ref, cmpf));
			if (root->right)
				return (ft_btree_search_item(root->left, data_ref, cmpf));
		}
	}
	return (NULL);
}
