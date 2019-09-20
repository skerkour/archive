/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_dirs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 11:06:26 by skerkour          #+#    #+#             */
/*   Updated: 2014/12/08 14:22:18 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#define HCK args->flags & FLAG_a
#define HCK2 !ft_strcmp(name, ".") || !ft_strcmp(name, "..")
#define HCKLOL1 ft_putstr(((t_lsentry*)el->data)->path),
#define HCKLOL 	HCKLOL1 ft_putchar(':'), ft_putchar('\n')
#define FTDODO	(((t_lsentry*)el->data)->name[0] != '.' || HCK)

void			ls_list_dir_cont(char *name, t_lst *dcontent, t_lst *subdirs,
							t_lsargs *args)
{
	t_lst	*el;
	t_uint	sub_count;

	if ((name[0] != '.' || HCK2) || HCK)
	{
		if (args->flags & FLAG_l && dcontent)
			ls_l_tblock(dcontent);
		ls_display_cont(dcontent, args);
	}
	if (args->flags & FLAG_R)
	{
		if (subdirs && ((name[0] != '.' || !ft_strcmp(name, ".")) || HCK))
			ft_putchar('\n');
		if (args->flags & FLAG_r)
			ft_lstrev(&subdirs);
		while ((el = ft_lstpop(&subdirs)) != NULL)
		{
			if (((t_lsentry*)el->data)->name[0] != '.' || HCK)
				HCKLOL;
			sub_count = ls_list_dir((t_lsentry*)el->data, args);
			if ((el->next || (el->next && sub_count)) && FTDODO)
				ft_putchar('\n');
			ft_lstdelone(&el, ls_del_ent);
		}
	}
}

char			*ls_mkpath(char *left, char *right)
{
	char	*ret;

	if (left && !right)
		return (ft_strdup(left));
	else if (right && !left)
		return (ft_strdup(right));
	else
	{
		ret = (char*)ft_xmalloc(ft_strlen(left) + ft_strlen(right) + 2);
		ft_strcpy(ret, left);
		if (ft_strcmp(left, "/"))
			ft_strcat(ret, "/");
		ft_strcat(ret, right);
		return (ret);
	}
}

void			ls_display_cont(t_lst *list, t_lsargs *args)
{
	t_lst		*el;
	t_l_form	form;

	ls_l_form_init(&form);
	if (args->flags & FLAG_l)
		ls_l_count(list, &form, NULL);
	if (args->flags & FLAG_r)
		ft_lstrev(&list);
	while ((el = ft_lstpop(&(list))) != NULL)
	{
		if (((t_lsentry*)el->data)->name[0] == '.' && !(args->flags & FLAG_a))
			continue ;
		if (args->flags & FLAG_l)
			ls_pinfos((t_lsentry*)el->data, &form);
		ls_pname((t_lsentry*)el->data);
		if (S_ISLNK(((t_lsentry*)el->data)->infos.st_mode)
				&& args->flags & FLAG_l)
			ls_l_plink(((t_lsentry*)el->data)->path);
		ft_putchar('\n');
		ft_lstdelone(&el, ls_del_ent);
	}
}

void			ls_process_dirs(t_lsargs *args)
{
	t_lst	*elem;

	elem = NULL;
	while ((elem = ft_lstpop(&args->dirs)))
	{
		if (args->ndirs > 1 || args->nfiles || args->nunk)
		{
			ft_putstr(((t_lsentry*)elem->data)->path);
			ft_putchar(':');
			ft_putchar('\n');
		}
		ls_list_dir((t_lsentry*)elem->data, args);
		if (elem->next)
			ft_putchar('\n');
		ft_lstdelone(&elem, NULL);
	}
}
