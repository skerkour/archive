/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_suffix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 14:15:10 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/09 14:15:11 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_suffix(t_btree *root, void (*applyf)(t_ftbuffer *))
{
	if (root && applyf)
	{
		if (root->left)
			ft_btree_apply_suffix(root->left, applyf);
		if (root->right)
			ft_btree_apply_suffix(root->right, applyf);
		(*applyf)(root->data);
	}
}
