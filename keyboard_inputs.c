/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:40:23 by rprieur           #+#    #+#             */
/*   Updated: 2025/12/03 14:40:25 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "nacho/includes/nacho.h"

static void	iso_config_key_inputs(t_context *context)
{
	if (context->nacho->inputs.keyp[NACHO_KEY_C])
	{
		context->colorize_grid = !context->colorize_grid;
		if (context->colorize_grid)
			color_grid(&context->grid,
				color(LOW_LINE_COLOR), color(HIGH_LINE_COLOR));
		else
			color_grid(&context->grid,
				color(BASE_LINE_COLOR), color(BASE_LINE_COLOR));
	}
	if (context->nacho->inputs.keyp[NACHO_KEY_T])
		context->line_size = min(context->line_size + 1, MAX_LINE_SIZE);
	if (context->nacho->inputs.keyp[NACHO_KEY_G])
		context->line_size = max(context->line_size - 1, MIN_LINE_SIZE);
	if (context->nacho->inputs.key[NACHO_KEY_R])
		context->cam.height_mod *= 1
			+ context->nacho->delta_time * HEIGHT_MOD_AMPLIFIER;
	if (context->nacho->inputs.key[NACHO_KEY_F])
		context->cam.height_mod /= 1
			+ context->nacho->delta_time * HEIGHT_MOD_AMPLIFIER;
}

static void	iso_key_inputs(t_context *context)
{
	if (context->nacho->inputs.keyp[NACHO_KEY_SPACE])
	{
		context->record_mouse
			= !context->record_mouse;
		nacho_warp_mouse(context->nacho, context->nacho->viewport.width / 2,
			context->nacho->viewport.height / 2);
		if (context->record_mouse)
			mlx_mouse_hide(context->nacho->mlx);
		else
			mlx_mouse_show(context->nacho->mlx);
	}
	handle_camera_movement(context);
	iso_config_key_inputs(context);
}

void	handle_key_inputs(t_context *context)
{
	if (context->nacho->inputs.keyp[NACHO_KEY_F11])
	{
		if (context->nacho->window.is_fullscreen)
		{
			context->nacho->window.is_fullscreen = false;
			context->nacho->window.width = WINDOW_WIDTH;
			context->nacho->window.height = WINDOW_HEIGHT;
		}
		else
			context->nacho->window.is_fullscreen = true;
		nacho_refresh_window(context->nacho);
	}
	if (context->nacho->inputs.keyp[NACHO_KEY_F10])
		nacho_center_window(context->nacho);
	if (context->nacho->inputs.keyp[NACHO_KEY_ESCAPE])
		context->nacho->inputs.should_exit = true;
	if (context->nacho->inputs.key[NACHO_KEY_ENTER])
		save_grid(context);
	if (context->nacho->inputs.keyp[NACHO_KEY_TAB])
		toggle_heightmap(context);
	if (context->heightmap_mode)
		handle_heightmap_movement(context);
	else
		iso_key_inputs(context);
}
