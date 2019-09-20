/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 22:19:50 by skerkour          #+#    #+#             */
/*   Updated: 2014/12/09 13:34:24 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "priv_readline.h"

int		main(void)
{
	char	*ret;

	while (1)
	{
		ret = ft_readline(NULL);
		ft_putchar('\n');
		ft_putendl(ret);
		free(ret);
	}
	return (0);
}
