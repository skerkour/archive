/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_create_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 14:09:47 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/21 15:58:42 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

t_btree	*ft_btree_create_node(void *data, size_t size)
{
	t_btree	*new;

	new = NULL;
	if ((new = (t_btree *)malloc(sizeof(t_btree))) == NULL)
		return (NULL);
	if ((new->data = ft_memdup(data, size)) == NULL)
	{
		free(new);
		return (NULL);
	}
	new->left = NULL;
	new->right = NULL;
	return (new);
}
