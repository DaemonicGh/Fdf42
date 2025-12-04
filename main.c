/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:29:00 by rprieur           #+#    #+#             */
/*   Updated: 2025/11/06 17:29:01 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

static void	heightmap_update(t_context *context)
{
	mlx_clear_window(context->nacho->mlx, context->nacho->viewport.win,
		color(HM_BG_COLOR));
	update_heightmap_focus(context);
	mlx_put_transformed_image_to_window(context->nacho->mlx,
		context->nacho->viewport.win, context->heightmap.img,
		context->nacho->viewport.width / 2 - ((float)context->grid.width
			/ 2 + context->heightmap.disp.x) * context->heightmap.zoom,
		context->nacho->viewport.height / 2
		- ((float)context->grid.height / 2 + context->heightmap.disp.y)
		* context->heightmap.zoom,
		context->heightmap.zoom, context->heightmap.zoom, 0);
	draw_monitoring_hm(context);
}

static void	isometric_update(t_context *context)
{
	mlx_clear_window(context->nacho->mlx, context->nacho->viewport.win,
		color_lerp(color(ISO_BG_COLOR), color(ISO_BG_COLOR_DARK),
			sinf(context->cam.rotation.y * 0.5) * 0.5 + 0.5));
	draw_grid(context);
	if (context->record_mouse)
		mlx_put_image_to_window(context->nacho->mlx,
			context->nacho->viewport.win, context->crosshair,
			context->nacho->viewport.width / 2 - 8,
			context->nacho->viewport.height / 2 - 8);
	draw_monitoring_iso(context);
}

void	update(void *param)
{
	t_context		*context;

	context = param;
	if (context->nacho->inputs.should_exit)
		free_exit(context, 0, "Exited successfully!");
	update_inputs(context);
	update_fps(context);
	if (context->heightmap_mode)
		heightmap_update(context);
	else
		isometric_update(context);
	mlx_put_transformed_image_to_window(context->nacho->mlx,
		context->nacho->window.win, context->nacho->viewport.image, 0, 0,
		(float)context->nacho->window.width / context->nacho->viewport.width,
		(float)context->nacho->window.height / context->nacho->viewport.height,
		0);
}

void	init(char *file)
{
	t_grid		grid;
	t_context	context;

	grid = get_grid(file);
	if (!grid.grid || !grid.colors)
		put_exit(1, "ERROR: Memory error during parsing!");
	context = init_context(&grid, file);
	nacho_run(context.nacho, update, &context);
	free_exit(&context, 0, "Exited succesfully!");
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write(2, "Please enter 1 argument\n", 25);
		return (-1);
	}
	init(av[1]);
}
