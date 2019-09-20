/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1_hooked_signals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 17:40:19 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/08 17:45:44 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "ft_sh1.h"

void	sh1_hkd_sigint(int sign)
{
	char	*header;

	UNUSED(sign);
	ft_putchar('\n');
	if ((header = sh1_get_header(*g_env)))
		ft_putstr(header), free(header);
}

void	sh1_hkd_sigtstp(int sign)
{
	UNUSED(sign);
}
