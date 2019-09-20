/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_bench.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 18:07:37 by skerkour          #+#    #+#             */
/*   Updated: 2015/05/28 18:27:47 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main(void)
{
	char *lol = strdup("wwdddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	int i = 0;

	while (i++ < 15)
		lol = ft_strjoin(lol, lol);

	clock_t begin, end;
	double time_spent;
	i = 0;
	begin = clock();
	while (i++ < 8400)
		ft_strlen(lol);
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("time : %lf\n", time_spent);
	return (0);
}
