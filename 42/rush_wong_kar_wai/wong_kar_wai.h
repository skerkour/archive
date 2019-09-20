/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wong_kar_wai.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 11:35:38 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/01 19:37:50 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WONG_KAR_WAI_H
# define WONG_KAR_WAI_H

# define SCORES_FILE "scores.txt"

enum	e_const
{
	WIN_VALUE = 2048,
	N_VALUE = 4
};

/*
** v = (unsigned int) value of the cell
** f = (bool) already fusionned ? 0 | 1
*/
typedef struct	s_wkw_cell
{
	unsigned int	v;
	int				f;
}				t_wkw_cell;

typedef struct	s_wkw_ctx
{
	int				n;
	t_wkw_cell		*grid;
	unsigned int	score;
	char			*player_name;
	unsigned int	won;
}				t_wkw_ctx;

extern t_wkw_ctx	*g_ctx;

/*
** wkw_check_win_loose.c
*/
void			wkw_chck_w_l(t_wkw_ctx *ctx);
/*
** wkw_check_windows_size.c
*/
void			wkw_check_windows_size(int n);

/*
** wkw_color_off.c
*/
void			wkw_color_off(unsigned int nb);

/*
** wkw_color_on.c
*/
void			wkw_color_on(unsigned int nb);

/*
** wkw_display_nbrs.c
*/
void			wkw_display_nbrs(t_wkw_ctx *ctx);

/*
** wkw_draw_grid.c
*/
void			wkw_draw_grid(t_wkw_ctx *ctx);

/*
** wkw_error.c
*/
void			wkw_error(char *str);

/*
** wkw_exit.c
*/
void			wkw_exit(t_wkw_ctx *ctx, int code);

/*
** wkw_exit_signal.c
*/
void			wkw_exit_signal(int sign);

/*
** wkw_init.c
*/
void			wkw_init(t_wkw_ctx *ctx);

/*
** wkw_parse_args.c
*/
void			wkw_parse_args(int ac, char **av, t_wkw_ctx *ctx);

/*
** wkw_play_down.c
*/
int				wkw_play_down(t_wkw_ctx *ctx);

/*
** wkw_play_left.c
*/
int				wkw_play_left(t_wkw_ctx *ctx);

/*
** wkw_play_right.c
*/
int				wkw_play_right(t_wkw_ctx *ctx);

/*
** wkw_play_up.c
*/
int				wkw_play_up(t_wkw_ctx *ctx);

/*
** wkw_resize_handler.c
*/
void			wkw_resize_handler(int sign);

/*
** wkw_save_score.c
*/
void			wkw_save_score(t_wkw_ctx *ctx);

/*
** wkw_spawn_nbr.c
*/
void			wkw_spawn_nbr(t_wkw_ctx *ctx);

/*
** wkw_start_game.c
*/
void			wkw_start_game(t_wkw_ctx *ctx);

#endif
