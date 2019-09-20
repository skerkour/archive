/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 23:18:21 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/16 23:18:22 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

t_lst	*ft_lstnew(void *data, t_ulong size)
{
	t_lst	*ret;

	if ((ret = (t_lst*)malloc(sizeof(t_lst))) == NULL)
		return (NULL);
	if ((ret->data = (void*)malloc(size)) == NULL)
	{
		free(ret);
		return (NULL);
	}
	ft_memcpy(ret->data, data, size);
	ret->size = size;
	ret->next = NULL;
	return (ret);
}
