/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 15:27:35 by skerkour          #+#    #+#             */
/*   Updated: 2017/09/26 15:27:55 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		main(void)
{
	int		i;
	void	*ptr;

	i = 0;
	ptr = NULL;
	write(1, "test0\n", 6);
	while (i < 1024)
	{
		++i;
	}
	return (0);
}
