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

#include "includes/fdf.h"

static void	move_cam(t_context *context, t_vec2f disp, int speed)
{
	context->cam.focus.x += disp.x * context->nacho->deltatime * speed;
	context->cam.focus.y += disp.y * context->nacho->deltatime * speed;
	if (AUTO_CAMERA_HEIGHT)
		context->cam.focus.z = *get_cell(&context->grid,
				roundf(context->cam.focus.x), roundf(context->cam.focus.y));
}

void	handle_camera_movement(t_context *context)
{
	const int	speed = context->nacho->inputs.key[NACHO_KEY_LSHIFT]
		* CAMERA_SPEED_ADD + CAMERA_SPEED;
	const float	angle = context->cam.rotation.x;

	if (context->nacho->inputs.key[NACHO_KEY_W]
		|| context->nacho->inputs.key[NACHO_KEY_UP])
		move_cam(context, vec2f_new(-sinf(angle), -cosf(angle)), speed);
	if (context->nacho->inputs.key[NACHO_KEY_A]
		|| context->nacho->inputs.key[NACHO_KEY_LEFT])
		move_cam(context, vec2f_new(-cosf(angle), sinf(angle)), speed);
	if (context->nacho->inputs.key[NACHO_KEY_S]
		|| context->nacho->inputs.key[NACHO_KEY_DOWN])
		move_cam(context, vec2f_new(sinf(angle), cosf(angle)), speed);
	if (context->nacho->inputs.key[NACHO_KEY_D]
		|| context->nacho->inputs.key[NACHO_KEY_RIGHT])
		move_cam(context, vec2f_new(cosf(angle), -sinf(angle)), speed);
}

void	update_rotation(t_context *context)
{
	if (!context->nacho->inputs.record_mouse)
		return ;
	if (!context->nacho->inputs.btn[NACHO_BUTTON_LEFT])
	{
		context->cam.rotation.y += (context->nacho->viewport.height / 2
				- context->nacho->inputs.mouse.y) * MOUSE_SENSITIVITY;
		context->cam.rotation.y = clamp(context->cam.rotation.y, 0, M_PI);
	}
	if (!context->nacho->inputs.btn[NACHO_BUTTON_RIGHT])
	{
		context->cam.rotation.x += (context->nacho->viewport.width / 2
				- context->nacho->inputs.mouse.x) * MOUSE_SENSITIVITY;
		context->cam.rotation.x = loop(context->cam.rotation.x, 0, M_PI * 2);
	}
	nacho_warp_mouse(context->nacho, context->nacho->viewport.width / 2,
		context->nacho->viewport.height / 2);
}
