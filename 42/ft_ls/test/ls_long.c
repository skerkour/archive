/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 13:00:55 by skerkour          #+#    #+#             */
/*   Updated: 2014/12/04 16:20:08 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_pname(t_lsentry *entry)
{
	if (S_ISLNK(entry->infos.st_mode))
		ft_putstr(MAGE);
	else if (S_ISDIR(entry->infos.st_mode))
		ft_putstr(CYAN);
	else if (entry->infos.st_mode & S_IXUSR || entry->infos.st_mode & S_IXGRP
		|| entry->infos.st_mode & S_IXOTH)
		ft_putstr(RED);
	else if (S_ISCHR(entry->infos.st_mode))
		ft_putstr(CHRCLR);
	else if (S_ISBLK(entry->infos.st_mode))
		ft_putstr(BLKCLR);
	ft_putstr(entry->name);
	if (S_ISLNK(entry->infos.st_mode) || S_ISDIR(entry->infos.st_mode) ||
			entry->infos.st_mode & S_IXUSR || entry->infos.st_mode & S_IXGRP
			|| entry->infos.st_mode & S_IXOTH || S_ISCHR(entry->infos.st_mode)
			|| S_ISBLK(entry->infos.st_mode))
		ft_putstr(CEND);
}

void	ls_ppath(t_lsentry *entry)
{
	if (S_ISLNK(entry->infos.st_mode))
		ft_putstr(MAGE);
	else if (S_ISDIR(entry->infos.st_mode))
		ft_putstr(CYAN);
	else if (entry->infos.st_mode & S_IXUSR || entry->infos.st_mode & S_IXGRP
		|| entry->infos.st_mode & S_IXOTH)
		ft_putstr(RED);
	else if (S_ISCHR(entry->infos.st_mode))
		ft_putstr(CHRCLR);
	else if (S_ISBLK(entry->infos.st_mode))
		ft_putstr(BLKCLR);
	ft_putstr(entry->path);
	if (S_ISLNK(entry->infos.st_mode) || S_ISDIR(entry->infos.st_mode) ||
			entry->infos.st_mode & S_IXUSR || entry->infos.st_mode & S_IXGRP
			|| entry->infos.st_mode & S_IXOTH || S_ISCHR(entry->infos.st_mode)
			|| S_ISBLK(entry->infos.st_mode))
		ft_putstr(CEND);
}

void	ls_pinfos(t_lsentry *entry, t_l_form *format)
{
	ls_l_ptype(entry);
	ls_l_pperms(entry->infos.st_mode);
	ls_l_pext_inf(entry->path);
	ft_putchar(' ');
	ls_l_pnlinks(entry->infos.st_nlink, format->msl);
	ft_putchar(' ');
	ls_l_puname(entry->infos.st_uid, format->msu);
	ft_putstr("  ");
	ls_l_pgname(entry->infos.st_gid, format->msg);
	ft_putstr("  ");
	if (S_ISBLK(entry->infos.st_mode) || S_ISCHR(entry->infos.st_mode))
		ls_l_pmajmin(entry, format->mmin, format->mmaj);
	else
		ls_l_psize(entry->infos.st_size, format->mss);
	ft_putchar(' ');
	ls_l_pmtime(&(entry->infos.st_mtimespec.tv_sec));
	ft_putchar(' ');
}

void	ls_l_form_init(t_l_form *format)
{
	format->msl = 0;
	format->msu = 0;
	format->msg = 0;
	format->mss = 0;
	format->mmaj = 0;
	format->mmin = 0;
	format->tblock = 0;
}

void	ls_l_count(t_lst *el, t_l_form *form, char *tmp)
{
	struct passwd	*pawd;
	struct group	*ggd;

	while (el)
	{
		form->msl = ft_count_isize(((t_lsentry*)el->data)->infos.st_nlink) >
			form->msl ? ft_count_isize(
			((t_lsentry*)el->data)->infos.st_nlink) : form->msl;
		if ((pawd = getpwuid(((t_lsentry*)el->data)->infos.st_uid)) == NULL)
			tmp = ft_itoa(((t_lsentry*)el->data)->infos.st_uid);
		else
			tmp = ft_strdup(pawd->pw_name);
		form->msu = ft_strlen(tmp) > form->msu ? ft_strlen(tmp) : form->msu;
		free(tmp);
		if ((ggd = getgrgid(((t_lsentry*)el->data)->infos.st_gid)) == NULL)
			tmp = ft_itoa(((t_lsentry*)el->data)->infos.st_uid);
		else
			tmp = ft_strdup(ggd->gr_name);
		free(tmp);
		form->msg = ft_strlen(tmp) > form->msg ? ft_strlen(tmp) : form->msg;
		form->mss = ls_l_countweigth(form, (t_lsentry*)el->data);
		el = el->next;
	}
}
