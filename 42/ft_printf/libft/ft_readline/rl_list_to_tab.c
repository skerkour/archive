/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_list_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 13:28:48 by skerkour          #+#    #+#             */
/*   Updated: 2014/12/09 13:29:16 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** free
*/
#include <stdlib.h>

#include "priv_readline.h"

char	*rl_list_to_tab(t_lst **line)
{
	char	*ret;
	t_uint	i;
	t_lst	*tmp;

	ret = (char*)ft_xmalloc(ft_lstlen(*line) + 1);
	i = 0;
	while (*line)
	{
		tmp = *line;
		ret[i++] = *((char*)(*line)->data);
		(*line) = (*line)->next;
		free(tmp->data);
		free(tmp);
	}
	ret[i] = 0;
	*line = NULL;
	return (ret);
}
