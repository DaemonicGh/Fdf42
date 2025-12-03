/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heightmap_inputs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:16:01 by rprieur           #+#    #+#             */
/*   Updated: 2025/11/27 14:16:03 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

static void	handle_heightmap_mouse(t_context *context)
{
	if (context->nacho->inputs.btn[NACHO_BUTTON_MIDDLE])
	{
		context->heightmap.disp.x += (context->nacho->inputs.prev_mouse.x
				- context->nacho->inputs.mouse.x) / context->heightmap.zoom;
		context->heightmap.disp.y += (context->nacho->inputs.prev_mouse.y
				- context->nacho->inputs.mouse.y) / context->heightmap.zoom;
	}
	if (context->nacho->inputs.btnp[NACHO_BUTTON_LEFT])
	{
		update_point(context, vec2_new(context->heightmap.focus.x,
				context->heightmap.focus.y), 1);
	}
	else if (context->nacho->inputs.btnp[NACHO_BUTTON_RIGHT])
	{
		update_point(context, vec2_new(context->heightmap.focus.x,
				context->heightmap.focus.y), -1);
	}
}

void	handle_heightmap_movement(t_context *context)
{
	if (context->nacho->inputs.key[NACHO_KEY_W]
		|| context->nacho->inputs.key[NACHO_KEY_UP])
		context->heightmap.disp.y -= HEIGHTMAP_DISP_SPEED
			/ context->heightmap.zoom;
	if (context->nacho->inputs.key[NACHO_KEY_A]
		|| context->nacho->inputs.key[NACHO_KEY_LEFT])
		context->heightmap.disp.x -= HEIGHTMAP_DISP_SPEED
			/ context->heightmap.zoom;
	if (context->nacho->inputs.key[NACHO_KEY_S]
		|| context->nacho->inputs.key[NACHO_KEY_DOWN])
		context->heightmap.disp.y += HEIGHTMAP_DISP_SPEED
			/ context->heightmap.zoom;
	if (context->nacho->inputs.key[NACHO_KEY_D]
		|| context->nacho->inputs.key[NACHO_KEY_RIGHT])
		context->heightmap.disp.x += HEIGHTMAP_DISP_SPEED
			/ context->heightmap.zoom;
 	handle_heightmap_mouse(context);
}

void	handle_heightmap_scroll(t_context *context)
{
	if (context->nacho->inputs.key[NACHO_KEY_LALT])
	{
		update_point(context, vec2_new(context->heightmap.focus.x,
				context->heightmap.focus.y),
			context->nacho->inputs.mouse_wheel);
	}
	else if (context->nacho->inputs.key[NACHO_KEY_LCTRL])
	{
		update_point(context, vec2_new(context->heightmap.focus.x,
				context->heightmap.focus.y),
			context->nacho->inputs.mouse_wheel * 10);
	}
	else
	{
		if (context->nacho->inputs.mouse_wheel > 0)
			context->heightmap.zoom = fmin(context->heightmap.zoom
					* CAMERA_ZOOM_AMPLIFIER, 100);
		if (context->nacho->inputs.mouse_wheel < 0)
			context->heightmap.zoom = fmax(context->heightmap.zoom
					/ CAMERA_ZOOM_AMPLIFIER, 0.1);
	}
}
