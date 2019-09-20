/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_graphics2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:49:22 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/31 15:55:43 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "fdf.h"

int32_t	fdf_get_color(t_fdf_point p1, t_fdf_point p2)
{
	int32_t	color;
	int32_t	z;

	if (p2.color > p1.color)
		z = p2.color;
	else
		z = p1.color;
	if (z < 0)
		color = 0x0d6386;
	else if (z >= 0 && z < 15)
		color = 0x24b75f;
	else if (z >= 15 && z < 30)
		color = 0x8acc97;
	else if (z >= 30 && z < 45)
		color = 0xf1f3c4;
	else if (z >= 45 && z < 75)
		color = 0x9c7554;
	else if (z >= 75 && z < 100)
		color = 0xe1d5cb;
	else if (z >= 100)
		color = 0xffffff;
	else
		color = 0xffffff;
	return (color);
}
