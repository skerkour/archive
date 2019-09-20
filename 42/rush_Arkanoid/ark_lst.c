/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 15:55:54 by skerkour          #+#    #+#             */
/*   Updated: 2015/05/02 22:57:32 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
#include "libft_ext.h"

void	ark_enqueue_lvl(t_list **lst, char *filename)
{
	t_list	*tmp;

	if (filename)
	{
		if (!*lst)
			*lst = ft_lstnew((void*)filename, ft_strlen(filename) + 1);
		else
		{
			tmp = *lst;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = ft_lstnew((void*)filename, ft_strlen(filename) + 1);
		}
		free(filename);
	}
}
