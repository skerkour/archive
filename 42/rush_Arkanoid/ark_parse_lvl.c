/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark_parse_lvl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 19:43:52 by skerkour          #+#    #+#             */
/*   Updated: 2015/05/03 20:54:54 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "arkanoid.h"
#include "libft_ext.h"

int			ark_check_line(t_ark_ctx *ctx, char *line)
{
	unsigned int	size;

	size = 0;
	while (*line)
	{
		if ((!(*line >= '0' && *line <= '3') && *line != '9' && *line != 'X')
				|| !(*(line + 1) == ' ' || !*(line + 1)))
		{
			ctx->map_size_tmp = 0;
			return (0);
		}
		++size;
		if (*(line + 1))
			line += 2;
		else
			++line;
	}
	ctx->map_size_tmp += size;
	return (1);
}

int			ark_check_map(t_ark_ctx *ctx, int fd)
{
	char	*line;

	while (get_next_line_2(fd, &line) > 0)
	{
		if (!ark_check_line(ctx, line))
		{
			free(line);
			return (0);
		}
		free(line);
	}
	return (1);
}

void		ark_read_lines(int fd, char *map)
{
	char			*line;
	unsigned int	i;
	char			*tmp;

	i = 0;
	while (get_next_line_2(fd, &line) > 0)
	{
		tmp = line;
		while (*line)
		{
			map[i++] = *line;
			if (*(line + 1))
				line += 2;
			else
				line++;
		}
		free(tmp);
	}
	map[i] = 0;
}

int			ark_read_map(t_ark_ctx *ctx, int fd)
{
	char	*map;

	if (!(map = (char*)malloc(ctx->map_size_tmp + 1)))
		return (0);
	ctx->lvl.size = ctx->map_size_tmp;
	ark_read_lines(fd, map);
	map[ctx->lvl.size] = 0;
	ctx->lvl.bricks = map;
	return (1);
}

int			ark_get_next_lvl(t_ark_ctx *ctx)
{
	int		fd;
	t_list	*next;

	if (!(ctx->lvl_names))
		return (0);
	if ((fd = open(ctx->lvl_names->content, O_RDONLY)) <= 0)
		return (-1);
	if (!ark_check_map(ctx, fd) || ctx->map_size_tmp == 0)
	{
		next = ctx->lvl_names->next;
		free(ctx->lvl_names->content), free(ctx->lvl_names), close(fd);
		ctx->lvl_names = next;
		return (-1);
	}
	close(fd);
	if ((fd = open(ctx->lvl_names->content, O_RDONLY)) <= 0)
		return (-1);
	if (!ark_read_map(ctx, fd))
		return (-1);
	close(fd);
	next = ctx->lvl_names->next;
	free(ctx->lvl_names->content);
	free(ctx->lvl_names);
	ctx->lvl_names = next;
	return (1);
}
