/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 10:47:33 by skerkour          #+#    #+#             */
/*   Updated: 2014/12/03 13:33:51 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lsargs		*ls_targs_new(void)
{
	t_lsargs	*ret;

	ret = (t_lsargs*)ft_xmalloc(sizeof(t_lsargs));
	ret->flags = 0;
	ret->files = NULL;
	ret->unk = NULL;
	ret->dirs = NULL;
	ret->ndirs = 0;
	ret->nfiles = 0;
	ret->nunk = 0;
	return (ret);
}

static void		ls_args_error(char c)
{
	ft_putstr_fd("ft_ls: illegal option -- ", FT_STDERR);
	ft_putchar_fd(c, FT_STDERR);
	ft_putchar_fd('\n', FT_STDERR);
	ft_putstr_fd("usage : ft_ls [-alRrt] [file ...]\n", FT_STDERR);
	exit(1);
}

static t_uint	ls_parse_opt(char *arg)
{
	t_uint	ret;

	ret = 0;
	++arg;
	while (*arg)
	{
		if (*arg == 'l')
			ret |= FLAG_l;
		else if (*arg == 'R')
			ret |= FLAG_R;
		else if (*arg == 'a')
			ret |= FLAG_a;
		else if (*arg == 'r')
			ret |= FLAG_r;
		else if (*arg == 't')
			ret |= FLAG_t;
		else
			ls_args_error(*arg);
		++arg;
	}
	return (ret);
}

static void		ls_parse_args_cut(int *i, int ac, char **av, t_lsargs *args)
{
	struct stat	inf;

	while (*i < ac)
	{
		if (lstat(av[*i], &inf) == -1)
			ft_lstadd_srt(&(args->unk),
				ft_lstnew(ft_strdup(av[*i]), ft_strlen(av[*i]) + 1), ls_cmpu_n),
				args->nunk++;
		else if (inf.st_mode & S_IFDIR)
			ft_lstadd_srt(&(args->dirs), ft_lstnew(ls_new_ent(ft_strdup(
				av[*i]), &inf), sizeof(t_lsentry)),
				args->flags & FLAG_t ? ls_cmpe_t : ls_cmpe_n), args->ndirs++;
		else
			ft_lstadd_srt(&(args->files), ft_lstnew(ls_new_ent(ft_strdup(
				av[*i]), &inf), sizeof(t_lsentry)),
				args->flags & FLAG_t ? ls_cmpe_t : ls_cmpe_p), args->nfiles++;
		(*i)++;
	}
	if (args->flags & FLAG_r)
	{
		ft_lstrev(&(args->dirs));
		ft_lstrev(&(args->unk));
		ft_lstrev(&(args->files));
	}
}

t_lsargs		*ls_args(int ac, char **av)
{
	int			i;
	t_lsargs	*ret;
	t_bool		ttdone;

	ttdone = FALSE;
	i = 1;
	ret = ls_targs_new();
	while (i < ac)
	{
		if (!ft_strcmp(av[i], "--") && !ttdone)
		{
			++i, ttdone = TRUE;
			continue ;
		}
		if (av[i][0] == '-' && av[i][1] && av[i][1] != '-' && !ttdone)
			ret->flags |= ls_parse_opt(av[i]);
		else
			ls_parse_args_cut(&i, ac, av, ret);
		++i;
	}
	return (ret);
}
