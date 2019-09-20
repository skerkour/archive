/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 22:45:08 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/22 19:37:10 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ps_ra(t_ps_ctx *ctx, t_ps_stack **a, t_bool print)
{
	t_ps_stack	*tmp;

	(ctx->n_ops)++;
	if (print)
		ft_putn("ra", 2);
	tmp = *a;
	if (*a && (*a)->next)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *a;
		*a = (*a)->next;
		tmp->next->next = NULL;
	}
	if (print && (ctx->flags & PS_FLAG_d))
		ps_stack_print_both(ctx->a, ctx->b);
}

void	ps_rb(t_ps_ctx *ctx, t_ps_stack **b, t_bool print)
{
	t_ps_stack	*tmp;

	(ctx->n_ops)++;
	if (print)
		ft_putn("rb", 2);
	tmp = *b;
	if (*b && (*b)->next)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *b;
		*b = (*b)->next;
		tmp->next->next = NULL;
	}
	if (print && (ctx->flags & PS_FLAG_d))
		ps_stack_print_both(ctx->a, ctx->b);
}

void	ps_rr(t_ps_ctx *ctx, t_ps_stack **a, t_ps_stack **b)
{
	ft_putn("rr", 2);
	ps_ra(ctx, a, 0);
	ps_rb(ctx, b, 0);
	(ctx->n_ops)--;
	if (ctx->flags & PS_FLAG_d)
		ps_stack_print_both(ctx->a, ctx->b);
}
