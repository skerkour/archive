/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 11:04:43 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/21 15:43:01 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

t_dlst	*ft_dlstmew(void *data, size_t size)
{
	t_dlst	*ret;

	if ((ret = (t_dlst*)malloc(sizeof(t_dlst))) == NULL)
		return (NULL);
	if ((ret->data = (void*)malloc(size)) == NULL)
	{
		free(ret);
		return (NULL);
	}
	ft_memcpy(ret->data, data, size);
	ret->size = size;
	ret->next = NULL;
	ret->prev = NULL;
	return (ret);
}
