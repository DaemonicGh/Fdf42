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

#include "includes/fdf.h"

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

void	update_heightmap_colors(t_context *context, mlx_image image)
{
	mlx_color	*buffer;
	int			i;

	buffer = malloc(sizeof(mlx_color) * context->grid.size);
	if (!buffer)
		exit_mlx(context, 1, "ERROR: memory error during heightmap refresh");
	i = 0;
	while (i < context->grid.size)
	{
		buffer[i] = normalize_z_color(&context->grid, context->grid.grid[i]);
		i++;
	}
	mlx_set_image_region(context->nacho->mlx, image, 0, 0,
		context->grid.width, context->grid.height, buffer);
	free(buffer);
}

t_heightmap	make_heightmap(t_context *context)
{
	t_heightmap	heightmap;

	heightmap.img = mlx_new_image(context->nacho->mlx,
			context->grid.width, context->grid.height);
	update_heightmap_colors(context, heightmap.img);
	heightmap.zoom = fmin((float)context->nacho->viewport.width
			/ context->grid.width, (float)context->nacho->viewport.height
			/ context->grid.height) * 0.8;
	heightmap.disp.x = 0;
	heightmap.disp.y = 0;
	heightmap.focus = vec3_new(0, 0, 0);
	return (heightmap);
}

static void	update_focus(t_context *context)
{
	context->heightmap.focus.x = min(max((context->nacho->inputs.mouse.x
					- (context->nacho->viewport.width / 2
						- (((float)context->grid.width / 2
								+ context->heightmap.disp.x)
							* context->heightmap.zoom)))
				/ context->heightmap.zoom, 0), context->grid.width - 1);
	context->heightmap.focus.y = min(max((context->nacho->inputs.mouse.y
					- (context->nacho->viewport.height / 2
						- (((float)context->grid.height / 2
								+ context->heightmap.disp.y)
							* context->heightmap.zoom)))
				/ context->heightmap.zoom, 0), context->grid.height - 1);
	context->heightmap.focus.z = *get_cell(&context->grid,
			context->heightmap.focus.x, context->heightmap.focus.y);
}

void	update_heightmap_focus(t_context *context)
{
	mlx_color	col;

	col = mlx_get_image_pixel(context->nacho->mlx, context->heightmap.img,
			context->heightmap.focus.x, context->heightmap.focus.y);
	col.g = col.r;
	col.b = col.r;
	mlx_set_image_pixel(context->nacho->mlx, context->heightmap.img,
		context->heightmap.focus.x, context->heightmap.focus.y, col);
	update_focus(context);
	col = mlx_get_image_pixel(context->nacho->mlx, context->heightmap.img,
			context->heightmap.focus.x, context->heightmap.focus.y);
	col.g = 0x00;
	col.b = 0xFF;
	mlx_set_image_pixel(context->nacho->mlx, context->heightmap.img,
		context->heightmap.focus.x, context->heightmap.focus.y, col);
}
