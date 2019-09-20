/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_save_score.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 14:43:20 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/01 15:57:52 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#include "libft.h"
#include "wong_kar_wai.h"

void	wkw_save_score(t_wkw_ctx *ctx)
{
	int		fd;
	char	*scores_line;
	int		len;
	char	*score;

	fd = open(SCORES_FILE, O_RDWR | O_APPEND | O_CREAT, 0644);
	if (fd < 0)
		return ;
	len = ft_strlen(ctx->player_name);
	score = ft_itoa(ctx->score);
	len += 4 + ft_strlen(score) + 8;
	scores_line = ft_memalloc(len + 1);
	ft_strcat(scores_line, ctx->player_name);
	ft_strcat(scores_line, " : ");
	ft_strcat(scores_line, score);
	ft_strcat(scores_line, ctx->won ? " (WON)" : " (LOSED)");
	ft_strcat(scores_line, "\n");
	write(fd, scores_line, len);
	ft_memdel((void**)&scores_line), ft_memdel((void**)&score);
	close(fd);
}
