/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xmalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 19:22:24 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/15 19:22:28 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

void	*ft_xmalloc(size_t n)
{
	void	*ret;

	if ((ret = (void*)malloc(n)) == NULL)
	{
		ft_putendl_fd("fatal error with malloc()... exiting", FT_STDERR);
		exit(-1);
	}
	return (ret);
}
