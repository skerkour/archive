/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_compute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 17:53:03 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/31 16:14:35 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdint.h>
#include <stdlib.h>

#include "fdf.h"

void	fdf_apply_matrix(t_fdf_ctx *ctx, t_fdf_point *p, t_fdf_matrix *m)
{
	double	x;
	double	y;
	double	z;

	p->x -= ctx->center.x;
	p->y -= ctx->center.y;
	x = p->x * m->a1 + p->y * m->a2 + p->z * m->a3 + p->s * m->a4;
	y = p->x * m->b1 + p->y * m->b2 + p->z * m->b3 + p->s * m->b4;
	z = p->x * m->c1 + p->y * m->c2 + p->z * m->c3 + p->s * m->c4;
	p->x = x;
	p->y = y;
	p->z = z;
	p->x += ctx->center.x;
	p->y += ctx->center.y;
}

void	fdf_apply_matrix_all_points(t_fdf_ctx *ctx, t_fdf_matrix *m)
{
	size_t		i;
	t_fdf_point	**map_array;

	map_array = ctx->map_array;
	i = 0;
	while (map_array[i])
	{
		fdf_apply_matrix(ctx, map_array[i], m);
		i += 1;
	}
}

void	fdf_compute_rotation(t_fdf_ctx *ctx, double rot, int32_t axis)
{
	t_fdf_matrix	*m;

	if (axis == FDF_AXIS_X)
		m = fdf_matrix_rotation_x(rot);
	else if (axis == FDF_AXIS_Y)
		m = fdf_matrix_rotation_y(rot);
	else
		m = fdf_matrix_rotation_z(rot);
	fdf_apply_matrix_all_points(ctx, m);
	free(m);
}

void	fdf_compute_translation(t_fdf_ctx *ctx, double x, double y)
{
	t_fdf_matrix	*m;

	m = fdf_matrix_translation(x, y, 0);
	fdf_apply_matrix_all_points(ctx, m);
	fdf_get_center(ctx);
	free(m);
}

void	fdf_compute_scale(t_fdf_ctx *ctx, double s)
{
	t_fdf_matrix	*m;

	m = fdf_matrix_scale(s);
	fdf_apply_matrix_all_points(ctx, m);
	free(m);
}
