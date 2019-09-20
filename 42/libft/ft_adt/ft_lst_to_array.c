/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 21:30:28 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/22 09:39:32 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "ft_lst.h"

void	*ft_lst_to_array(t_lst *lst)
{
	size_t	len;
	void	*ret;
	size_t	elem_len;
	size_t	i;

	if ((len = ft_lstlen(lst)) == 0)
		return (NULL);
	elem_len = lst->size;
	if ((ret = malloc(len * elem_len)) == NULL)
		return (NULL);
	i = 0;
	while (lst)
	{
		ft_memcpy(&(ret[i]), lst->data, elem_len);
		lst = lst->next;
		i += 1;
	}
	return (ret);
}
