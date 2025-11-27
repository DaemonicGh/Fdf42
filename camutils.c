/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:21:09 by rprieur           #+#    #+#             */
/*   Updated: 2025/11/14 14:21:12 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_cam(t_context *context, t_vec2 disp)
{
	context->cam.focus.x += disp.x;
	context->cam.focus.y += disp.y;
	if (AUTO_CAMERA_HEIGHT)
		context->cam.focus.z = get_cell(&context->grid,
				context->cam.focus.x, context->cam.focus.y);
}

void	handle_camera_movement(t_context *context)
{
	const t_vec2	axis[8] = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1},
	{0, 1}, {1, 1}, {1, 0}, {1, -1}};
	float			radangle;
	int				quadrant;

	radangle = fmodf(context->cam.hrot.angle + 45, 2 * M_PI);
	if (radangle < 0)
		radangle += 2 * M_PI;
	quadrant = (int)roundf(radangle / M_PI_4) & 7;
	if (context->nacho->inputs.key[26] || context->nacho->inputs.key[82])
		move_cam(context, axis[quadrant]);
	else if (context->nacho->inputs.key[4] || context->nacho->inputs.key[80])
		move_cam(context, axis[(quadrant + 2) & 7]);
	else if (context->nacho->inputs.key[22] || context->nacho->inputs.key[81])
		move_cam(context, axis[(quadrant + 4) & 7]);
	else if (context->nacho->inputs.key[7] || context->nacho->inputs.key[79])
		move_cam(context, axis[(quadrant - 2) & 7]);
}

void	update_rotation(t_context *context)
{
	if (!context->nacho->inputs.record_mouse)
		return ;
	context->cam.hrot.angle += (context->nacho->viewport.width / 2
			- context->nacho->inputs.mouse.x) * MOUSE_SENSITIVITY;
	if (context->cam.hrot.angle < 0)
		context->cam.hrot.angle += 2 * M_PI;
	else if (context->cam.hrot.angle > 2 * M_PI)
		context->cam.hrot.angle -= 2 * M_PI;
	context->cam.hrot.cos = cos(context->cam.hrot.angle);
	context->cam.hrot.sin = sin(context->cam.hrot.angle);
	nacho_warp_mouse(context->nacho, context->nacho->viewport.width / 2,
		context->nacho->viewport.height / 2);
}
