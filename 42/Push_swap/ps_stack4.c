/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 23:35:56 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/30 21:04:38 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void		ps_sort_3(t_ps_ctx *ctx, t_ps_stack **a)
{
	if (ps_stack_is_sorted_inv(*a))
		ps_sa(ctx, a, 1), ps_putchar(ctx, ' '), ps_rra(ctx, a, 1);
	else if (((*a)->n < (*a)->next->n) && (*a)->n > (*a)->next->next->n)
		ps_rra(ctx, a, 1), ps_putchar(ctx, ' ');
	else if (ps_stack_is_sorted_excepttop(*a))
		ps_sa(ctx, a, 1);
	else if (((*a)->n > (*a)->next->n) && (*a)->n > (*a)->next->next->n)
		ps_ra(ctx, a, 1);
	else if (ps_stack_is_sorted_exceptbot(*a))
		ps_sort_only_bot(ctx, a);
}

void		ps_pushb_min4(t_ps_ctx *ctx, t_ps_stack **a, t_ps_stack **b,
				t_uint min_pos)
{
	if (min_pos == 1)
		ps_ra(ctx, a, 1), ps_putchar(ctx, ' ');
	else if (min_pos == 2)
		ps_ra(ctx, a, 1), ps_putchar(ctx, ' '),
		ps_ra(ctx, a, 1), ps_putchar(ctx, ' ');
	else if (min_pos == 3)
		ps_rra(ctx, a, 1), ps_putchar(ctx, ' ');
	ps_pb(ctx, a, b), ps_putchar(ctx, ' ');
}

void		ps_pushb_min5(t_ps_ctx *ctx, t_ps_stack **a, t_ps_stack **b,
				t_uint min_pos)
{
	if (min_pos == 1)
		ps_ra(ctx, a, 1), ps_putchar(ctx, ' ');
	else if (min_pos == 2)
		ps_ra(ctx, a, 1), ps_putchar(ctx, ' '),
		ps_ra(ctx, a, 1), ps_putchar(ctx, ' ');
	else if (min_pos == 3)
		ps_rra(ctx, a, 1), ps_putchar(ctx, ' '),
		ps_rra(ctx, a, 1), ps_putchar(ctx, ' ');
	else if (min_pos == 4)
		ps_rra(ctx, a, 1), ps_putchar(ctx, ' ');
	ps_pb(ctx, a, b), ps_putchar(ctx, ' ');
}

void		ps_sort_5(t_ps_ctx *ctx, t_ps_stack **a, t_ps_stack **b)
{
	t_uint	pos;

	ctx->n_sorted = 0;
	pos = ps_stack_getmin_pos(ctx, *a);
	ps_pushb_min5(ctx, a, b, pos);
	pos = ps_stack_getmin_pos(ctx, *a);
	ps_pushb_min4(ctx, a, b, pos);
	ps_sort_3(ctx, a);
	ps_pa(ctx, a, b), ps_putchar(ctx, ' ');
	ps_pa(ctx, a, b), ps_putchar(ctx, ' ');
}

int			ps_nomiddlevalu(t_ps_stack *stck, int n, int n2)
{
	while (stck)
	{
		if (stck->n > n && stck->n < n2)
			return (0);
		stck = stck->next;
	}
	return (1);
}
