/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_matrices.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:41:29 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/31 15:56:13 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "fdf.h"
#include "libft.h"

t_fdf_matrix	*fdf_matrix_scale(double s)
{
	t_fdf_matrix	*ret;

	ret = (t_fdf_matrix*)ft_xmalloc(sizeof(t_fdf_matrix));
	ret->a1 = s;
	ret->b2 = s;
	ret->c3 = s;
	ret->d4 = 1;
	return (ret);
}

t_fdf_matrix	*fdf_matrix_translation(double tx, double ty, double tz)
{
	t_fdf_matrix	*ret;

	ret = (t_fdf_matrix*)ft_xmalloc(sizeof(t_fdf_matrix));
	ret->a4 = tx;
	ret->b4 = ty;
	ret->c4 = tz;
	ret->a1 = 1;
	ret->b2 = 1;
	ret->c3 = 1;
	ret->d4 = 1;
	return (ret);
}

t_fdf_matrix	*fdf_matrix_rotation_x(double beta)
{
	t_fdf_matrix	*ret;

	ret = (t_fdf_matrix*)ft_xmalloc(sizeof(t_fdf_matrix));
	ret->a1 = 1;
	ret->b2 = cos(beta);
	ret->b3 = -sin(beta);
	ret->c2 = sin(beta);
	ret->c3 = cos(beta);
	ret->d4 = 1;
	return (ret);
}

t_fdf_matrix	*fdf_matrix_rotation_y(double beta)
{
	t_fdf_matrix	*ret;

	ret = (t_fdf_matrix*)ft_xmalloc(sizeof(t_fdf_matrix));
	ret->a1 = cos(beta);
	ret->a3 = sin(beta);
	ret->c1 = -sin(beta);
	ret->c3 = cos(beta);
	ret->b2 = 1;
	ret->d4 = 1;
	return (ret);
}

t_fdf_matrix	*fdf_matrix_rotation_z(double beta)
{
	t_fdf_matrix	*ret;

	ret = (t_fdf_matrix*)ft_xmalloc(sizeof(t_fdf_matrix));
	ret->a1 = cos(beta);
	ret->a2 = -sin(beta);
	ret->b1 = sin(beta);
	ret->b2 = cos(beta);
	ret->c3 = 1;
	ret->d4 = 1;
	return (ret);
}
