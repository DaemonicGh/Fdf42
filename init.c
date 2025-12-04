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
	const float	max_grid_side = max(context->grid.width, context->grid.height);
	t_cam		cam;

	cam.rotation = vec2f_new(CAMERA_INIT_ROTATION_X, CAMERA_INIT_ROTATION_Y);
	cam.rotation_cos = vec2f_new(cosf(CAMERA_INIT_ROTATION_X),
			cosf(CAMERA_INIT_ROTATION_Y));
	cam.rotation_sin = vec2f_new(sinf(CAMERA_INIT_ROTATION_X),
			sinf(CAMERA_INIT_ROTATION_Y));
	cam.disp = vec2_new(context->nacho->viewport.width / 2,
			context->nacho->viewport.height / 2);
	cam.zoom = CAMERA_INIT_ZOOM / sqrt(max_grid_side);
	cam.focus = vec3f_new(context->grid.width / 2, context->grid.height / 2,
			get_cell(&context->grid, context->grid.width / 2,
				context->grid.height / 2));
	cam.height_mod = max_grid_side / (context->grid.max - context->grid.min)
		* INIT_HEIGHT_AMPLIFIER;
	return (cam);
}

static void	init_context_values(t_context *context, char *file)
{
	context->line_size = INIT_LINE_SIZE;
	context->colorize_grid = true;
	context->record_mouse = true;
	context->heightmap_mode = false;
	context->file = file;
	context->is_save_success = false;
}

static void	fill_fps_array(float *fps, int size)
{
	int	i;

	i = 0;
	while (i < size)
		fps[i++] = 0;
}

t_context	init_context(t_grid *grid, char *file)
{
	t_context	context;

	context.grid = *grid;
	context.proj_grid = malloc(context.grid.size * sizeof(t_vec2));
	if (!context.proj_grid)
	{
		free(grid->grid);
		free(grid->colors);
		put_exit(1, "ERROR: memory error during initalization!");
	}
	init_context_values(&context, file);
	fill_fps_array(context.fps_record, FPS_ARRAY_SIZE);
	context.nacho = nacho_init(vec2_new(WINDOW_WIDTH, WINDOW_HEIGHT),
			WINDOW_TITLE, WINDOW_FLAGS);
	context.cam = init_camera(&context);
	context.crosshair = mlx_new_image_from_file(context.nacho->mlx,
			CROSSHAIR_IMAGE_PATH, NULL, NULL);
	context.heightmap = make_heightmap(&context);
	mlx_mouse_hide(context.nacho->mlx);
	mlx_set_fps_goal(context.nacho->mlx, MAX_FPS);
	return (context);
}
