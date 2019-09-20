/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_create_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 14:09:47 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/09 14:09:48 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

t_btree	*ft_btree_create_node(t_ftbuffer *item)
{
	t_btree	*new;

	new = NULL;
	if (item)
	{
		if ((new = (t_btree *)malloc(sizeof(t_btree))) == NULL)
			return (NULL);
		if ((new->data = ft_buffer_dup(item)) == NULL)
		{
			free(new);
			return (NULL);
		}
		new->left = NULL;
		new->right = NULL;
	}
	return (new);
}
