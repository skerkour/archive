/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:51:02 by skerkour          #+#    #+#             */
/*   Updated: 2016/06/06 14:52:45 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_get_center(t_fdf_ctx *ctx)
{
	ctx->center.x = (ctx->map_array[ctx->map_len - 1]->x + ctx->map_array[0]->x)
		/ 2;
	ctx->center.y = (ctx->map_array[ctx->map_len - 1]->y
		+ ctx->map_array[0]->y) / 2;
}

int		fdf_is_point_out_of_win(t_fdf_point point)
{
	if (!(point.x > FDF_WIN_W + 100 || point.x <= 0
		|| point.y > FDF_WIN_H + 100 || point.y <= 0))
		return (1);
	return (0);
}
