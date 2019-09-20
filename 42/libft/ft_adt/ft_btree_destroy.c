/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 14:33:37 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/21 16:22:49 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

void	ft_btree_destroy(t_btree **root)
{
	if (root && *root)
	{
		if ((*root)->left)
			ft_btree_destroy(&(*root)->left);
		if ((*root)->right)
			ft_btree_destroy(&(*root)->right);
		free((*root)->data);
		free(*root);
		*root = NULL;
	}
}
