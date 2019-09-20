/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_spawn_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asleewae <asleewae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:01:32 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/01 17:29:36 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>

#include "libft.h"
#include "wong_kar_wai.h"

void	wkw_spawn_nbr(t_wkw_ctx *ctx)
{
	int nb_a;
	int nb_grid;
	int nb_found;

	nb_a = 0;
	nb_found = 0;
	srand(time(NULL));
	while (!nb_found)
	{
		nb_grid = rand() % (ctx->n * ctx->n);
		if (ctx->grid[nb_grid].v == 0)
		{
			nb_a = rand() % 4;
			if (nb_a == 0 || nb_a == 1)
				nb_a = 2;
			else if (nb_a == 2 || nb_a == 3)
				nb_a = 4;
			nb_found = 1;
			ctx->grid[nb_grid].v = nb_a;
		}
	}
}
