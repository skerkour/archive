/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priv_readline.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 16:36:28 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/08 16:43:38 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIV_READLINE_H
# define PRIV_READLINE_H

# include "libft.h"

typedef struct	s_rl_ctx
{
	t_dlst	*line;
	char	*header;
	t_uint	pos;
	t_uint	term_width;
}				t_rl_ctx;

extern t_rl_ctx	*g_rl_ctx;

/*
** ft_readline.c
*/
int				rl_getch(void);
char			*ft_readline(char *header);

/*
** rl_arrows.c
*/
void			rl_right_arrow(t_rl_ctx *ctx);
void			rl_left_arrow(t_rl_ctx *ctx);

/*
** rl_ctx.c
*/
void			rl_ctx_del(t_rl_ctx **ctx);
int				rl_ctx_init(t_rl_ctx **ctx, char *header);

/*
** rl_delete.c
*/
void			rl_delete(t_rl_ctx *ctx);

/*
** rl_dlist_to_arr.c
*/
char			*rl_dlist_to_arr(t_dlst *line);

/*
** rl_dlst.c
*/
void			rl_add_char(t_rl_ctx *ctx, char c);
void			rl_del_char(t_rl_ctx *ctx);

/*
** rl_output.c
*/
void			rl_putline(t_rl_ctx *ctx);
int				rl_putchar(int c);
void			rl_clear_screen(t_rl_ctx *ctx);
void			rl_putheader(t_rl_ctx *ctx);

/*
** rl_resize_handler.c
*/
void			rl_resize_handler(int sign);

#endif
