/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heightmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:06:37 by rprieur           #+#    #+#             */
/*   Updated: 2025/11/20 17:06:38 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	toggle_heightmap(t_context *context)
{
	context->nacho->inputs.record_mouse = context->heightmap_mode;
	context->heightmap_mode = !context->heightmap_mode;
	nacho_warp_mouse(context->nacho, context->nacho->viewport.width / 2,
		context->nacho->viewport.height / 2);
	if (context->heightmap_mode)
		mlx_mouse_show(context->nacho->mlx);
	else
		mlx_mouse_hide(context->nacho->mlx);
}

t_heightmap	make_heightmap(t_context *context)
{
	t_heightmap	heightmap;
	mlx_color	*img;
	int			i;

	heightmap.img = mlx_new_image(context->nacho->mlx,
			context->grid.width, context->grid.height);
	img = malloc(sizeof(mlx_color) * context->grid.size);
	if (!img)
		exit_mlx(context);
	i = 0;
	while (i < context->grid.size)
	{
		img[i] = normalize_z_color(&context->grid, context->grid.grid[i]);
		i++;
	}
	mlx_set_image_region(context->nacho->mlx, heightmap.img, 0, 0,
		context->grid.width, context->grid.height, img);
	heightmap.zoom = fmin((float)context->nacho->viewport.width
			/ context->grid.width, (float)context->nacho->viewport.height
			/ context->grid.height) * 0.8;
	heightmap.dispx = 0;
	heightmap.dispy = 0;
	heightmap.focus = vec2_new(0, 0);
	return (heightmap);
}

static void	update_focus(t_context *context)
{
	context->heightmap.focus.x = min(max((context->nacho->inputs.mouse.x
					- (context->nacho->viewport.width / 2
						- (((float)context->grid.width / 2
								+ context->heightmap.dispx)
							* context->heightmap.zoom)))
				/ context->heightmap.zoom, 0), context->grid.width - 1);
	context->heightmap.focus.y = min(max((context->nacho->inputs.mouse.y
					- (context->nacho->viewport.height / 2
						- (((float)context->grid.height / 2
								+ context->heightmap.dispy)
							* context->heightmap.zoom)))
				/ context->heightmap.zoom, 0), context->grid.height - 1);
}

void	update_heightmap(t_context *context)
{
	mlx_color	col;

	col = mlx_get_image_pixel(context->nacho->mlx, context->heightmap.img,
			context->heightmap.focus.x, context->heightmap.focus.y);
	col.g = col.r;
	col.b = col.r;
	update_focus(context);
	mlx_set_image_pixel(context->nacho->mlx, context->heightmap.img,
		context->heightmap.focus.x, context->heightmap.focus.y, col);
	col = mlx_get_image_pixel(context->nacho->mlx, context->heightmap.img,
			context->heightmap.focus.x, context->heightmap.focus.y);
	col.g = 0x00;
	col.b = 0xFF;
	mlx_set_image_pixel(context->nacho->mlx, context->heightmap.img,
		context->heightmap.focus.x, context->heightmap.focus.y, col);
}
