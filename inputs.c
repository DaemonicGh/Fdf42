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

#include "includes/fdf.h"

static void	handle_scroll(t_context *context)
{
	if (context->nacho->inputs.key[NACHO_KEY_LALT])
	{
		update_point(context, vec2_new(roundf(context->cam.focus.x),
				roundf(context->cam.focus.y)),
			context->nacho->inputs.mouse_wheel);
	}
	else if (context->nacho->inputs.key[NACHO_KEY_LCTRL])
	{
		update_point(context, vec2_new(roundf(context->cam.focus.x),
				roundf(context->cam.focus.y)),
			context->nacho->inputs.mouse_wheel * 10);
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

static void	handle_mouse_inputs(t_context *context)
{
	if (context->heightmap_mode)
	{
		handle_heightmap_scroll(context);
		return ;
	}
	if (context->nacho->inputs.btn[NACHO_BUTTON_LEFT])
		context->cam.rotation.y = roundf(clamp(context->cam.rotation.y,
					0, M_PI) / M_PI_4) * M_PI_4;
	if (context->nacho->inputs.btn[NACHO_BUTTON_RIGHT])
		context->cam.rotation.x = roundf(loop(context->cam.rotation.x,
					0, M_PI * 2) / M_PI_4) * M_PI_4;
	if (context->nacho->inputs.btn[NACHO_BUTTON_MIDDLE])
	{
		context->cam.rotation.x = roundf(loop(context->cam.rotation.x + M_PI_4,
					0, M_PI * 2) / M_PI_2) * M_PI_2 - M_PI_4;
		if (context->cam.rotation.y >= M_PI_2)
			context->cam.rotation.y = M_PI_2 + 0.61548;
		else
			context->cam.rotation.y = M_PI_2 - 0.61548;
	}
	handle_scroll(context);
}

void	update_inputs(t_context *context)
{
	update_rotation(context);
	handle_key_inputs(context);
	handle_mouse_inputs(context);
}
