/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 15:43:51 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/30 17:40:43 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int			ps_nomiddle_min_to_n(t_ps_stack *stck, int min, int n)
{
	while (stck && stck->n != min)
		stck = stck->next;
	if (!stck)
		return (0);
	while (stck)
	{
		if (stck->next)
		{
			if (min > stck->n || stck->next->n < stck->n || stck->n > n)
				return (0);
		}
		stck = stck->next;
	}
	return (1);
}

int			ps_stack_no_min_ahead(t_ps_stack *stck, int n)
{
	stck = stck->next;
	while (stck)
	{
		if (stck->n < n)
			return (0);
		stck = stck->next;
	}
	return (1);
}

int			ps_stack_no_min_before(t_ps_stack *s, t_ps_stack *s_sorted, int n)
{
	while (s != s_sorted)
	{
		if (s->n < n)
			return (0);
		s = s->next;
	}
	return (1);
}

t_uint		ps_stack_get_nsorted(t_ps_stack *s)
{
	t_uint		ret;
	t_ps_stack	*start;
	t_ps_stack	*start_sorted;

	start = s;
	ret = 0;
	start_sorted = start;
	while (s)
	{
		if (ps_stack_no_min_ahead(s, s->n)
				&& ps_stack_no_min_before(start, start_sorted, s->n))
			++ret, start_sorted = ret == 1 ? s : start_sorted;
		else
		{
			ret = 0;
			start_sorted = s;
		}
		s = s->next;
	}
	return (ret);
}

t_uint		ps_stack_getmin_pos(t_ps_ctx *ctx, t_ps_stack *stck)
{
	int		min;
	t_uint	ret;
	t_uint	pos;

	ret = 0;
	pos = 0;
	min = stck->n;
	while (stck && pos < (ctx->a_len - ctx->n_sorted))
	{
		if (stck->n < min)
		{
			min = stck->n;
			ret = pos;
		}
		stck = stck->next;
		++pos;
	}
	return (ret);
}
