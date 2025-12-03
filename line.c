/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:09:36 by rprieur           #+#    #+#             */
/*   Updated: 2025/11/12 17:09:37 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

static void	put_line_step(t_context *context,
		t_vec2 pos, bool steep, mlx_color *buffer)
{
	if (steep)
	{
		mlx_pixel_put_array(context->nacho->mlx, context->nacho->viewport.win,
			pos.x - (float)context->line_size / 2 - 0.5, pos.y,
			buffer, context->line_size);
	}
	else
	{
		mlx_pixel_put_region(context->nacho->mlx, context->nacho->viewport.win,
			pos.x, pos.y - (float)context->line_size / 2 - 0.5, 1,
			context->line_size, buffer);
	}
}

void	line_put(t_context *context,
		t_vec2 pos1, t_vec2 pos2, mlx_color *buffer)
{
	const t_vec2	d = vec2_new(abs(pos2.x - pos1.x), -abs(pos2.y - pos1.y));
	const t_vec2	s = vec2_new(
			(pos1.x < pos2.x) * 2 - 1, (pos1.y < pos2.y) * 2 - 1);
	int				err;
	int				err2;

	err = d.x + d.y;
	while (1)
	{
		put_line_step(context, pos1, d.x < -d.y, buffer);
		if (pos1.x == pos2.x && pos1.y == pos2.y)
			break ;
		err2 = 2 * err;
		if (err2 >= d.y)
		{
			err += d.y;
			pos1.x += s.x;
		}
		if (err2 <= d.x)
		{
			err += d.x;
			pos1.y += s.y;
		}
	}
	free(buffer);
}
