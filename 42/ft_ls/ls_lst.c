/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 10:47:41 by skerkour          #+#    #+#             */
/*   Updated: 2014/12/03 19:47:00 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ls_cmpe_t(t_lst *a, t_lst *b)
{
	if (((t_lsentry*)b->data)->infos.st_mtimespec.tv_sec
		!= ((t_lsentry*)a->data)->infos.st_mtimespec.tv_sec)
		return ((int)(((t_lsentry*)b->data)->infos.st_mtimespec.tv_sec
		- ((t_lsentry*)a->data)->infos.st_mtimespec.tv_sec));
	else
		return (ls_cmpe_n(a, b));
}

int			ls_cmpe_n(t_lst *a, t_lst *b)
{
	return (ft_strcmp(((t_lsentry*)a->data)->name,
	((t_lsentry*)b->data)->name));
}

int			ls_cmpe_p(t_lst *a, t_lst *b)
{
	return (ft_strcmp(((t_lsentry*)a->data)->path,
	((t_lsentry*)b->data)->path));
}

int			ls_cmpu_n(t_lst *a, t_lst *b)
{
	return (ft_strcmp(a->data, b->data));
}

t_lsentry	*ls_new_ent(char *path, struct stat *infos)
{
	t_lsentry *ret;

	ret = (t_lsentry*)ft_xmalloc(sizeof(t_lsentry));
	ft_memcpy(&(ret->infos), infos, sizeof(struct stat));
	ret->path = path;
	ret->name = ls_xtrct_name(path);
	return (ret);
}
