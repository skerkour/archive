/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark_score3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 18:16:20 by skerkour          #+#    #+#             */
/*   Updated: 2015/05/03 18:43:26 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	ark_display_digit_5(float col)
{
	ark_display_digit_bar(col * 0.2f, 0.87f, (col + 1) * 0.2f, 0.87f);
	ark_display_digit_bar(col * 0.2f, 0.99f, (col + 1) * 0.2f, 0.99f);
	ark_display_digit_bar(col * 0.2f, 0.93f, (col + 1) * 0.2f, 0.93f);
	ark_display_digit_bar(col * 0.2f, 0.99f, col * 0.2f, 0.93f);
	ark_display_digit_bar((col + 1) * 0.2f, 0.93f, (col + 1) * 0.2f, 0.87f);
}

void	ark_display_digit_6(float col)
{
	ark_display_digit_bar(col * 0.2f, 0.87f, (col + 1) * 0.2f, 0.87f);
	ark_display_digit_bar(col * 0.2f, 0.93f, (col + 1) * 0.2f, 0.93f);
	ark_display_digit_bar(col * 0.2f, 0.99f, col * 0.2f, 0.87f);
	ark_display_digit_bar((col + 1) * 0.2f, 0.93f, (col + 1) * 0.2f, 0.87f);
}

void	ark_display_digit_7(float col)
{
	ark_display_digit_bar(col * 0.2f, 0.99f, (col + 1) * 0.2f, 0.99f);
	ark_display_digit_bar((col + 1) * 0.2f, 0.99f, col * 0.2f, 0.87f);
}

void	ark_display_digit_8(float col)
{
	ark_display_digit_bar(col * 0.2f, 0.99f, (col + 1) * 0.2f, 0.99f);
	ark_display_digit_bar(col * 0.2f, 0.87f, (col + 1) * 0.2f, 0.87f);
	ark_display_digit_bar(col * 0.2f, 0.93f, (col + 1) * 0.2f, 0.93f);
	ark_display_digit_bar(col * 0.2f, 0.99f, col * 0.2f, 0.87f);
	ark_display_digit_bar((col + 1) * 0.2f, 0.99f, (col + 1) * 0.2f, 0.87f);
}

void	ark_display_digit_9(float col)
{
	ark_display_digit_bar(col * 0.2f, 0.87f, (col + 1) * 0.2f, 0.87f);
	ark_display_digit_bar(col * 0.2f, 0.93f, (col + 1) * 0.2f, 0.93f);
	ark_display_digit_bar(col * 0.2f, 0.99f, col * 0.2f, 0.93f);
	ark_display_digit_bar((col + 1) * 0.2f, 0.93f, (col + 1) * 0.2f, 0.87f);
}
