/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 11:33:28 by skerkour          #+#    #+#             */
/*   Updated: 2016/03/11 16:03:03 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdint.h>
# include <stdlib.h>

# include "libft.h"

# define FTL_N_FRACTALS 5
# define FTL_N_COLORS 4

# define FTL_WIN_H 750
# define FTL_WIN_W 750

# define FTL_MOUSE_BTN_RIGHT 1
# define FTL_MOUSE_BTN_LEFT 2
# define FTL_MOUSE_BTN_MIDDLE 3
# define FTL_MOUSE_SCROLL_UP 4
# define FTL_MOUSE_SCROLL_DOWN 5
# define FTL_MOUSE_SCROLL_LEFT 6
# define FTL_MOUSE_SCROLL_RIGHT 7

# define FTL_MOTION_MASK (1L<<6)
# define FTL_MOTION_NOTIFY 6

# define FTL_KEY_ESC 53
# define FTL_KEY_ENTER 36
# define FTL_KEY_SPACE 49

# define FTL_KEY_Q 12
# define FTL_KEY_W 13
# define FTL_KEY_E 14
# define FTL_KEY_R 15
# define FTL_KEY_T 17
# define FTL_KEY_Y 16
# define FTL_KEY_U 32
# define FTL_KEY_A 0
# define FTL_KEY_S 1
# define FTL_KEY_D 2
# define FTL_KEY_F 3
# define FTL_KEY_G 5
# define FTL_KEY_P 35
# define FTL_KEY_C 8

# define FTL_KEY_PAD_PLUS 69
# define FTL_KEY_PAD_MINUS 78
# define FTL_KEY_PAD_1 83
# define FTL_KEY_PAD_2 84
# define FTL_KEY_PAD_3 85
# define FTL_KEY_PAD_4 86
# define FTL_KEY_PAD_5 87
# define FTL_KEY_PAD_6 88

# define FTL_KEY_UP 126
# define FTL_KEY_DOWN 125
# define FTL_KEY_LEFT 123
# define FTL_KEY_RIGHT 124

# define FTL_SQAURE(x) (x * x)

typedef struct	s_ftl_point
{
	double	x;
	double	y;
}				t_ftl_point;

typedef struct	s_ftl_fractal
{
	t_complex	c;
	t_complex	z;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		zoom_x;
	double		zoom_y;
	double		zoom_ratio;
	double		tmp;
	int32_t		n_iters;
	int32_t		iters_max;
	void		*func;
	char		*name;
}				t_ftl_fractal;

typedef struct	s_ftl_colors
{
	int32_t	color_0;
	int32_t	color_1;
	int32_t	color_2;
	int32_t	color_3;
	int32_t	color_4;
	int32_t	color_5;
	int32_t	color_6;
	int32_t	color_7;
	int32_t	color_8;
}				t_ftl_colors;

typedef struct	s_ftl_ctx
{
	size_t			win_h;
	size_t			win_w;
	void			*mlx;
	void			*win;
	void			*img;
	char			*mlx_img;
	int32_t			bpp;
	int32_t			size_line;
	int32_t			ed;
	t_ftl_fractal	*fractals_arr;
	t_ftl_fractal	*current_fractal;
	t_ftl_colors	*colors_arr;
	size_t			i_colors;
	t_ftl_colors	*current_colors;
	char			is_motion;
}				t_ftl_ctx;

/*
** ftl_hooks.c
*/
int				ftl_hook_mouse(int32_t btn, int32_t x, int32_t y,
					t_ftl_ctx *ctx);
int				ftl_hook_expose(t_ftl_ctx *ctx);
int				ftl_hook_keys(int key, t_ftl_ctx *ctx);
int				ftl_hook_motion(int x, int y, t_ftl_ctx *ctx);

/*
** ftl_hooks_subfunctions.c
*/
void			ftl_hook_keys_change_fractal(int key, t_ftl_ctx *ctx);
void			ftl_hook_keys_controls_fractal(int key, t_ftl_ctx *ctx);

/*
** ftl_graphics.c
*/
void			ftl_redraw(t_ftl_ctx *ctx);
void			ftl_apply_func(t_ftl_ctx *ctx, t_ftl_fractal *fractal,
					int32_t (*f)(t_ftl_ctx*, t_ftl_fractal, t_ftl_point*));
void			ftl_draw_pixel_img(t_ftl_ctx *ctx, t_ftl_point *point,
					int32_t color);

/*
** ftl_fractals.c
*/
int32_t			ftl_fracal_mandelbrot(t_ftl_ctx	*ctx, t_ftl_fractal fractal,
					t_ftl_point *point);
int32_t			ftl_fractal_julia(t_ftl_ctx *ctx, t_ftl_fractal fractal,
					t_ftl_point *point);
int32_t			ftl_fractal_mandelbar(t_ftl_ctx *ctx, t_ftl_fractal fractal,
					t_ftl_point *point);
int32_t			ftl_fractal_carpet(t_ftl_ctx *ctx, t_ftl_fractal fractal,
					t_ftl_point *point);
int32_t			ftl_fractal_burning_ship(t_ftl_ctx *ctx, t_ftl_fractal fractal,
					t_ftl_point *point);

/*
** ftl_utils.c
*/
void			ftl_init_colors(t_ftl_ctx *ctx);
int32_t			ftl_get_color(int32_t z, t_ftl_colors colors);
void			ftl_use_fractal(t_ftl_ctx *ctx, char *fractal_name);
int32_t			ftl_rgb_ton_int32(int32_t r, int32_t g, int32_t b);
void			ftl_fractal_change_colors(t_ftl_ctx *ctx);

/*
** ftl_utils_fractals.c
*/
void			ftl_fractal_translate(t_ftl_ctx *ctx, int32_t d, char axis);
void			ftl_fractal_change_iterations(t_ftl_ctx *ctx, int32_t iters);
void			ftl_fractal_change_scale(t_ftl_ctx *ctx, double zoom_ratio);
void			ftl_init_fractals(t_ftl_ctx *ctx);

#endif
