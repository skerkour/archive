/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 23:30:02 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/30 15:46:22 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "push_swap.h"

void	ps_stack_print_both(t_ps_stack *a, t_ps_stack *b)
{
	ft_putchar('\n'), ft_putstr(FT_BLUE), ft_putstr("a : ");
	while (a)
		ft_putnbr(a->n), ft_putchar(' '), a = a->next;
	ft_putstr(FT_CEND);
	ft_putchar('\n'), ft_putstr(FT_RED), ft_putstr("b : ");
	while (b)
		ft_putnbr(b->n), ft_putchar(' '), b = b->next;
	ft_putendl(FT_CEND);
}

int		ps_stack_is_already_in(t_ps_stack *stck, int n)
{
	while (stck)
	{
		if (n == stck->n)
			return (1);
		stck = stck->next;
	}
	return (0);
}

int		ps_stack_peek(t_ps_stack *stack)
{
	return (stack->n);
}

int		ps_stack_pop(t_ps_stack **stck)
{
	int			ret;
	t_ps_stack	*tmp;

	ret = (*stck)->n;
	tmp = *stck;
	*stck = (*stck)->next;
	free(tmp);
	return (ret);
}

void	ps_stack_push(t_ps_stack **stck, int n)
{
	t_ps_stack	*new;

	if ((new = (t_ps_stack*)malloc(sizeof(t_ps_stack))) == NULL)
		ps_error();
	new->next = *stck;
	new->n = n;
	*stck = new;
}
