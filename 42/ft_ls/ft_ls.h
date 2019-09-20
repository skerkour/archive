/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 10:47:25 by skerkour          #+#    #+#             */
/*   Updated: 2014/12/10 22:03:32 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <sys/stat.h>
# include <time.h>
# include <stdio.h>

# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <ctype.h>

# include <sys/xattr.h>

# include "libft/libft.h"

# define RED "\e[0;31m"
# define CYAN "\e[1;36m"
# define MAGE  "\e[0;35m"
# define CHRCLR "\e[0;34;43m"
# define BLKCLR "\e[0;34;46m"
# define CEND "\e[0m"

# define LS_MAJOR(x)	((int32_t)(((u_int32_t)(x) >> 24) & 0xff))
# define LS_MINOR(x)	((int32_t)((x) & 0xffffff))

enum
{
	FLAG_l = 1 << 0,
	FLAG_R = 1 << 1,
	FLAG_a = 1 << 2,
	FLAG_r = 1 << 3,
	FLAG_t = 1 << 4,
};

enum
{
	ls_tunk = 0,
	ls_tfifo = 1 << 0,
	ls_tchr = 1 << 1,
	ls_tdir = 1 << 2,
	ls_tblk = 1 << 3,
	ls_treg = 1 << 4,
	ls_tlnk = 1 << 5,
	ls_tsock = 1 << 6,
	ls_twht = 1 << 7
};

typedef struct	s_lsentry
{
	struct stat		infos;
	char			*path;
	char			*name;
}				t_lsentry;

typedef struct	s_lsargs
{
	t_uint	flags;
	t_lst	*files;
	t_lst	*unk;
	t_lst	*dirs;
	t_uint	ndirs;
	t_uint	nfiles;
	t_uint	nunk;
}				t_lsargs;

typedef struct	s_l_form
{
	t_ushort	msl;
	t_ushort	msu;
	t_ushort	msg;
	t_ushort	mss;
	t_ushort	mmaj;
	t_ushort	mmin;
	t_uint		tblock;
}				t_l_form;

/*
** little hack to fuck the 'norme'
*/
typedef struct	s_hack
{
	struct dirent	*dent;
	t_lsargs		*args;
	t_lst			*dcontent;
	t_lst			*subdirs;
	struct stat		inf;
	char			*path;
}				t_hack;

/*
**	ls_args.c
*/
t_lsargs		*ls_targs_new(void);
t_lsargs		*ls_args(int ac, char **av);
/*
**	ls_lsit_dirs.c
*/
t_uint			ls_list_dir(t_lsentry *lsentry, t_lsargs *args);
void			ls_add_dcontent(t_lsargs *args, t_hack *hck);
void			ls_add_subdirs(t_lsargs *args, t_hack *hck, t_uint *ret);
/*
**	ls_dirs.c
*/
char			*ls_mkpath(char *left, char *right);
void			ls_display_cont(t_lst *list, t_lsargs *args);
void			ls_process_dirs(t_lsargs *args);
void			ls_list_dir_cont(char *name, t_lst *dcontent, t_lst *subdirs,
								t_lsargs *args);
/*
**	ls_long.c
*/
void			ls_pname(t_lsentry *entry);
void			ls_ppath(t_lsentry *entry);
void			ls_pinfos(t_lsentry *entry, t_l_form *format);
void			ls_l_form_init(t_l_form *format);
void			ls_l_count(t_lst *el, t_l_form *form, char *tmp);
/*
**	ls_long2.c
*/
void			ls_l_pnlinks(t_uint nlinks, t_ushort nl);
void			ls_l_puname(t_uint uid, t_ushort nu);
void			ls_l_pgname(t_uint gid, t_ushort ng);
void			ls_l_psize(t_uint size, t_ushort ns);
void			ls_l_pmtime(time_t *t);
/*
**	ls_long3.c
*/
char			*ls_xtrct_name(char *path);
void			ls_l_tblock(t_lst *dir_cont);
void			ls_l_ptype(t_lsentry *entry);
void			ls_l_plink(char *path);
void			ls_l_pperms(mode_t mode);
/*
**	ls_long4.c
*/
void			ls_l_pext_inf(char *path);
t_uint			ls_l_countweigth(t_l_form *form, t_lsentry *entry);
void			ls_l_pmajmin(t_lsentry *entry, t_ushort nmin, t_ushort nmax);
/*
**	ls_lst.c
*/
int				ls_cmpe_t(t_lst *a, t_lst *b);
int				ls_cmpe_n(t_lst *a, t_lst *b);
int				ls_cmpe_p(t_lst *a, t_lst *b);
int				ls_cmpu_n(t_lst *a, t_lst *b);
t_lsentry		*ls_new_ent(char *path, struct stat *infos);
/*
**	ls_lst2.c
*/
void			ls_del_ent(void *entry, size_t size);
void			ls_del_unk(void *name, size_t size);
/*
**	main.c
*/
void			ls_error(char *error, t_bool bexit);
void			ls_process_files(t_lsargs *args);
void			ls_process_args(t_lsargs *args);
void			ls_list_current(t_lsargs *args);
#endif
