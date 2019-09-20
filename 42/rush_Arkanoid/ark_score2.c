/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark_score2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 17:28:14 by skerkour          #+#    #+#             */
/*   Updated: 2015/05/03 18:25:44 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	ark_display_digit_0(float col)
{
	ark_display_digit_bar(col * 0.2f, 0.99f, col * 0.2f, 0.87f);
	ark_display_digit_bar((col + 1) * 0.2f, 0.99f, (col + 1) * 0.2f, 0.87f);
	ark_display_digit_bar(col * 0.2f, 0.99f, (col + 1) * 0.2f, 0.99f);
	ark_display_digit_bar(col * 0.2f, 0.87f, (col + 1) * 0.2f, 0.87f);
	ark_display_digit_bar((col + 1) * 0.2f, 0.99f, col * 0.2f, 0.87f);
}

void	ark_display_digit_1(float col)
{
	ark_display_digit_bar((col + 0.5f) * 0.2f, 0.99f,
		(col + 0.5f) * 0.2f, 0.87f);
}

void	ark_display_digit_2(float col)
{
	ark_display_digit_bar(col * 0.2f, 0.99f, (col + 1) * 0.2f, 0.99f);
	ark_display_digit_bar(col * 0.2f, 0.87f, (col + 1) * 0.2f, 0.87f);
	ark_display_digit_bar((col + 1) * 0.2f, 0.99f, col * 0.2f, 0.87f);
}

void	ark_display_digit_3(float col)
{
	ark_display_digit_bar(col * 0.2f, 0.99f, (col + 1) * 0.2f, 0.99f);
	ark_display_digit_bar(col * 0.2f, 0.87f, (col + 1) * 0.2f, 0.87f);
	ark_display_digit_bar((col + 1) * 0.2f, 0.99f, col * 0.2f, 0.93f);
	ark_display_digit_bar(col * 0.2f, 0.93f, (col + 1) * 0.2f, 0.87f);
}

void	ark_display_digit_4(float col)
{
	ark_display_digit_bar((col + 1) * 0.2f, 0.99f, col * 0.2f, 0.93f);
	ark_display_digit_bar(col * 0.2f, 0.93f, (col + 1) * 0.2f, 0.93f);
	ark_display_digit_bar((col + 0.5f) * 0.2f, 0.94f,
		(col + 0.5f) * 0.2f, 0.88f);
}
