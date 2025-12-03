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

#include "includes/fdf.h"

static void	draw_grid_forward(t_context *context)
{
	int		i;
	t_vec3	pos;

	i = 0;
	while (i < context->grid.size)
	{
		pos = get_cell_at_i(&context->grid, i);
		context->proj_grid[i] = project_iso(&context->cam, pos);
		if (pos.x > 0 && (!should_cull_line(context->nacho,
					context->proj_grid[i], context->proj_grid[i - 1])))
			line_put(context, context->proj_grid[i], context->proj_grid[i - 1],
				get_line_color_region(context, i, i - 1));
		if (pos.y > 0 && (!should_cull_line(context->nacho,
					context->proj_grid[i],
					context->proj_grid[i - context->grid.width])))
			line_put(context, context->proj_grid[i],
				context->proj_grid[i - context->grid.width],
				get_line_color_region(context, i, i - context->grid.width));
		i++;
	}
}

static void	draw_grid_rightward(t_context *context)
{
	int		i;
	t_vec3	pos;

	i = context->grid.size - context->grid.width;
	while (1)
	{
		pos = get_cell_at_i(&context->grid, i);
		context->proj_grid[i] = project_iso(&context->cam, pos);
		if (pos.x > 0 && (!should_cull_line(context->nacho,
					context->proj_grid[i], context->proj_grid[i - 1])))
			line_put(context, context->proj_grid[i], context->proj_grid[i - 1],
				get_line_color_region(context, i, i - 1));
		if (pos.y + 1 < context->grid.height && (!should_cull_line(
					context->nacho, context->proj_grid[i],
					context->proj_grid[i + context->grid.width])))
			line_put(context, context->proj_grid[i],
				context->proj_grid[i + context->grid.width],
				get_line_color_region(context, i, i + context->grid.width));
		if (i + 1 == context->grid.width)
			break ;
		if (pos.y == 0)
			i += context->grid.size + 1;
		i -= context->grid.width;
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
		if (pos.x + 1 < context->grid.width && (!should_cull_line(
					context->nacho, context->proj_grid[i],
					context->proj_grid[i + 1])))
			line_put(context, context->proj_grid[i], context->proj_grid[i + 1],
				get_line_color_region(context, i, i + 1));
		if (pos.y + 1 < context->grid.height && (!should_cull_line(
					context->nacho, context->proj_grid[i],
					context->proj_grid[i + context->grid.width])))
			line_put(context, context->proj_grid[i],
				context->proj_grid[i + context->grid.width],
				get_line_color_region(context, i, i + context->grid.width));
		i--;
	}
}

static void	draw_grid_leftward(t_context *context)
{
	int		i;
	t_vec3	pos;

	i = context->grid.width - 1;
	while (1)
	{
		pos = get_cell_at_i(&context->grid, i);
		context->proj_grid[i] = project_iso(&context->cam, pos);
		if (pos.x + 1 < context->grid.width && (!should_cull_line(
					context->nacho, context->proj_grid[i],
					context->proj_grid[i + 1])))
			line_put(context, context->proj_grid[i], context->proj_grid[i + 1],
				get_line_color_region(context, i, i + 1));
		if (pos.y > 0 && (!should_cull_line(
					context->nacho, context->proj_grid[i],
					context->proj_grid[i - context->grid.width])))
			line_put(context, context->proj_grid[i],
				context->proj_grid[i - context->grid.width],
				get_line_color_region(context, i, i - context->grid.width));
		if (i == context->grid.size - context->grid.width)
			break ;
		if (pos.y + 1 == context->grid.height)
			i -= context->grid.size + 1;
		i += context->grid.width;
	}
}

void	draw_grid(t_context *context)
{
	if (context->line_size == 1)
	{
		if (context->cam.rotation.x < M_PI_2)
			draw_grid_forward(context);
		else if (context->cam.rotation.x >= M_PI_2
			&& context->cam.rotation.x < M_PI)
			draw_grid_rightward(context);
		else if (context->cam.rotation.x >= M_PI
			&& context->cam.rotation.x < M_PI + M_PI_2)
			draw_grid_backward(context);
		else
			draw_grid_leftward(context);
	}
 	else
	{
		if (context->cam.rotation.x < M_PI_2)
			draw_grid_forward(context);
		else if (context->cam.rotation.x >= M_PI_2
			&& context->cam.rotation.x < M_PI)
			draw_grid_rightward(context);
		else if (context->cam.rotation.x >= M_PI
			&& context->cam.rotation.x < M_PI + M_PI_2)
			draw_grid_backward(context);
		else
			draw_grid_leftward(context);
	}
}
