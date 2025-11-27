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

#include "fdf.h"
#include "nacho/nacho.h"

static void	heightmap_update(t_context *context)
{
	char	str[80];

	mlx_clear_window(context->nacho->mlx, context->nacho->viewport.win,
		color(HM_BG_COLOR));
	update_heightmap(context);
	mlx_put_transformed_image_to_window(context->nacho->mlx,
		context->nacho->viewport.win, context->heightmap.img,
		context->nacho->viewport.width / 2 - ((float)context->grid.width
			/ 2 + context->heightmap.dispx) * context->heightmap.zoom,
		context->nacho->viewport.height / 2
		- ((float)context->grid.height / 2 + context->heightmap.dispy)
		* context->heightmap.zoom,
		context->heightmap.zoom, context->heightmap.zoom, 0);
	draw_monitoring_bg(context);
	make_monitoring_str_hm(context, str);
	mlx_string_put(context->nacho->mlx, context->nacho->viewport.win, 2, 9,
		color(TEXT_COLOR), str);
	mlx_string_put(context->nacho->mlx, context->nacho->viewport.win,
		context->nacho->viewport.width / 2 - 80,
		context->nacho->viewport.height - 2, color(TEXT_COLOR),
		"HEIGHTMAP MODE [TAB]");
}

static void	isometric_update(t_context *context)
{
	char	str[80];

	mlx_clear_window(context->nacho->mlx, context->nacho->viewport.win,
		color(ISO_BG_COLOR));
	update_rotation(context);
	draw_grid(context);
	mlx_put_image_to_window(context->nacho->mlx, context->nacho->viewport.win,
		context->crosshair, context->nacho->viewport.width / 2 - 7,
		context->nacho->viewport.height / 2 - 7);
	draw_monitoring_bg(context);
	make_monitoring_str_iso(context, str);
	mlx_string_put(context->nacho->mlx, context->nacho->viewport.win, 2, 9,
		color(TEXT_COLOR), str);
	if (!context->nacho->inputs.record_mouse)
		mlx_string_put(context->nacho->mlx, context->nacho->viewport.win,
			context->nacho->viewport.width / 2 - 120,
			context->nacho->viewport.height - 2, color(TEXT_COLOR),
			"MOUSE RECORDING PAUSED [SPACE]");
}

void	update(void *param)
{
	t_context		*context;

	context = param;
	if (context->nacho->inputs.should_exit)
		exit_mlx(context);
	update_inputs(context);
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
	if (!grid.grid)
		exit(1);
	context = init_window(&grid);
	nacho_run(context.nacho, update, &context);
	exit_mlx(&context);
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
