/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark_scores.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 21:49:03 by skerkour          #+#    #+#             */
/*   Updated: 2015/05/03 22:03:08 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#include "arkanoid.h"

void	ark_display_latest_scores(char *file)
{
	int		fd;
	char	buff[1024];
	int		ret;

	if ((fd = open(file, O_RDONLY)) < 0)
		return ;
	ret = 1024;
	while (ret == 1024)
	{
		ret = read(fd, buff, 1024);
		write(1, buff, ret);
	}
	close(fd);
}

void	ark_save_score(t_ark_ctx *ctx)
{
	int		fd;
	char	*scores_line;
	char	*score;

	fd = open(SCORES_FILE, O_RDWR | O_APPEND | O_CREAT, 0644);
	if (fd < 0)
		return ;
	score = ft_itoa(ctx->score);
	scores_line = ft_memalloc(ft_strlen(score) + 1 + 1 + 8);
	*scores_line = 0;
	ft_strcat(scores_line, score);
	ft_strcat(scores_line, ctx->player_hp ? " (WON)" : " (LOSED)");
	ft_strcat(scores_line, "\n");
	write(fd, scores_line, ft_strlen(scores_line));
	ft_memdel((void**)&scores_line), ft_memdel((void**)&score);
	close(fd);
}
