/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse_file2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:28:45 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/31 15:35:31 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "fdf.h"
#include "libft.h"

void		fdf_parse_line(t_fdf_ctx *ctx, char *line)
{
	int32_t	n;
	size_t	j;

	j = 0;
	ctx->line_j = 0;
	while (fdf_get_next_token(ctx, &line, &n))
	{
		fdf_check_errors(ctx);
		fdf_add_line_elem(ctx, n);
		j += 1;
	}
	fdf_check_errors(ctx);
	if (ctx->map_w == 0 && ctx->line_i == 0)
		ctx->map_w = j;
	else if (ctx->map_w != j
		|| (ctx->map_w == 0 && ctx->line_i != 0))
		fdf_set_line_length_error(ctx);
}

void		fdf_parse_file(t_fdf_ctx *ctx, char *filename)
{
	int		fd;
	char	*line;

	if ((fd = open(filename, O_RDONLY)) <= 0)
		return (fdf_set_open_error(ctx, filename));
	ctx->line_i = 0;
	while (ft_gnl(fd, &line) > 0)
	{
		fdf_parse_line(ctx, line);
		fdf_check_line_error(ctx, line, fd);
		free(line);
		ctx->line_i += 1;
	}
	ctx->map_h = ctx->line_i;
	close(fd);
}
