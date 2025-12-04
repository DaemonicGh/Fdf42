/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_overlay.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:47:00 by rprieur           #+#    #+#             */
/*   Updated: 2025/11/17 16:47:02 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	draw_monitoring_bg(t_context *context)
{
	mlx_color	*pixels;
	int			i;

	i = 0;
	pixels = malloc(sizeof(mlx_color) * context->nacho->viewport.width * 12);
	if (!pixels)
		return ;
	while (i < context->nacho->viewport.width * 12)
		pixels[i++] = color(MONITORING_BG_COLOR);
	mlx_pixel_put_region(context->nacho->mlx, context->nacho->viewport.win,
		0, 0, context->nacho->viewport.width, 12, pixels);
	if (!context->record_mouse || context->heightmap_mode
		|| context->nacho->inputs.last_key == NACHO_KEY_ENTER)
		mlx_pixel_put_region(context->nacho->mlx, context->nacho->viewport.win,
			0, context->nacho->viewport.height - 12,
			context->nacho->viewport.width, 12, pixels);
	free(pixels);
}

void	draw_monitor_save_str(t_context *context)
{
	if (context->is_save_success)
		mlx_string_put(context->nacho->mlx, context->nacho->viewport.win,
			context->nacho->viewport.width / 2 - 132,
			context->nacho->viewport.height - 2, color(TEXT_COLOR),
			"MAP SAVED SUCCESSFULLY");
	else
		mlx_string_put(context->nacho->mlx, context->nacho->viewport.win,
			context->nacho->viewport.width / 2 - 120,
			context->nacho->viewport.height - 2, color(TEXT_COLOR_ERROR),
			"ERROR DURING SAVING!");
}
