/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:33:33 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/24 19:09:33 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

void	ft_lstdelone(t_lst **alst, void (*del)(void *, size_t))
{
	if (alst && *alst)
	{
		if (del)
			(*del)((*alst)->data, (*alst)->size);
		free((*alst)->data);
		free(*alst);
		*alst = NULL;
	}
}
