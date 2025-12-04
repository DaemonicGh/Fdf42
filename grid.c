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
#include <fcntl.h>

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

static void	save_grid_line(t_context *context, int fd, int i, int *j)
{
	const int	kmax = max(nbrlen_base(context->grid.min, 10),
			nbrlen_base(context->grid.max, 10)) + 1;
	int			k;

	if (*j == context->grid.width)
	{
		write(fd, "\n", 1);
		*j = 0;
	}
	k = kmax;
	while (k-- > nbrlen_base(context->grid.grid[i], 10))
		write(fd, " ", 1);
	ft_putnbr_fd(fd, context->grid.grid[i]);
	if (context->grid.colors[i].is_override)
	{
		write(fd, ",", 1);
		k = 6;
		while (k-- > nbrlen_base(context->grid.colors[i].color.rgba >> 8,
				16))
			write(fd, " ", 1);
		write(fd, "0x", 2);
		ft_putuhex_fd(fd, context->grid.colors[i].color.rgba >> 8);
	}
}

void	save_grid(t_context *context)
{
	const int	fd = open(context->file, O_WRONLY | O_TRUNC);
	int			i;
	int			j;

	if (fd < 0)
	{
		write(2, "ERROR: Failed to open file when saving!\n", 39);
		context->is_save_success = false;
		return ;
	}
	i = 0;
	j = 0;
	while (i < context->grid.size)
	{
		save_grid_line(context, fd, i, &j);
		i++;
		j++;
	}
	write(fd, "\n", 1);
	close(fd);
	context->is_save_success = true;
}
