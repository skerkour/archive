/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 17:39:19 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/31 15:04:31 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "libft.h"
#include "fdf.h"

void	fdf_add_line_elem(t_fdf_ctx *ctx, int32_t n)
{
	t_lst	*new_el;

	if ((new_el = ft_lstnew(&n, sizeof(int32_t))) == NULL)
	{
		ft_putendl_fd("fatal error with malloc()... exiting", FT_STDERR);
		ft_exit(-42);
	}
	ft_lstadd_end(&(ctx->map_lst), new_el);
}

void	fdf_map_lst_to_array(t_fdf_ctx *ctx)
{
	t_lst		*tmp;
	size_t		i;
	t_fdf_point	*point;

	ctx->map_array = (t_fdf_point**)ft_xmalloc(sizeof(t_fdf_point*) *
		(ctx->map_w * ctx->map_h + 1));
	i = 0;
	while (ctx->map_lst)
	{
		tmp = ctx->map_lst;
		point = (t_fdf_point*)ft_xmalloc(sizeof(t_fdf_point));
		point->x = (i % ctx->map_w) * 20;
		point->y = (i / ctx->map_w) * 20;
		point->z = (double)(*((int32_t*)tmp->data));
		point->s = 1;
		point->color = point->z;
		ctx->map_array[i] = point;
		i += 1;
		ctx->map_lst = ctx->map_lst->next;
		free(tmp->data);
		free(tmp);
	}
	ctx->map_array[i] = NULL;
}
