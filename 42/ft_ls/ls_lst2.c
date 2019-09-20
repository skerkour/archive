/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lst2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 15:19:38 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/28 15:19:39 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_del_ent(void *entry, size_t size)
{
	if (entry)
		free(((t_lsentry*)entry)->path);
	UNUSED(size);
}

void	ls_del_unk(void *name, size_t size)
{
	free(name);
	UNUSED(size);
}
