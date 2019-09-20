/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 22:46:43 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/22 19:37:17 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ps_rra(t_ps_ctx *ctx, t_ps_stack **a, t_bool print)
{
	t_ps_stack	*tmp;

	(ctx->n_ops)++;
	if (print)
		ft_putn("rra", 3);
	tmp = *a;
	if (*a && (*a)->next)
	{
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->next->next = *a;
		*a = tmp->next;
		tmp->next = NULL;
	}
	if (print && (ctx->flags & PS_FLAG_d))
		ps_stack_print_both(ctx->a, ctx->b);
}

void	ps_rrb(t_ps_ctx *ctx, t_ps_stack **b, t_bool print)
{
	t_ps_stack	*tmp;

	(ctx->n_ops)++;
	if (print)
		ft_putn("rrb", 3);
	tmp = *b;
	if (*b && (*b)->next)
	{
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->next->next = *b;
		*b = tmp->next;
		tmp->next = NULL;
	}
	if (print && (ctx->flags & PS_FLAG_d))
		ps_stack_print_both(ctx->a, ctx->b);
}

void	ps_rrr(t_ps_ctx *ctx, t_ps_stack **a, t_ps_stack **b)
{
	ft_putn("rrr", 3);
	ps_rra(ctx, a, 0);
	ps_rrb(ctx, b, 0);
	(ctx->n_ops)--;
	if (ctx->flags & PS_FLAG_d)
		ps_stack_print_both(ctx->a, ctx->b);
}
