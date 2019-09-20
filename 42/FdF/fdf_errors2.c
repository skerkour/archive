/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_errors2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:07:42 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/31 15:11:29 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void		fdf_set_line_length_error(t_fdf_ctx *ctx)
{
	char *msg;

	msg = ft_strjoinsf("at line : ", ft_stoa(ctx->line_i + 1));
	msg = ft_strjoinf(msg, ", lines should be congruent.");
	fdf_set_error(ctx, msg);
}

void		fdf_set_open_error(t_fdf_ctx *ctx, char *filename)
{
	fdf_set_error(ctx, ft_strjoin("Can't open file : ", filename));
}

void		fdf_set_token_error(t_fdf_ctx *ctx)
{
	char *msg;

	msg = ft_strjoinsf("Unexpected token at column : ",
			ft_stoa(ctx->line_j + 1));
	msg = ft_strjoinf(msg, ", at line : ");
	msg = ft_strjoinf(msg, ft_stoa(ctx->line_i + 1));
	fdf_set_error(ctx, msg);
}
