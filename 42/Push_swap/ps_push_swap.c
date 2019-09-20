/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 18:51:58 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/30 21:01:36 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ps_sort(t_ps_ctx *ctx, t_ps_stack **a, t_ps_stack **b)
{
	t_uint	min_pos;
	t_uint	i;

	i = 0;
	if ((min_pos = ps_stack_getmin_pos(ctx, *a)) == 0)
		ps_ra(ctx, a, 1), ps_putchar(ctx, ' ');
	else if (min_pos >= ctx->a_mid)
	{
		while (i < ctx->a_len - min_pos)
			ps_rra(ctx, a, 1), ps_putchar(ctx, ' '), ++i;
		ps_pb(ctx, a, b), ps_putchar(ctx, ' '), i = 0;
		while (i < ctx->a_len - min_pos - 1)
			ps_ra(ctx, a, 1), ps_putchar(ctx, ' '), ++i;
		ps_pa(ctx, a, b), ps_putchar(ctx, ' '), ps_ra(ctx, a, 1), PS(ctx);
	}
	else
	{
		while (i < min_pos)
			ps_ra(ctx, a, 1), ps_putchar(ctx, ' '), ++i;
		ps_pb(ctx, a, b), ps_putchar(ctx, ' '), i = 0;
		while (i < min_pos)
			ps_rra(ctx, a, 1), ps_putchar(ctx, ' '), ++i;
		ps_pa(ctx, a, b), ps_putchar(ctx, ' '), ps_ra(ctx, a, 1), PS(ctx);
	}
}

void	ps_sort_only_bot(t_ps_ctx *ctx, t_ps_stack **a)
{
	ps_rra(ctx, a, 1), ps_putchar(ctx, ' ');
	ps_rra(ctx, a, 1), ps_putchar(ctx, ' ');
	ps_sa(ctx, a, 1), ps_putchar(ctx, ' ');
	ps_ra(ctx, a, 1), ps_putchar(ctx, ' ');
	ps_ra(ctx, a, 1), ps_putchar(ctx, ' ');
}

void	ps_sort_inv(t_ps_ctx *ctx, t_ps_stack **a, t_ps_stack **b)
{
	t_uint	i;

	i = 0;
	while (i++ < ctx->a_len - 2)
		ps_rra(ctx, a, 1), ps_putchar(ctx, ' '),
			ps_pb(ctx, a, b), ps_putchar(ctx, ' ');
	ps_ra(ctx, a, 1), ps_putchar(ctx, ' ');
	i = 0;
	while (i++ < ctx->a_len - 2)
	{
		ps_pa(ctx, a, b);
		if (i < ctx->a_len - 2)
			ps_putchar(ctx, ' ');
	}
}

void	ps_push_swap(t_ps_ctx *ctx, t_ps_stack **a, t_ps_stack **b)
{
	if ((ctx->a_len = ps_stack_get_len(*a)) <= 1)
		return ;
	ctx->a_mid = (ctx->a_len / 2) + ((!(ctx->a_len & 1)) ? 0 : 1);
	if ((ctx->n_sorted = ps_stack_get_nsorted(*a)) == ctx->a_len)
		return ;
	if (ctx->a_len == 2 && (*a)->next->n < (*a)->n)
		ps_ra(ctx, a, 1), ps_putchar(ctx, ' ');
	else if (ctx->a_len == 3)
		ps_sort_3(ctx, a);
	else if (ctx->a_len == 5)
		ps_sort_5(ctx, a, b);
	else if (ps_stack_is_sorted_excepttop(*a))
		ps_sa(ctx, a, 1);
	else if (ps_stack_is_sorted_exceptbot(*a))
		ps_sort_only_bot(ctx, a);
	else if (ps_stack_is_sorted_inv(*a))
		ps_sort_inv(ctx, a, b);
	else
	{
		while (ctx->n_sorted < ctx->a_len)
			ps_sort(ctx, a, b), (ctx->n_sorted)++;
	}
	(!(ctx->flags & PS_FLAG_d)) ? ft_putchar('\n') : (void)ctx;
}
