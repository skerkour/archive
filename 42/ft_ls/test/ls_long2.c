/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_long2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 13:00:59 by skerkour          #+#    #+#             */
/*   Updated: 2014/12/03 19:44:09 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_l_pnlinks(t_uint nlinks, t_ushort nl)
{
	t_ushort tnl;

	tnl = ft_count_isize(nlinks);
	if (tnl < nl)
		while (nl-- > tnl)
			ft_putchar(' ');
	ft_putnbr(nlinks);
}

void	ls_l_puname(t_uint uid, t_ushort nu)
{
	t_uint			tnu;
	struct passwd	*pawd;
	char			*uname;

	if ((pawd = getpwuid(uid)) == NULL)
		uname = ft_itoa(uid);
	else
		uname = ft_strdup(pawd->pw_name);
	tnu = ft_strlen(uname);
	ft_putstr(uname);
	if (tnu < nu)
		while (nu-- > tnu)
			ft_putchar(' ');
	free(uname);
}

void	ls_l_pgname(t_uint gid, t_ushort ng)
{
	t_uint			tng;
	struct group	*ggd;
	char			*gname;

	if ((ggd = getgrgid(gid)) == NULL)
		gname = ft_itoa(gid);
	else
		gname = ft_strdup(ggd->gr_name);
	tng = ft_strlen(gname);
	ft_putstr(gname);
	if (tng < ng)
		while (ng-- > tng)
			ft_putchar(' ');
	free(gname);
}

void	ls_l_psize(t_uint size, t_ushort ns)
{
	t_ushort tns;

	tns = ft_count_isize(size);
	if (tns < ns)
		while (ns-- > tns)
			ft_putchar(' ');
	ft_putnbr(size);
}

void	ls_l_pmtime(time_t *t)
{
	char	*str;
	char	*end;
	char	*start;
	time_t	ct;

	ct = time(NULL);
	if ((str = ctime(t)) == NULL)
		return ;
	start = str + 4;
	end = str + 10;
	*end = 0;
	ft_putstr(start);
	ft_putchar(' ');
	if (*t > ct || *t + 15768000 < ct)
	{
		start = str + 20;
		end = str + 24, ft_putchar(' ');
	}
	else
	{
		start = str + 11;
		end = str + 16;
	}
	*end = 0;
	ft_putstr(start);
}
