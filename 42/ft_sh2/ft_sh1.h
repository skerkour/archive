/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 15:48:37 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/11 20:54:45 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H
# define FT_SH1_H

# include "libft.h"

typedef struct	s_env_el
{
	char	*name;
	char	*value;
}				t_env_el;

extern char		***g_env;

/*
** main.c
*/
void			sh1_main_loop(char ***env);

/*
** sh1_env.c
*/
char			*sh1_getenv(char **env, char *var);
char			*sh1_getenv_name(char *full_var);
void			sh1_env_replace(char **env, char **args);

/*
** sh1_extern_exist.c
*/
int				sh1_extern_exist(char *cmd, char **env);

/*
** sh1_signals.c
*/
void			sh1_set_signals_hook(void);

/*
** sh1_hooked_signals.c
*/
void			sh1_hkd_sigint(int sign);
void			sh1_hkd_sigtstp(int sign);

/*
** sh1_header.c
*/
char			*sh1_get_header(char **env);

/*
** sh1_parse_line.c
*/
void			sh1_parse_cmdl_comma(char *line, char ***env);
void			sh1_parse_cmdl(char *line, char ***env);

/*
** sh1_xcute.c
** sh1_isxcut_relative:
**	return -1, if no such file or directory or unusable filetype,
**	0 if its a directory so you can go into,
**	1 if its a file or a link t a file and is xcutable by user
*/
int				sh1_isxcut_relative(char *path);
void			sh1_xcute_relative(char *cmd_path, char **args, char **env);
int				sh1_search_cmd_indir(char *dir_path, char *cmd);
char			*sh1_search_cmd_path(char *cmd, char **env);
void			sh1_xcute_extern(char *cmd, char **args, char **env);
/*
** builtin/sh1_bltin_cd.c
*/
void			sh1_bltin_cd(char ***env, char **args);

/*
** builtin/sh1_bltin_exit.c
*/
void			sh1_bltin_exit(char *code);

/*
** sh1_bltin_setenv.c
** sh1_bltin_setenv_one:
**	pos and name must be NULL -> fuck the norme
*/
void			sh1_bltin_setenv(char ***env, char **line);
void			sh1_bltin_setenv_one(char ***env, char *arg,
					char *pos, char *name);

/*
** sh1_bltin_unsetenv.c
*/
void			sh1_bltin_unsetenv(char ***env, char **arg);

/*
** sh1_bltin_env.c
*/
void			sh1_bltin_env(char ***env, char **arg);

#endif
