/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_list_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 05:38:29 by skerkour          #+#    #+#             */
/*   Updated: 2014/12/08 14:16:01 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#define HCKLOL lsentry->name, hck->dcontent, hck->subdirs, args
#define HCKLOL2 hck->misc_type = hck->dent->d_type
#define GROSCON t_uint ret = 0;

static t_hack	*init_ls_hack(void)
{
	t_hack	*ret;

	ret = (t_hack*)ft_xmalloc(sizeof(t_hack));
	ret->dent = NULL;
	ret->args = NULL;
	ret->dcontent = NULL;
	ret->subdirs = NULL;
	ret->path = NULL;
	return (ret);
}

t_uint			ls_list_dir(t_lsentry *lsentry, t_lsargs *args)
{
	DIR		*dir;
	t_hack	*hck;

	GROSCON;
	if ((dir = opendir(lsentry->path)) == NULL)
	{
		ls_error(lsentry->name, FALSE);
		return (0);
	}
	hck = init_ls_hack();
	while ((hck->dent = readdir(dir)))
	{
		hck->path = ls_mkpath(lsentry->path, hck->dent->d_name);
		if (lstat(hck->path, &(hck->inf)) == -1)
		{
			ls_error(lsentry->name, FALSE);
			continue ;
		}
		ls_add_dcontent(args, hck);
		if (args->flags & FLAG_R && S_ISDIR(hck->inf.st_mode))
			ls_add_subdirs(args, hck, &ret);
		ft_memdel((void**)&(hck->path));
	}
	closedir(dir), ls_list_dir_cont(HCKLOL), free(hck);
	return (ret);
}

void			ls_add_dcontent(t_lsargs *args, t_hack *hck)
{
	if ((hck->dent->d_name)[0] == '.' && (!args || !(args->flags & FLAG_a)))
		return ;
	else
	{
		ft_lstadd_srt(&(hck->dcontent),
			ft_lstnew(
				ls_new_ent(ft_strdup(hck->path), &(hck->inf)),
				sizeof(t_lsentry)),
		args->flags & FLAG_t ? ls_cmpe_t : ls_cmpe_n);
	}
}

void			ls_add_subdirs(t_lsargs *args, t_hack *hck, t_uint *ret)
{
	if (ft_strcmp(hck->dent->d_name, ".") && ft_strcmp(hck->dent->d_name, ".."))
	{
		ft_lstadd_srt(&(hck->subdirs),
			ft_lstnew(
				ls_new_ent(ft_strdup(hck->path), &(hck->inf)),
				sizeof(t_lsentry)),
		args->flags & FLAG_t ? ls_cmpe_t : ls_cmpe_n);
		(*ret)++;
	}
}
