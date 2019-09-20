/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_level_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 14:23:11 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/09 14:23:13 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_btree_lvl_c(t_btree *root)
{
	if (root)
		return (1 + ft_btree_lvl_c(root->left) + ft_btree_lvl_c(root->right));
	else
		return (0);
}
