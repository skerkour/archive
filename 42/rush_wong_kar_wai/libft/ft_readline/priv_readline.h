/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priv_ft_readline.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/24 08:31:29 by skerkour          #+#    #+#             */
/*   Updated: 2015/02/27 16:03:30 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIV_READLINE_H
# define PRIV_READLINE_H

# include "libft.h"

# define FT_RL_ESC 0x1b
# define FT_RL_DEL 0x7f
# define FT_RL_TAB 0x09

# define FT_RL_CTRL_L 0x0c
# define FT_RL_CTRL_X 0x18
# define FT_RL_CTRL_D 0x4

# define FT_RL_UP 0x41
# define FT_RL_DOWN 0x42
# define FT_RL_RIGHT 0x43
# define FT_RL_LEFT 0x44

typedef struct	s_rl_ctx
{
	t_lst	*line;
	char	*header;
	t_uint	pos;
	t_uint	max;
}				t_rl_ctx;

/*
** ft_readline.c
*/
int				rl_getch(void);
void			rl_escaped(t_lst *line, t_uint *pos, t_uint max);
void			rl_delete(t_lst **line, t_uint *pos, t_uint *max);
char			*ft_readline(char *header);

/*
** rl_putline.c
*/
void			rl_putline(t_lst *letter);
void			rl_putlinei(t_lst *letter, t_uint start);

/*
** rl_movecursor.c
*/
void			rl_movecurs_right(t_uint n);
void			rl_movecurs_left(t_uint n);
void			rl_clear_screen(char *header, t_lst *line);
void			rl_savecurs_pos(void);
void			rl_restorecurs_pos(void);

/*
** rl_lst.c
*/
void			rl_lstdel_el(t_lst *letter);
t_lst			*rl_lstnewel(char c);

/*
** rl_header.c
*/
void			rl_putheader(char *header);

/*
** rl_list_to_tab.c
*/
char			*rl_list_to_tab(t_lst **line);

/*
** rl_ctx.c
*/
t_rl_ctx		*rl_ctx_init(char *header);
#endif
