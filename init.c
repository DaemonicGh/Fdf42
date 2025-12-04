/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeinit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:02:17 by rprieur           #+#    #+#             */
/*   Updated: 2025/11/12 15:02:20 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

static t_cam	init_camera(t_context *context)
{
	t_cam	cam;

	cam.rotation = vec3f_new(0, 0, 0);
	cam.disp = vec2_new(context->nacho->viewport.width / 2,
			context->nacho->viewport.height / 2);
	cam.zoom = 12.0;
	cam.focus = vec3f_new(context->grid.width / 2, context->grid.height / 2,
			get_cell(&context->grid, context->grid.width / 2,
				context->grid.height / 2));
	cam.height_mod = (float)context->grid.width
		/ (context->grid.max - context->grid.min) * 0.1;
	return (cam);
}

static void	fill_fps_array(float *fps, int size)
{
	int	i;

	i = 0;
	while (i < size)
		fps[i++] = 0;
}

t_context	init_window(t_grid *grid, char *file)
{
	t_context	context;

	context.nacho = nacho_init(vec2_new(WINDOW_WIDTH, WINDOW_HEIGHT),
			WINDOW_TITLE, WINDOW_FLAGS);
	context.grid = *grid;
	context.proj_grid = malloc(context.grid.size * sizeof(t_vec2));
	if (!context.proj_grid)
		exit_mlx(&context, 1, "ERROR: memory error during initalization!");
	context.line_size = 3;
	context.colorize_grid = true;
	context.cam = init_camera(&context);
	context.record_mouse = true;
	context.heightmap_mode = false;
	context.heightmap = make_heightmap(&context);
	fill_fps_array(context.fps_record, FPS_ARRAY_SIZE);
	context.crosshair = mlx_new_image_from_file(context.nacho->mlx,
			"assets/crosshair.png", NULL, NULL);
	context.file = file;
	context.is_save_success = false;
	mlx_mouse_hide(context.nacho->mlx);
	mlx_set_fps_goal(context.nacho->mlx, 60);
	return (context);
}
