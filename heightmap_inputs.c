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

#include "fdf.h"

void	handle_heightmap_movement(t_context *context)
{
	if (context->nacho->inputs.key[NACHO_KEY_W]
		|| context->nacho->inputs.key[NACHO_KEY_UP])
		context->heightmap.dispy -= HEIGHTMAP_DISP_SPEED
			/ context->heightmap.zoom;
	if (context->nacho->inputs.key[NACHO_KEY_A]
		|| context->nacho->inputs.key[NACHO_KEY_LEFT])
		context->heightmap.dispx -= HEIGHTMAP_DISP_SPEED
			/ context->heightmap.zoom;
	if (context->nacho->inputs.key[NACHO_KEY_S]
		|| context->nacho->inputs.key[NACHO_KEY_DOWN])
		context->heightmap.dispy += HEIGHTMAP_DISP_SPEED
			/ context->heightmap.zoom;
	if (context->nacho->inputs.key[NACHO_KEY_D]
		|| context->nacho->inputs.key[NACHO_KEY_RIGHT])
		context->heightmap.dispx += HEIGHTMAP_DISP_SPEED
			/ context->heightmap.zoom;
	if (context->nacho->inputs.btn[NACHO_BUTTON_LEFT])
	{
		context->heightmap.dispx += (context->nacho->inputs.prev_mouse.x
				- context->nacho->inputs.mouse.x) / context->heightmap.zoom;
		context->heightmap.dispy += (context->nacho->inputs.prev_mouse.y
				- context->nacho->inputs.mouse.y) / context->heightmap.zoom;
	}
}

void	handle_heightmap_zoom(t_context *context)
{
	if (context->nacho->inputs.mouse_wheel > 0)
		context->heightmap.zoom = fmin(context->heightmap.zoom
				* CAMERA_ZOOM_AMPLIFIER, 100);
	if (context->nacho->inputs.mouse_wheel < 0)
		context->heightmap.zoom = fmax(context->heightmap.zoom
				/ CAMERA_ZOOM_AMPLIFIER, 0.1);
}
