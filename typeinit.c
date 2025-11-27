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

#include "fdf.h"

static t_cam	init_camera(t_context *context)
{
	t_cam	cam;

	cam = (t_cam){.matrix = {{0.866, 0.5}, {-0.866, 0.5}, {0.0, -1.0}}};
	cam.hrot = (t_angle){.angle = 0.0, .cos = 1.0, .sin = 0.0};
	cam.disp = vec2_new(context->nacho->viewport.width / 2,
			context->nacho->viewport.height / 2);
	cam.zoom = 12.0;
	cam.focus = vec3_new(context->grid.width / 2, context->grid.height / 2,
			get_cell(&context->grid, context->grid.width / 2,
				context->grid.height / 2));
	cam.height_mod = 0.5;
	return (cam);
}

t_context	init_window(t_grid *grid)
{
	t_context					context;

	context.nacho = nacho_init(vec2_new(WINDOW_WIDTH, WINDOW_HEIGHT),
			WINDOW_TITLE, WINDOW_FLAGS);
	context.grid = *grid;
	context.proj_grid = malloc(context.grid.size * sizeof(t_vec2));
	if (!context.proj_grid)
		exit_mlx(&context);
	context.cam = init_camera(&context);
	context.heightmap_mode = false;
	context.heightmap = make_heightmap(&context);
	context.crosshair = mlx_new_image_from_file(context.nacho->mlx,
			"assets/crosshair.png", NULL, NULL);
	mlx_mouse_hide(context.nacho->mlx);
	mlx_set_fps_goal(context.nacho->mlx, 60);
	return (context);
}
