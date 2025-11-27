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

#include "fdf.h"

static mlx_color actual_transparency(t_ncontext *nacho, t_vec2 pos, mlx_color col, float alpha)
{
	mlx_color	bg_color;

 	bg_color = mlx_get_image_pixel(nacho->mlx, nacho->viewport.image, pos.x, pos.y);
	if (bg_color.rgba == 0x0)
		bg_color = color(ACTUAL_ISO_BG_COLOR);
  	return (color_lerp(col, bg_color, alpha));
}

static void	put_blurry_pixel(t_ncontext *nacho, t_vec2 pos, bool steep, mlx_color col)
{
	mlx_pixel_put(nacho->mlx, nacho->viewport.win, pos.x, pos.y, col);
 	if (steep)
	{
		pos.x += 1;
		mlx_pixel_put(nacho->mlx, nacho->viewport.win, pos.x, pos.y,
			actual_transparency(nacho, pos, col, 0.9));
		pos.x -= 2;
		mlx_pixel_put(nacho->mlx, nacho->viewport.win, pos.x, pos.y,
			actual_transparency(nacho, pos, col, 0.9));
	}
 	else
	{
		pos.y += 1;
		mlx_pixel_put(nacho->mlx, nacho->viewport.win, pos.x, pos.y,
			actual_transparency(nacho, pos, col, 0.9));
		pos.y -= 2;
		mlx_pixel_put(nacho->mlx, nacho->viewport.win, pos.x, pos.y,
			actual_transparency(nacho, pos, col, 0.9));
	}
}

void	line_put(const t_context *context,
		t_vec2 pos1, t_vec2 pos2, mlx_color col)
{
	const t_vec2	d = vec2_new(abs(pos2.x - pos1.x), -abs(pos2.y - pos1.y));
	const t_vec2	s = vec2_new(
			(pos1.x < pos2.x) * 2 - 1, (pos1.y < pos2.y) * 2 - 1);
	int				err;
	int				e2;

	err = d.x + d.y;
	while (1)
	{
   		put_blurry_pixel(context->nacho, pos1, err < 0, col);
		if (pos1.x == pos2.x && pos1.y == pos2.y)
			break ;
		e2 = 2 * err;
		if (e2 >= d.y)
		{
			err += d.y;
			pos1.x += s.x;
		}
		if (e2 <= d.x)
		{
			err += d.x;
			pos1.y += s.y;
		}
	}
}
