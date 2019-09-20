/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   black_jack_hand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 15:03:02 by skerkour          #+#    #+#             */
/*   Updated: 2016/06/10 15:26:53 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	compute_aces(int ret, int n_ace)
{
	ret += n_ace * 11;
	while (n_ace > 0)
	{
		if (ret <= 21)
			return (ret);
		ret -= 10;
		n_ace -= 1;
	}
	return (ret);
}

int			black_jack_hand(char *hand)
{
	unsigned int	i;
	int				ret;
	int				n_ace;

	if (hand == (void*)0)
		return (0);
	i = 0;
	ret = 0;
	n_ace = 0;
	while (hand[i])
	{
		if (hand[i] >= '2' && hand[i] <= '9')
			ret += hand[i] - 0x30;
		else if (hand[i] == 'T' ||
			hand[i] == 'J' || hand[i] == 'D' || hand[i] == 'K')
			ret += 10;
		else if (hand[i] == 'A')
			n_ace += 1;
		i += 1;
	}
	ret = compute_aces(ret, n_ace);
	return (ret);
}
