/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 15:13:05 by skerkour          #+#    #+#             */
/*   Updated: 2016/06/10 15:23:00 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int			black_jack_hand(char *hand);

void lol(char *hand, int expected) {
	printf("%s | v = %d | e = %d\n", hand, black_jack_hand(hand), expected);
}


int main() {
	lol("AA", 12);
	lol("2345", 14);
	lol("AA8", 20);
	lol("339A6", 22);
	lol("AAT", 12);
	lol("AT", 21);
	lol("D8", 18);
	lol("A4", 15);
	lol("24", 6);

	return 0;
}
