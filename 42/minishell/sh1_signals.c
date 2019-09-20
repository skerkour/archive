/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1_signals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 17:38:36 by skerkour          #+#    #+#             */
/*   Updated: 2015/01/04 15:34:06 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include "ft_sh1.h"

void	sh1_set_signals_hook(void)
{
	signal(SIGINT, sh1_hkd_sigint);
	signal(SIGTSTP, sh1_hkd_sigtstp);
}
