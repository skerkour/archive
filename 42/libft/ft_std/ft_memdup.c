/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 10:41:20 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/21 15:57:29 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

void	*ft_memdup(void *src, size_t n)
{
	void	*ret;

	if ((ret = (void*)malloc(n)) == NULL)
		return (NULL);
	ft_memcpy(ret, src, n);
	return (ret);
}
