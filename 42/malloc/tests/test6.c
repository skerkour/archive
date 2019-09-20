/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 15:28:32 by skerkour          #+#    #+#             */
/*   Updated: 2017/09/26 17:24:42 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./malloc.h"
#include <stdio.h>

int		main(void)
{
	printf("sizeof(t_block) : %lu\n", sizeof(t_block));
	printf("sizeof(int32_t) : %lu\n", sizeof(int32_t));
	return (0);
}
