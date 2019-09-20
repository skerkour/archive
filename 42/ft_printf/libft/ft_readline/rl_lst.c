/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 10:13:00 by skerkour          #+#    #+#             */
/*   Updated: 2014/12/09 10:24:55 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** free
*/
#include <stdlib.h>

#include "priv_readline.h"

t_lst	*rl_lstnewel(char c)
{
	t_lst	*ret;

	ret = (t_lst*)ft_xmalloc(sizeof(t_lst));
	ret->data = (void*)ft_xmalloc(1);
	*((char*)ret->data) = c;
	ret->next = NULL;
	ret->size = 1;
	return (ret);
}

void	rl_lstdel_el(t_lst *letter)
{
	free(letter->data);
	free(letter);
}
