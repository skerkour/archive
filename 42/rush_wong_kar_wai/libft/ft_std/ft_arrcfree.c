/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrcfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 14:51:59 by skerkour          #+#    #+#             */
/*   Updated: 2014/12/13 14:55:24 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

void	ft_arrcfree(char ***array)
{
	t_uint	i;

	i = 0;
	while ((*array)[i])
	{
		free((*array)[i]);
		++i;
	}
	free((*array)[i]);
	free(*array);
	*array = NULL;
}
