/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_prefix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 14:11:30 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/21 15:59:14 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_prefix(t_btree *root, void (*applyf)(t_btree*))
{
	if (root && applyf)
	{
		(*applyf)(root);
		if (root->left)
			ft_btree_apply_prefix(root->left, applyf);
		if (root->right)
			ft_btree_apply_prefix(root->right, applyf);
	}
}
