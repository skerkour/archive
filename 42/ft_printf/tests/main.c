/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 16:19:54 by skerkour          #+#    #+#             */
/*   Updated: 2015/01/04 18:21:10 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#include "ft_printf.h"

int main(int ac, char **av)
{
	printf("%#x\n", 42);
	printf("4567 |%-10]5d| plip\n", 12);
	printf("4567 |%10]5d| plip\n", 12);
	printf("|%10.5d|\n", -12);
	printf("|%10d|\n", -12);
	printf("|%010d|\n", -12); 
	printf("|%-10.5d|\n", 12);
	printf("|%-010.5d|\n", -12);
	printf("%ll# +++-+-- h00012.3.5.28d\n", 42);
	puts("----------------------------------------------------------------");
	char a = 6;
	printf("%d\n", ft_printf("4567 |%-10]5d| plip\n"));
	printf("%d\n", ft_printf("4567 |%10]5d| plip\n"));
	printf("%d\n", ft_printf("|%10.5d|\n"));
	printf("%d\n", ft_printf("|%10d|\n"));
	printf("%d\n", ft_printf("|%010d|\n"));
	printf("%d\n", ft_printf("|%-10.5d|\n"));
	printf("%d\n", ft_printf("|%-010.5d|\n %s %% %"));
	return (0);
}
