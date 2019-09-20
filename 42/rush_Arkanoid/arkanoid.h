/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arkanoid.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 10:55:49 by skerkour          #+#    #+#             */
/*   Updated: 2015/05/03 22:01:49 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARKANOID_H
# define ARKANOID_H

# include <glfw3.h>

# include "libft_ext.h"

# define ARK_NBIRCKSF 15.0f
# define ARK_NBIRCKS 15
# define ARK_BRICK_W ((float)(2.0f / ARK_NBIRCKSF))
# define ARK_BRICK_H 0.04f

# define ARK_MIN_WIN_X 750
# define ARK_MIN_WIN_Y 750

# define SCORES_FILE ".score"

# ifndef PI
#  define PI (3.141592653589793)
# endif

enum	e_brick_type
{
	NORMAL = 0,
	ROCK = 1,
	BONUS = 2
};

typedef struct	s_ark_speed
{
	float	x;
	float	y;
}				t_ark_speed;

typedef struct	s_ark_bar
{
	float			x;
	float			size;
}				t_ark_bar;

typedef struct	s_ark_ball
{
	float		x;
	float		y;
	float		r;
	t_ark_speed	s;
}				t_ark_ball;

typedef struct	s_ark_map
{
	char			*bricks;
	unsigned int	size;
}				t_ark_map;

typedef struct	s_ark_ctx
{
	unsigned int	player_hp;
	t_ark_map		lvl;
	GLFWwindow		*window;
	t_list			*lvl_names;
	unsigned long	score;
	unsigned int	map_size_tmp;
	t_ark_bar		bar;
	t_ark_ball		ball;
	int				is_pause;
}				t_ark_ctx;

/*
** ark_callbacks.c
*/
void			ark_error_callback(int error, const char *description);
void			ark_key_callback(GLFWwindow *win, int key, int code, int actio,
					int mod);
void			ark_resize_callback(GLFWwindow *window, int w, int h);

/*
** ark_collide.c
*/
void			ark_compute_ball(t_ark_ctx *ctx);

/*
** ark_init.c
*/
int				ark_get_all_levels(t_ark_ctx *ctx, char *dir);
int				ark_init_glfw(t_ark_ctx *ctx);

/*
** ark_lst.c
*/
void			ark_enqueue_lvl(t_list **lst, char *filename);

/*
** ark_parse_lvl.c
*/
int				ark_get_next_lvl(t_ark_ctx *ctx);

/*
** ark_render.c
*/
void			ark_draw_map(t_ark_ctx *ctx);

/*
** ark_score.c
*/
void			ark_display_score(t_ark_ctx *ctx);
void			ark_display_digit_bar(float x1, float y1, float x2, float y2);

/*
** ark_score2.c
*/
void			ark_display_digit_0(float col);
void			ark_display_digit_1(float col);
void			ark_display_digit_2(float col);
void			ark_display_digit_3(float col);
void			ark_display_digit_4(float col);

/*
** ark_score3.c
*/
void			ark_display_digit_5(float col);
void			ark_display_digit_6(float col);
void			ark_display_digit_7(float col);
void			ark_display_digit_8(float col);
void			ark_display_digit_9(float col);

/*
** ark_scores.c
*/
void			ark_display_latest_scores(char *file);
void			ark_save_score(t_ark_ctx *ctx);

/*
** arkanoid.c
*/
void			ark_launch_game(t_ark_ctx *ctx);
void			ark_finish_game(t_ark_ctx *ctx);

/*
** main.c
*/
char			*ark_buid_path(char *dir, char *file);
void			ark_reset_ball_pos_and_speed(t_ark_ctx *ctx);

extern	t_ark_ctx	*g_ctx;

#endif
