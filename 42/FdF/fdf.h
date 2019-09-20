/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 14:08:00 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/31 16:15:30 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdint.h>
# include <stdlib.h>
# include <math.h>

# include "libft.h"

# define FDF_WIN_H 1000
# define FDF_WIN_W 2000

# define FDF_KEY_ESC 53
# define FDF_KEY_Q 12
# define FDF_KEY_W 13
# define FDF_KEY_E 14
# define FDF_KEY_R 15
# define FDF_KEY_T 17
# define FDF_KEY_Y 16
# define FDF_KEY_U 32
# define FDF_KEY_A 0
# define FDF_KEY_S 1
# define FDF_KEY_D 2
# define FDF_KEY_F 3
# define FDF_KEY_G 5
# define FDF_KEY_PAD_PLUS 69
# define FDF_KEY_PAD_LESS 78
# define FDF_KEY_PAD_1 83
# define FDF_KEY_PAD_2 84
# define FDF_KEY_PAD_3 85
# define FDF_KEY_PAD_4 86
# define FDF_KEY_PAD_5 87
# define FDF_KEY_PAD_6 88
# define FDF_KEY_UP 126
# define FDF_KEY_DOWN 125
# define FDF_KEY_LEFT 123
# define FDF_KEY_RIGHT 124

# define FDF_KEY_TRANS_UP FDF_KEY_UP
# define FDF_KEY_TRANS_DOWN FDF_KEY_DOWN
# define FDF_KEY_TRANS_LEFT FDF_KEY_LEFT
# define FDF_KEY_TRANS_RIGHT FDF_KEY_RIGHT
# define FDF_TRANS_UP -100
# define FDF_TRANS_DOWN 100
# define FDF_TRANS_LEFT -100
# define FDF_TRANS_RIGHT 100

# define FDF_KEY_SCALE_PLUS FDF_KEY_PAD_PLUS
# define FDF_KEY_SCALE_LESS FDF_KEY_PAD_LESS
# define FDF_ZOOM_IN 1.1
# define FDF_ZOOM_OUT 0.9

# define FDF_KEY_ROT_X_UP FDF_KEY_PAD_4
# define FDF_KEY_ROT_X_DOWN FDF_KEY_PAD_1
# define FDF_KEY_ROT_Y_UP FDF_KEY_PAD_5
# define FDF_KEY_ROT_Y_DOWN FDF_KEY_PAD_2
# define FDF_KEY_ROT_Z_UP FDF_KEY_PAD_6
# define FDF_KEY_ROT_Z_DOWN FDF_KEY_PAD_3
# define FDF_ROT_X_UP -M_PI / 64
# define FDF_ROT_X_DOWN M_PI / 64
# define FDF_ROT_Y_UP -M_PI / 64
# define FDF_ROT_Y_DOWN M_PI / 64
# define FDF_ROT_Z_UP -M_PI / 64
# define FDF_ROT_Z_DOWN M_PI / 64
# define FDF_AXIS_X 0
# define FDF_AXIS_Y 1
# define FDF_AXIS_Z 2

typedef struct	s_fdf_point
{
	double	x;
	double	y;
	double	z;
	double	s;
	int32_t	color;
}				t_fdf_point;

typedef struct	s_fdf_ctx
{
	int8_t		is_err;
	char		*err_msg;
	size_t		map_w;
	size_t		map_h;
	size_t		map_len;
	size_t		line_i;
	size_t		line_j;
	t_lst		*map_lst;
	t_fdf_point	**map_array;
	void		*mlx;
	void		*win;
	void		*img;
	char		*mlx_img;
	size_t		win_h;
	size_t		win_w;
	t_fdf_point	center;
	int32_t		bpp;
	int32_t		size_line;
	int32_t		ed;
}				t_fdf_ctx;

typedef struct	s_fdf_matrix {
	double	a1;
	double	a2;
	double	a3;
	double	a4;
	double	b1;
	double	b2;
	double	b3;
	double	b4;
	double	c1;
	double	c2;
	double	c3;
	double	c4;
	double	d1;
	double	d2;
	double	d3;
	double	d4;
}				t_fdf_matrix;

/*
** fdf_errors.c
*/
void			fdf_check_errors(t_fdf_ctx *ctx);
void			fdf_set_error(t_fdf_ctx *ctx, char *msg);

/*
** fdf_errors2.c
*/
void			fdf_set_open_error(t_fdf_ctx *ctx, char *filename);
void			fdf_set_line_length_error(t_fdf_ctx *ctx);
void			fdf_set_token_error(t_fdf_ctx *ctx);

/*
** fdf_parse_file.c
*/
void			fdf_check_line_error(t_fdf_ctx *ctx, char *line, int fd);
void			fdf_check_token_validity(t_fdf_ctx *ctx, char *token_start,
					char *token_end);
void			fdf_find_token_end(t_fdf_ctx *ctx, char *token_start,
					char **token_end);
void			fdf_parse_token(char *token_start, char *token_end, int32_t *n);
int				fdf_get_next_token(t_fdf_ctx *ctx, char **line, int32_t *n);

/*
** fdf_parse_file2.c
*/
void			fdf_parse_file(t_fdf_ctx *ctx, char *filename);
void			fdf_parse_line(t_fdf_ctx *ctx, char *line);

/*
** fdf_lst.c
*/
void			fdf_add_line_elem(t_fdf_ctx *ctx, int32_t n);
void			fdf_map_lst_to_array(t_fdf_ctx *ctx);

/*
** fdf_hooks.c
*/
int				fdf_hook_expose(t_fdf_ctx *ctx);
int				fdf_hook_keys(int key, t_fdf_ctx *ctx);

/*
** fdf_compute.c
*/
void			fdf_apply_matrix(t_fdf_ctx *ctx, t_fdf_point *p,
					t_fdf_matrix *m);
void			fdf_apply_matrix_all_points(t_fdf_ctx *ctx, t_fdf_matrix *m);
void			fdf_compute_rotation(t_fdf_ctx *ctx, double rot, int32_t axis);
void			fdf_compute_translation(t_fdf_ctx *ctx, double x, double y);
void			fdf_compute_scale(t_fdf_ctx *ctx, double s);

/*
** fdf_matrices.c
*/
t_fdf_matrix	*fdf_matrix_scale(double s);
t_fdf_matrix	*fdf_matrix_translation(double tx, double ty, double tz);
t_fdf_matrix	*fdf_matrix_rotation_x(double beta);
t_fdf_matrix	*fdf_matrix_rotation_y(double beta);
t_fdf_matrix	*fdf_matrix_rotation_z(double beta);

/*
** fdf_graphics.c
*/
void			fdf_draw_line_params(double *arr, t_fdf_point p1,
					t_fdf_point p2);
void			fdf_draw_point(t_fdf_ctx *ctx, t_fdf_point point,
					int32_t color);
void			fdf_draw_line(t_fdf_ctx *ctx, t_fdf_point p1, t_fdf_point p2,
					int state);
void			fdf_draw(t_fdf_ctx *ctx);
void			fdf_redraw(t_fdf_ctx *ctx);

/*
** fdf_graphics2.c
*/
int32_t			fdf_get_color(t_fdf_point p1, t_fdf_point p2);

/*
** fdf_utils.c
*/
void			fdf_get_center(t_fdf_ctx *ctx);
int				fdf_is_point_out_of_win(t_fdf_point point);

#endif
