/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gridutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:48:05 by rprieur           #+#    #+#             */
/*   Updated: 2025/11/07 15:48:06 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_cell(t_grid *grid, int x, int y)
{
	if (x < 0 || x >= grid->width || y < 0 || y >= grid->height)
		return (0);
	return (grid->grid[y * grid->width + x]);
}

t_vec3	get_cell_at_i(t_grid *grid, int i)
{
	return (vec3_new(i % grid->width, i / grid->width, grid->grid[i]));
}

float	normalize_z(t_grid *grid, float z)
{
	return ((z - grid->min) / (grid->max - grid->min));
}

mlx_color	normalize_z_color(t_grid *grid, float z)
{
	z = normalize_z(grid, z) * 255;
	return ((mlx_color){.r = z, .g = z, .b = z, .a = 0xFF});
}
