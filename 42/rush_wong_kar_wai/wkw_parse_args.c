/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_parse_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 16:14:34 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/01 20:54:32 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "wong_kar_wai.h"

static void	wkw_usage(char *name)
{
	int		i;

	ft_putstr(name);
	ft_putendl(" usage :");
	i = ft_strlen(name) + 8;
	while (i--)
		ft_putchar('~');
	ft_putchar('\n');
	ft_putstr(name);
	ft_putendl(" [<width> <player_name>]");
	ft_putendl("with <width> <= 42 and len(<player_name>) <= (9 * width - 10)");
	ft_exit(1);
}

void		wkw_parse_args(int ac, char **av, t_wkw_ctx *ctx)
{
	if (ac == 1)
		ctx->n = N_VALUE;
	else if (ac == 2 || ac > 3 || !ft_strcmp(av[1], "-h")
		|| !ft_strcmp(av[1], "--help"))
		wkw_usage(av[0]);
	else
		ctx->n = ft_atoi(av[1]) >= 3 ? ft_atoi(av[1]) : N_VALUE;
	if ((ctx->grid = (t_wkw_cell*)ft_memalloc(sizeof(t_wkw_cell)
			* (ctx->n * ctx->n))) == NULL)
		wkw_error("Cannot alloc enought memory... Exiting."), ft_exit(-43);
	if (ac == 1)
		ctx->player_name = ft_strdup("player");
	else
	{
		if ((int)ft_strlen(av[2]) > (9 * ctx->n) - 10)
			ctx->player_name = ft_strdup("player");
		else
			ctx->player_name = ft_strdup(av[2]);
	}
	ctx->n = (ctx->n > 42) ? 42 : ctx->n;
}
