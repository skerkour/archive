/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_isize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 11:40:30 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/24 14:25:51 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ushort	ft_count_isize(int n)
{
	t_ushort	ret;

	if (n == 0)
		return (1);
	ret = 0;
	while (n)
		ret++, n /= 10;
	return (ret);
}
