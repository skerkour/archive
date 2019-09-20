/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_long4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 17:31:15 by skerkour          #+#    #+#             */
/*   Updated: 2014/12/03 22:02:19 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_l_pext_inf(char *path)
{
	UNUSED(path);
	ft_putchar(' ');
}

void	ls_l_pmajmin(t_lsentry *entry, t_ushort nmin, t_ushort nmaj)
{
	t_ushort	tmin;
	t_ushort	tmaj;

	tmin = ft_count_isize(LS_MINOR(entry->infos.st_rdev));
	tmaj = ft_count_isize(LS_MAJOR(entry->infos.st_rdev));
	ft_putchar(' ');
	if (tmaj < nmaj)
		while (nmaj-- > tmaj)
			ft_putchar(' ');
	ft_putnbr(LS_MAJOR(entry->infos.st_rdev));
	ft_putstr(", ");
	if (tmin < nmin)
		while (nmin-- > tmin)
			ft_putchar(' ');
	ft_putnbr(LS_MINOR(entry->infos.st_rdev));
}

t_uint	ls_l_countweigth(t_l_form *form, t_lsentry *entry)
{
	t_uint	a;

	if (S_ISCHR(entry->infos.st_mode) || S_ISBLK(entry->infos.st_mode))
	{
		a = ft_count_isize(LS_MAJOR(entry->infos.st_rdev))
			+ 4
			+ ft_count_isize(LS_MINOR(entry->infos.st_rdev));
		form->mmaj = ft_count_isize(LS_MAJOR(entry->infos.st_rdev))
			> form->mmaj ? ft_count_isize(LS_MAJOR(entry->infos.st_rdev)) :
			form->mmaj;
		form->mmin = ft_count_isize(LS_MINOR(entry->infos.st_rdev))
			> form->mmin ? ft_count_isize(LS_MINOR(entry->infos.st_rdev)) :
			form->mmin;
	}
	else
		a = ft_count_isize(entry->infos.st_size);
	return (a > form->mss ? a : form->mss);
}
