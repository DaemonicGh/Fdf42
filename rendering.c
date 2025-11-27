/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 20:28:58 by rprieur           #+#    #+#             */
/*   Updated: 2025/11/18 20:29:00 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec2	project_iso(t_cam *cam, t_vec3 p)
{
	const t_vec3	d = vec3_sub(p, cam->focus);
	const float		rx = d.x * cam->hrot.cos - d.y * cam->hrot.sin;
	const float		ry = d.x * cam->hrot.sin + d.y * cam->hrot.cos;
	t_vec2			proj;

	proj = vec2_new(cam->disp.x, cam->disp.y);
	proj.x += rx * cam->matrix[0][0] * cam->zoom;
	proj.y += rx * cam->matrix[0][1] * cam->zoom;
	proj.x += ry * cam->matrix[1][0] * cam->zoom;
	proj.y += ry * cam->matrix[1][1] * cam->zoom;
	proj.x += (p.z - cam->focus.z) * cam->matrix[2][0] * cam->zoom
		* cam->height_mod;
	proj.y += (p.z - cam->focus.z) * cam->matrix[2][1] * cam->zoom
		* cam->height_mod;
	return (proj);
}

static mlx_color	get_line_color(t_grid *grid, int pi1, int pi2)
{
	if (grid->grid[pi1] > grid->grid[pi2])
	{
		if (grid->colors[pi1] != NULL_COLOR)
			return (color(grid->colors[pi1]));
		if (grid->colors[pi2] != NULL_COLOR)
			return (color(grid->colors[pi2]));
	}
	else
	{
		if (grid->colors[pi2] != NULL_COLOR)
			return (color(grid->colors[pi2]));
		if (grid->colors[pi1] != NULL_COLOR)
			return (color(grid->colors[pi1]));
	}
	return (color_lerp(color(LOW_LINE_COLOR), color(HIGH_LINE_COLOR),
			normalize_z(grid, (float)(grid->grid[pi1] + grid->grid[pi2]) / 2)));
}

static void	draw_grid_forward(t_context *context)
{
	int		i;
	t_vec3	pos;

	i = 0;
	while (i < context->grid.size)
	{
		pos = get_cell_at_i(&context->grid, i);
		context->proj_grid[i] = project_iso(&context->cam, pos);
		if (pos.x > 0 && (point_on_screen(context, context->proj_grid[i])
				|| point_on_screen(context, context->proj_grid[i - 1])))
			line_put(context, context->proj_grid[i], context->proj_grid[i - 1],
				get_line_color(&context->grid, i, i - 1));
		if (pos.y > 0 && (point_on_screen(context, context->proj_grid[i])
				|| point_on_screen(context,
					context->proj_grid[i - context->grid.width])))
			line_put(context, context->proj_grid[i],
				context->proj_grid[i - context->grid.width],
				get_line_color(&context->grid, i, i - context->grid.width));
		i++;
	}
}

static void	draw_grid_backward(t_context *context)
{
	int		i;
	t_vec3	pos;

	i = context->grid.size - 1;
	while (i >= 0)
	{
		pos = get_cell_at_i(&context->grid, i);
		context->proj_grid[i] = project_iso(&context->cam, pos);
		if (pos.x + 1 < context->grid.width
			&& (point_on_screen(context, context->proj_grid[i])
				|| point_on_screen(context, context->proj_grid[i + 1])))
			line_put(context, context->proj_grid[i], context->proj_grid[i + 1],
				get_line_color(&context->grid, i, i + 1));
		if (pos.y + 1 < context->grid.height
			&& (point_on_screen(context, context->proj_grid[i])
				|| point_on_screen(context,
					context->proj_grid[i + context->grid.width])))
			line_put(context, context->proj_grid[i],
				context->proj_grid[i + context->grid.width],
				get_line_color(&context->grid, i, i + context->grid.width));
		i--;
	}
}

void	draw_grid(t_context *context)
{
	if (context->grid.size <= 0)
		return ;
	if (context->cam.hrot.angle >= M_PI_4
		&& context->cam.hrot.angle < M_PI + M_PI_4)
		draw_grid_backward(context);
	else
		draw_grid_forward(context);
}
