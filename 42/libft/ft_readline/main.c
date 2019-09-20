/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 22:19:50 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/08 16:37:36 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"
#include "libft.h"
#include <stdlib.h>

int		main(void)
{
	char	*ret;

	while (1)
	{
		ret = ft_readline("$> ");
		ft_putchar('\n');
		ft_putendl(ret ? ret : "error with ret");
		free(ret);
	}
	return (0);
}
