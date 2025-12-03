/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:02:08 by rprieur           #+#    #+#             */
/*   Updated: 2025/12/03 14:02:09 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	color_grid(t_grid *grid, mlx_color col1, mlx_color col2)
{
	int	i;

	i = 0;
	if (col1.rgba == col2.rgba)
	{
		while (i < grid->size)
		{
			if (!grid->colors[i].is_override)
				grid->colors[i++].color = col1;
		}
	}
	else
	{
		while (i < grid->size)
		{
			if (!grid->colors[i].is_override)
				grid->colors[i].color = color_lerp(col1, col2,
						normalize_z(grid, grid->grid[i]));
			i++;
		}
	}
}

void	update_grid_limits(t_grid *grid)
{
	int	i;

	i = 0;
	grid->min = INT_MAX;
	grid->max = INT_MIN;
	while (i < grid->size)
	{
		if (grid->grid[i] > grid->max)
			grid->max = grid->grid[i];
		if (grid->grid[i] < grid->min)
			grid->min = grid->grid[i];
		i++;
	}
}

void	update_point(t_context *context, t_vec2 point, int increment)
{
	int	*cell;

	cell = get_cell_p(&context->grid, point.x, point.y);
 	if (!cell)
   		return ;
	*cell += increment;
	update_grid_limits(&context->grid);
	update_heightmap_colors(context, context->heightmap.img);
	if (roundf(context->cam.focus.x) == point.x
		&& roundf(context->cam.focus.y) == point.y)
		context->cam.focus.z = *cell;
	if (context->colorize_grid)
		color_grid(&context->grid,
			color(LOW_LINE_COLOR), color(HIGH_LINE_COLOR));
}

void	save_grid(t_context *context)
{
	const int	fd = open(context->file, O_WRONLY);

	if (fd < 0)
	{
   		write(2, "ERROR: Failed to open file when saving!", 39);
  		return ;
	}
}
