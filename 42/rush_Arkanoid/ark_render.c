/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 23:31:40 by skerkour          #+#    #+#             */
/*   Updated: 2015/05/03 17:44:25 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "arkanoid.h"

void	ark_draw_bar(float x, float size)
{
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(x - size, -0.965f);
	glVertex2f(x + size, -0.965f);
	glVertex2f(x + size, -0.98f);
	glVertex2f(x - size, -0.98f);
	glEnd();
}

void	ark_draw_brick(float x, float y, char value)
{
	glBegin(GL_QUADS);
	if (value == '1')
		glColor3ub(51, 204, 51);
	else if (value == '2')
		glColor3ub(51, 51, 204);
	else if (value == '3')
		glColor3ub(255, 0, 0);
	else
		glColor3ub(155, 155, 155);
	glVertex2f(x, y);
	glVertex2f(x + ARK_BRICK_W, y);
	glVertex2f(x + ARK_BRICK_W, y + ARK_BRICK_H);
	glVertex2f(x, y + ARK_BRICK_H);
	glEnd();
}

void	ark_draw_bricks(t_ark_ctx *ctx)
{
	char			*map;
	unsigned int	i;

	map = ctx->lvl.bricks;
	i = 0;
	while (*map)
	{
		if (*map != '0')
		{
			ark_draw_brick(
				-1 + ((float)(i % ARK_NBIRCKS) * ARK_BRICK_W),
				0.8 - ((float)(i / ARK_NBIRCKS) * ARK_BRICK_H), *map);
		}
		++i;
		++map;
	}
}

void	ark_draw_ball(t_ark_ctx *ctx)
{
	int		i;
	int		tri;
	GLfloat	twice_pi;

	twice_pi = 2.0f * PI;
	tri = 20;
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(ctx->ball.x, ctx->ball.y);
	i = 0;
	while (i <= tri)
	{
		glVertex2f(ctx->ball.x + (ctx->ball.r * cos(i * twice_pi / tri)),
			ctx->ball.y + (ctx->ball.r * sin(i * twice_pi / tri)));
		++i;
	}
	glEnd();
}

void	ark_draw_map(t_ark_ctx *ctx)
{
	glClear(GL_COLOR_BUFFER_BIT);
	ark_draw_bar(ctx->bar.x, ctx->bar.size);
	ark_draw_bricks(ctx);
	ark_draw_ball(ctx);
	ark_display_score(ctx);
	glfwSwapBuffers(ctx->window);
}
