/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_header.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 13:07:02 by skerkour          #+#    #+#             */
/*   Updated: 2014/12/09 13:07:51 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "priv_readline.h"

void	rl_putheader(char *header)
{
	if (header)
		ft_putstr(header);
}
