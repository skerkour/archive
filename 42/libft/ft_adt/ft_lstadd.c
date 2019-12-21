/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:51:36 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/15 19:11:34 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_lst **alst, t_lst *new)
{
	if (alst && *alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}