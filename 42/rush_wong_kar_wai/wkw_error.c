/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 00:25:37 by skerkour          #+#    #+#             */
/*   Updated: 2015/02/28 00:26:06 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	wkw_error(char *str)
{
	ft_putstr_fd("game_2048: error: ", FT_STDERR);
	ft_putendl_fd(str, FT_STDERR);
}
