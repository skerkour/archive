/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 10:41:20 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/08 10:41:21 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

void	*ft_memdup(void *src, t_uint n)
{
	void	*ret;

	if ((ret = (void*)malloc(n)) == NULL)
		return (NULL);
	ft_memcpy(ret, src, n);
	return (ret);
}
