/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 16:23:39 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/23 17:31:09 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"
#include "push_swap.h"

void	ps_putchar(t_ps_ctx *ctx, char c)
{
	if (!(ctx->flags & PS_FLAG_d) && ctx->n_sorted < ctx->a_len - 1)
		write(1, &c, 1);
}

void	ps_help(void)
{
	ft_putstr("usage : ./push_swap (-h | -lvnc) N1 N2 N3 ...\n");
	ft_exit(0);
}

void	ps_error(void)
{
	ft_putstr_fd("Error\n", FT_STDERR);
	ft_exit(-42);
}

void	ps_ctx_init(t_ps_ctx *ctx)
{
	ft_bzero(ctx, sizeof(t_ps_ctx));
}

int		main(int ac, char **av)
{
	t_ps_ctx	ctx;

	ps_ctx_init(&ctx);
	if (ac > 1)
	{
		ps_parse_args(&ctx, av, ac);
		if (ctx.flags & PS_FLAG_h)
			ps_help();
		ps_push_swap(&ctx, &(ctx.a), &(ctx.b));
		if ((ctx.flags & PS_FLAG_v) || (ctx.flags & PS_FLAG_V))
		{
			ft_putstr(FT_MAGE), ft_putendl("a's final state :");
			while (ctx.a)
				ft_putnbr(ps_stack_pop(&(ctx.a))), ft_putchar(' ');
			ft_putendl(FT_CEND);
		}
		if (ctx.flags & PS_FLAG_n)
			ft_putstr(FT_MAGE), ft_putendl("Total operations :"),
				ft_putuint(ctx.n_ops), ft_putendl(FT_CEND);
	}
	else
		ps_error();
	return (0);
}
