/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 14:39:21 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/09 14:39:23 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

void	ft_buffer_destroy(t_ftbuffer **buf)
{
	if (buf && *buf)
	{
		free((*buf)->data);
		free(*buf);
		*buf = NULL;
	}
}
