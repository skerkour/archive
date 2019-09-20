/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark_score.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 16:58:18 by skerkour          #+#    #+#             */
/*   Updated: 2015/05/03 18:18:48 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	ark_display_digit_bar(float x1, float y1, float x2, float y2)
{
	glBegin(GL_LINES);
	glColor3ub(51, 204, 255);
	glLineWidth(4.0);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
}

void	ark_display_score_digit(char digit, float col)
{
	if (digit == 0)
		ark_display_digit_0(col);
	else if (digit == 1)
		ark_display_digit_1(col);
	else if (digit == 2)
		ark_display_digit_2(col);
	else if (digit == 3)
		ark_display_digit_3(col);
	else if (digit == 4)
		ark_display_digit_4(col);
	else if (digit == 5)
		ark_display_digit_5(col);
	else if (digit == 6)
		ark_display_digit_6(col);
	else if (digit == 7)
		ark_display_digit_7(col);
	else if (digit == 8)
		ark_display_digit_8(col);
	else
		ark_display_digit_9(col);
}

void	ark_display_score(t_ark_ctx *ctx)
{
	unsigned long	score;
	unsigned		col;
	char			digit;
	int				display;

	col = 4;
	score = ctx->score;
	display = 1;
	while (display)
	{
		digit = score % 10;
		ark_display_score_digit(digit, (float)col);
		score /= 10;
		--col;
		display = !score ? 0 : 1;
	}
}
