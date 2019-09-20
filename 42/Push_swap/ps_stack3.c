/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 20:41:32 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/25 23:44:17 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int		ps_stack_getmin_value(t_ps_stack *stck)
{
	int		ret;

	ret = stck->n;
	while (stck)
	{
		if (stck->n < ret)
			ret = stck->n;
		stck = stck->next;
	}
	return (ret);
}

int		ps_stack_is_sorted_exceptbot(t_ps_stack *stck)
{
	if (stck->next)
	{
		while (stck->next->next)
		{
			if (stck->next->n < stck->n)
				return (0);
			stck = stck->next;
		}
		if (stck->next->n < stck->n)
			return (1);
	}
	return (0);
}

int		ps_stack_is_sorted_excepttop(t_ps_stack *stck)
{
	int	tmp;

	if (stck && stck->next)
	{
		if (stck->next->n < stck->n && stck->next->next)
		{
			tmp = stck->n;
			stck = stck->next;
			if (tmp < stck->next->n)
				return (ps_stack_is_sorted(stck));
		}
		return (0);
	}
	return (0);
}

int		ps_stack_is_sorted_inv(t_ps_stack *stck)
{
	while (stck)
	{
		if (stck->next)
		{
			if (stck->next->n > stck->n)
				return (0);
		}
		stck = stck->next;
	}
	return (1);
}

int		ps_stack_is_sorted(t_ps_stack *stck)
{
	if (!stck)
		return (0);
	while (stck)
	{
		if (stck->next)
		{
			if (stck->next->n < stck->n)
				return (0);
		}
		stck = stck->next;
	}
	return (1);
}
