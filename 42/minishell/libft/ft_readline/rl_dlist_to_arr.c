/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_dlist_to_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 16:38:36 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/07 12:57:51 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "priv_readline.h"

char	*rl_dlist_to_arr(t_dlst *line)
{
	char	*ret;
	t_uint	i;

	if ((ret = (char*)malloc(line ? ft_dlstlen(line) : 0 + 1)) == NULL)
		return (NULL);
	if (line)
		while (line->prev)
			line = line->prev;
	i = 0;
	while (line)
	{
		ret[i++] = *((char*)line->data);
		line = line->next;
	}
	ret[i] = 0;
	return (ret);
}
