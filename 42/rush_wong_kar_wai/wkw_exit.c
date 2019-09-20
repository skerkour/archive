/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 23:26:13 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/01 19:12:16 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <ncurses.h>
#include <unistd.h>

#include "libft.h"
#include "wong_kar_wai.h"

static void	wkw_display_latest_scores(char *file)
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

void		wkw_exit(t_wkw_ctx *ctx, int code)
{
	char	*rep;
	char	*score;

	endwin();
	ft_putstr("You "), ft_putendl(ctx->won ? "Win =)" : "Lose =(");
	ft_putstr("Score : "), score = ft_itoa(ctx->score);
	ft_putendl(score), ft_memdel((void**)&score);
	ft_putendl("+---------------+\n| Latest scores |\n+---------------+");
	wkw_display_latest_scores(SCORES_FILE);
	wkw_save_score(ctx);
	ft_putendl("Do you want to replay ? (y/*)"), ft_gnl(0, &rep);
	if (!ft_strcmp(rep, "y"))
	{
		ft_memdel((void**)&rep);
		ctx->won = 0;
		ctx->score = 0;
		ft_bzero((void*)ctx->grid, sizeof(t_wkw_cell) * (ctx->n * ctx->n));
		wkw_init(ctx);
		wkw_start_game(ctx);
	}
	else
		endwin(), ft_exit(code);
}
