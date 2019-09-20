/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 11:21:23 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/31 15:11:27 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "fdf.h"
#include "libft.h"

static void	fdf_display_error(t_fdf_ctx *ctx)
{
	ft_putstr_fd("ERROR: ", FT_STDERR);
	ft_putendl_fd(ctx->err_msg, FT_STDERR);
}

inline void	fdf_check_errors(t_fdf_ctx *ctx)
{
	if (ctx->is_err == 1)
	{
		fdf_display_error(ctx);
		exit(-42);
	}
}

void		fdf_set_error_flag(t_fdf_ctx *ctx)
{
	ctx->is_err = 1;
}

void		fdf_set_error_msg(t_fdf_ctx *ctx, char *msg)
{
	ctx->err_msg = msg;
}

void		fdf_set_error(t_fdf_ctx *ctx, char *msg)
{
	fdf_set_error_flag(ctx);
	fdf_set_error_msg(ctx, msg);
}
