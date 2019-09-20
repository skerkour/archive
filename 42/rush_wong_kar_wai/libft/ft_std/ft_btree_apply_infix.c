/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_infix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 14:13:30 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/09 14:13:31 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_infix(t_btree *root, void (*applyf)(t_ftbuffer *))
{
	if (root && applyf)
	{
		if (root->left)
			ft_btree_apply_infix(root->left, applyf);
		(*applyf)(root->data);
		if (root->right)
			ft_btree_apply_infix(root->right, applyf);
	}
}
