/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 22:44:16 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/22 19:38:40 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ps_sa(t_ps_ctx *ctx, t_ps_stack **a, t_bool print)
{
	(ctx->n_ops)++;
	if (print)
		ft_putn("sa", 2);
	if ((*a)->next)
	{
		(*a)->n ^= (*a)->next->n;
		(*a)->next->n ^= (*a)->n;
		(*a)->n ^= (*a)->next->n;
	}
	if (print && (ctx->flags & PS_FLAG_d))
		ps_stack_print_both(ctx->a, ctx->b);
}

void	ps_sb(t_ps_ctx *ctx, t_ps_stack **b, t_bool print)
{
	(ctx->n_ops)++;
	if (print)
		ft_putn("sb", 2);
	if ((*b)->next)
	{
		(*b)->n ^= (*b)->next->n;
		(*b)->next->n ^= (*b)->n;
		(*b)->n ^= (*b)->next->n;
	}
	if (print && (ctx->flags & PS_FLAG_d))
		ps_stack_print_both(ctx->a, ctx->b);
}

void	ps_ss(t_ps_ctx *ctx, t_ps_stack **a, t_ps_stack **b)
{
	ft_putn("ss", 2);
	ps_sa(ctx, a, 0);
	ps_sb(ctx, b, 0);
	(ctx->n_ops)--;
	if (ctx->flags & PS_FLAG_d)
		ps_stack_print_both(ctx->a, ctx->b);
}

void	ps_pa(t_ps_ctx *ctx, t_ps_stack **a, t_ps_stack **b)
{
	ft_putn("pa", 2);
	(ctx->n_ops)++;
	if (*b)
		ps_stack_push(a, ps_stack_pop(b));
	if (ctx->flags & PS_FLAG_d)
		ps_stack_print_both(ctx->a, ctx->b);
}

void	ps_pb(t_ps_ctx *ctx, t_ps_stack **a, t_ps_stack **b)
{
	ft_putn("pb", 2);
	(ctx->n_ops)++;
	if (*a)
		ps_stack_push(b, ps_stack_pop(a));
	if (ctx->flags & PS_FLAG_d)
		ps_stack_print_both(ctx->a, ctx->b);
}
