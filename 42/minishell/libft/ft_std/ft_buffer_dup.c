/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 14:36:52 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/09 14:36:54 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

t_ftbuffer	*ft_buffer_dup(t_ftbuffer *buf)
{
	t_ftbuffer	*ret;

	ret = NULL;
	if (buf)
		ret = ft_buffer_new(buf->data, buf->size);
	return (ret);
}
