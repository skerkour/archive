/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:36:58 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/01 16:26:05 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "wong_kar_wai.h"

t_wkw_ctx	*g_ctx;

int			main(int ac, char **av, char **env)
{
	t_wkw_ctx		*ctx;

	if (!*env)
		wkw_error("no environnement detected... Exiting."), ft_exit(-42);
	if ((ctx = (t_wkw_ctx*)ft_memalloc(sizeof(t_wkw_ctx))) == NULL)
		wkw_error("Cannot alloc enought memory... Exiting."), ft_exit(-42);
	if (WIN_VALUE <= 0 || !((WIN_VALUE != 0) && !(WIN_VALUE & (WIN_VALUE - 1))))
		wkw_error("WIN_VALUE is not a power of two... Exinting."), ft_exit(-42);
	wkw_parse_args(ac, av, ctx);
	wkw_init(ctx);
	g_ctx = ctx;
	wkw_start_game(ctx);
	wkw_exit(ctx, 0);
	return (0);
}
