/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 12:31:18 by skerkour          #+#    #+#             */
/*   Updated: 2016/03/11 17:55:09 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdint.h>

#include "fdf.h"
#include "libft.h"

void	fdf_check_line_error(t_fdf_ctx *ctx, char *line, int fd)
{
	if (ctx->is_err == 1)
	{
		close(fd);
		free(line);
		fdf_check_errors(ctx);
	}
}

void	fdf_check_token_validity(t_fdf_ctx *ctx, char *token_start,
			char *token_end)
{
	if (token_end - token_start < 0 || token_end - token_start > 9)
		fdf_set_token_error(ctx);
	if (token_end - token_start == 9)
	{
		if (token_start[0] > '2')
			fdf_set_token_error(ctx);
		if (token_start[0] == '2' && token_start[1] > '1')
			fdf_set_token_error(ctx);
		if (token_start[0] == '2' && token_start[1] == '1'
			&& token_start[2] > '4')
			fdf_set_token_error(ctx);
		if (token_start[0] == '2' && token_start[1] == '1'
			&& token_start[2] == '4' && token_start[3] > '7')
			fdf_set_token_error(ctx);
	}
}

void	fdf_find_token_end(t_fdf_ctx *ctx, char *token_start,
			char **token_end)
{
	if (*token_start == '-' || *token_start == '+')
	{
		token_start += 1;
		ctx->line_j += 1;
	}
	if (!(*token_start))
		fdf_set_token_error(ctx);
	while (*token_start && ft_isdigit(*token_start))
	{
		token_start += 1;
		ctx->line_j += 1;
	}
	if (0)
		UNUSED(ctx);
	*token_end = token_start;
}

void	fdf_parse_token(char *token_start, char *token_end, int32_t *n)
{
	char	*token;

	token = ft_strsub(token_start, 0, (token_end - token_start));
	*n = ft_atoi32(token);
	free(token);
}

int		fdf_get_next_token(t_fdf_ctx *ctx, char **line, int32_t *n)
{
	char	*token_start;
	char	*token_end;

	while (**line && !ft_isdigit(**line) && (**line) != '-' && (**line) != '+')
	{
		if (!ft_isspace(**line))
			fdf_set_token_error(ctx);
		(*line) += 1;
		ctx->line_j += 1;
	}
	if (!(**line))
		return (0);
	token_start = *line;
	fdf_find_token_end(ctx, token_start, &token_end);
	fdf_check_errors(ctx);
	fdf_check_token_validity(ctx, token_start, token_end);
	if (*line)
		*line = token_end;
	ctx->line_j += (token_end - token_start);
	fdf_parse_token(token_start, token_end, n);
	return (1);
}
