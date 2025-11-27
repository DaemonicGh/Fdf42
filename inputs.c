/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:29:32 by rprieur           #+#    #+#             */
/*   Updated: 2025/11/25 13:29:33 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "nacho/nacho.h"

static void	handle_key_inputs(t_context *context)
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
		exit_mlx(context);
	if (context->nacho->inputs.keyp[NACHO_KEY_TAB])
		toggle_heightmap(context);
	if (context->heightmap_mode)
		handle_heightmap_movement(context);
	else if (context->nacho->inputs.keyp[NACHO_KEY_SPACE])
	{
		context->nacho->inputs.record_mouse
			= !context->nacho->inputs.record_mouse;
		nacho_warp_mouse(context->nacho, context->nacho->viewport.width / 2,
			context->nacho->viewport.height / 2);
	}
	else if (context->nacho->inputs.key[NACHO_KEY_LSHIFT]
		|| !(context->nacho->frame_elapsed % 3))
		handle_camera_movement(context);
}

static void	handle_mouse_inputs(t_context *context)
{
	if (context->heightmap_mode)
		handle_heightmap_zoom(context);
	else if (context->nacho->inputs.key[NACHO_KEY_LALT])
	{
		if (context->nacho->inputs.mouse_wheel > 0)
			context->cam.height_mod *= HEIGHT_MOD_AMPLIFIER;
		if (context->nacho->inputs.mouse_wheel < 0)
			context->cam.height_mod /= HEIGHT_MOD_AMPLIFIER;
	}
	else
	{
		if (context->nacho->inputs.mouse_wheel > 0)
			context->cam.zoom = fmin(context->cam.zoom
					* CAMERA_ZOOM_AMPLIFIER, 100);
		if (context->nacho->inputs.mouse_wheel < 0)
			context->cam.zoom = fmax(context->cam.zoom
					/ CAMERA_ZOOM_AMPLIFIER, 0.1);
	}
}

void	update_inputs(t_context *context)
{
	handle_key_inputs(context);
	handle_mouse_inputs(context);
}
