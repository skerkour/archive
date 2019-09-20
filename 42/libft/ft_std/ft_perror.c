/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:58:18 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/04 19:03:43 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	ft_perror(char *name, char *error, int iexit)
{
	if (name)
	{
		ft_putstr_fd(name, FT_STDERR);
		ft_putstr_fd(": ", FT_STDERR);
	}
	perror(error);
	if (iexit)
		exit(iexit);
}
