/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 10:47:49 by skerkour          #+#    #+#             */
/*   Updated: 2014/12/10 21:57:39 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_error(char *error, t_bool bexit)
{
	ft_putstr_fd("ft_ls: ", 2);
	perror(error);
	if (bexit)
		exit(-1);
}

void	ls_process_files(t_lsargs *args)
{
	t_lst		*elem;
	t_l_form	forml;

	ls_l_form_init(&forml);
	if (args->flags & FLAG_l)
		ls_l_count(args->files, &forml, NULL);
	while ((elem = ft_lstpop(&(args->files))) != NULL)
	{
		if (args->flags & FLAG_l)
			ls_pinfos((t_lsentry*)elem->data, &forml);
		if (ft_strcountc(((t_lsentry*)elem->data)->path, '/') >= 1)
			ls_ppath((t_lsentry*)elem->data);
		else
			ls_pname((t_lsentry*)elem->data);
		if (S_ISLNK(((t_lsentry*)elem->data)->infos.st_mode)
			&& args->flags & FLAG_l)
			ls_l_plink(((t_lsentry*)elem->data)->path);
		ft_putchar('\n');
		ft_lstdelone(&elem, ls_del_ent);
	}
}

void	ls_process_args(t_lsargs *args)
{
	t_lst	*elem;

	elem = NULL;
	while ((elem = ft_lstpop(&(args->unk))) != NULL)
		ls_error((char*)elem->data, FALSE);
	if (args->nfiles)
		ls_process_files(args);
	if (args->ndirs)
	{
		if (args->nfiles)
			ft_putchar('\n');
		ls_process_dirs(args);
	}
}

void	ls_list_current(t_lsargs *args)
{
	struct stat	inf;
	t_lsentry	*loc;

	if (stat(".", &inf) == -1)
		return ;
	loc = ls_new_ent(".", &inf);
	loc->path = ft_strdup(".");
	if (args)
		ls_list_dir(loc, args);
	else
		ls_list_dir(loc, args);
	ls_del_ent(loc, sizeof(t_lsentry));
}

int		main(int ac, char **av)
{
	t_lsargs	*args;

	if (ac > 1)
	{
		args = ls_args(ac, av);
		if (!(args->nunk) && !(args->files) && !(args->dirs))
			ls_list_current(args);
		else
			ls_process_args(args);
	}
	else
	{
		args = ls_targs_new();
		ls_list_current(args);
	}
	free(args);
	return (0);
}
