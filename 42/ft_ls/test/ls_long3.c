/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_long3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 13:01:06 by skerkour          #+#    #+#             */
/*   Updated: 2014/12/05 19:09:53 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ls_xtrct_name(char *path)
{
	char	*pos;

	if ((pos = ft_strrchr(path, '/')) == NULL)
		return (path);
	return (pos + 1);
}

void	ls_l_tblock(t_lst *dir_cont)
{
	t_uint	tot;

	tot = 0;
	while (dir_cont)
	{
		tot += ((t_lsentry*)dir_cont->data)->infos.st_blocks;
		dir_cont = dir_cont->next;
	}
	ft_putstr("total ");
	ft_putnbr(tot);
	ft_putchar('\n');
}

void	ls_l_ptype(t_lsentry *entry)
{
	if (S_ISBLK(entry->infos.st_mode))
		ft_putchar('b');
	else if (S_ISCHR(entry->infos.st_mode))
		ft_putchar('c');
	else if (S_ISDIR(entry->infos.st_mode))
		ft_putchar('d');
	else if (S_ISLNK(entry->infos.st_mode))
		ft_putchar('l');
	else if (S_ISSOCK(entry->infos.st_mode))
		ft_putchar('s');
	else if (S_ISFIFO(entry->infos.st_mode))
		ft_putchar('p');
	else
		ft_putchar('-');
}

void	ls_l_plink(char *path)
{
	char	buf[1024];

	ft_bzero(buf, sizeof(buf));
	readlink(path, buf, sizeof(buf));
	ft_putstr(" -> ");
	ft_putstr(buf);
}

void	ls_l_pperms(mode_t mode)
{
	ft_putchar(mode & S_IRUSR ? 'r' : '-');
	ft_putchar(mode & S_IWUSR ? 'w' : '-');
	if (mode & S_ISUID)
		ft_putchar(mode & S_IXUSR ? 's' : 'S');
	else
		ft_putchar(mode & S_IXUSR ? 'x' : '-');
	ft_putchar(mode & S_IRGRP ? 'r' : '-');
	ft_putchar(mode & S_IWGRP ? 'w' : '-');
	if (mode & S_ISGID)
		ft_putchar(mode & S_IXGRP ? 's' : 'S');
	else
		ft_putchar(mode & S_IXGRP ? 'x' : '-');
	ft_putchar(mode & S_IROTH ? 'r' : '-');
	ft_putchar(mode & S_IWOTH ? 'w' : '-');
	if (mode & S_ISVTX)
		ft_putchar(mode & S_IXOTH ? 't' : 'T');
	else
		ft_putchar(mode & S_IXOTH ? 'x' : '-');
}
