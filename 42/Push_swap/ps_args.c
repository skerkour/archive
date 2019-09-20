/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 19:39:58 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/30 17:36:19 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	ps_parse_flag(t_ps_ctx *ctx, char *arg)
{
	++arg;
	while (*arg)
	{
		if (*arg == 'c')
			ctx->flags |= PS_FLAG_c;
		else if (*arg == 'h')
			ctx->flags |= PS_FLAG_h;
		else if (*arg == 'l')
			ctx->flags |= PS_FLAG_l;
		else if (*arg == 'n')
			ctx->flags |= PS_FLAG_n;
		else if (*arg == 'v')
			ctx->flags |= PS_FLAG_v;
		else if (*arg == 'V')
			ctx->flags |= PS_FLAG_V;
		else if (*arg == 'd')
			ctx->flags |= PS_FLAG_d;
		else
			ps_error();
		++arg;
	}
}

static long	ps_atol(char *str)
{
	long	ret;
	int		is_neg;
	t_uint	i;

	ret = 0;
	is_neg = 0;
	i = 0;
	if (*str == '-')
		++str, is_neg++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			ret += *str++ - '0';
			if (*str >= '0' && *str <= '9')
				ret *= 10;
		}
		else
			ps_error();
		if (i > 11)
			ps_error();
		++i;
	}
	return (is_neg ? -ret : ret);
}

static void	ps_parse_int(t_ps_ctx *ctx, char *arg)
{
	long	n;

	n = ps_atol(arg);
	if (n > INT_MAX || n < INT_MIN)
		ps_error();
	if (ps_stack_is_already_in(ctx->a, (int)n))
		ps_error();
	ps_stack_push(&(ctx->a), (int)n);
}

void		ps_parse_args(t_ps_ctx *ctx, char **av, int ac)
{
	--ac;
	while (ac > 0)
	{
		if (av[ac][0] == '-' && !(av[ac][1]))
			ps_error();
		else if (av[ac][0] == '-' && av[ac][1] && !ft_isdigit(av[ac][1]))
			ps_parse_flag(ctx, av[ac]);
		else
			ps_parse_int(ctx, av[ac]);
		--ac;
	}
}

t_uint		ps_stack_get_len(t_ps_stack *stck)
{
	t_uint	ret;

	ret = 0;
	while (stck)
	{
		stck = stck->next;
		++ret;
	}
	return (ret);
}
