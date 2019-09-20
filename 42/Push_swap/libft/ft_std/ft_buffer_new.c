/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 14:43:29 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/09 14:43:30 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

t_ftbuffer	*ft_buffer_new(void *data, t_ulong size)
{
	t_ftbuffer	*ret;

	ret = NULL;
	if (data && size != 0)
	{
		if ((ret = (t_ftbuffer*)malloc(sizeof(t_ftbuffer))) == NULL)
			return (NULL);
		if ((ret->data = (void*)malloc(size)) == NULL)
		{
			free(ret);
			return (NULL);
		}
		ft_memcpy(ret->data, data, size);
		ret->size = size;
	}
	return (ret);
}
