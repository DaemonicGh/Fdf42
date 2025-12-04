/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:34:44 by rprieur           #+#    #+#             */
/*   Updated: 2025/11/06 17:34:45 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

static int	get_grid_width(const char *str)
{
	int	i;
	int	prev;
	int	width;

	i = 0;
	prev = 1;
	width = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] == ',')
			prev = 1;
		else if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		{
			if (!prev)
				width++;
			prev = 1;
		}
		else
			prev = 0;
		i++;
	}
	return (width + !prev);
}

static void	get_grid_size(const char *str, t_grid *grid)
{
	int	i;

	i = 0;
	grid->height = 0;
	while (str[i])
	{
		if (str[i++] == '\n')
			grid->height++;
	}
	grid->width = get_grid_width(str);
	grid->size = grid->width * grid->height;
}

static void	handle_colors(const char *str, t_grid *grid, int *i, int *j)
{
	if (str[*i] == ',')
	{
		grid->colors[*j] = (t_gridcolor){color(ahextocol(str + ++(*i))), true};
		while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
			(*i)++;
	}
	else
		grid->colors[*j] = (t_gridcolor){color(0x0), false};
}

static void	fill_grid(const char *str, t_grid *grid)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		if (!str[i])
			return ;
		grid->grid[j] = ft_atoi(str + i);
		grid->min = min(grid->grid[j], grid->min);
		grid->max = max(grid->grid[j], grid->max);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		handle_colors(str, grid, &i, &j);
		j++;
		while (str[i] && str[i] != ' ' && (str[i] < 9 || str[i] > 13))
			i++;
	}
}

t_grid	get_grid(char *file)
{
	const char	*str = read_all(open(file, O_RDONLY));
	t_grid		grid;

	if (!str)
		put_exit(1, "ERROR: Couldn't parse given file!");
	get_grid_size(str, &grid);
	grid.grid = malloc(sizeof(int) * grid.size);
	grid.colors = malloc(sizeof(t_gridcolor) * grid.size);
	if (!grid.grid && !grid.colors)
		return (grid);
	grid.min = INT_MAX;
	grid.max = INT_MIN;
	fill_grid(str, &grid);
	color_grid(&grid, color(LOW_LINE_COLOR), color(HIGH_LINE_COLOR));
	free((char *)str);
	return (grid);
}
