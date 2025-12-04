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
	context->cam.focus.x += disp.x * context->nacho->delta_time * speed;
	context->cam.focus.y += disp.y * context->nacho->delta_time * speed;
	if (AUTO_CAMERA_HEIGHT)
		context->cam.focus.z = get_cell(&context->grid,
				roundf(context->cam.focus.x), roundf(context->cam.focus.y));
}

void	handle_camera_movement(t_context *context)
{
	const int	speed = context->nacho->inputs.key[NACHO_KEY_LSHIFT]
		* CAMERA_SPEED_ADD + CAMERA_SPEED;

	if (context->nacho->inputs.key[NACHO_KEY_W]
		|| context->nacho->inputs.key[NACHO_KEY_UP])
		move_cam(context, vec2f_new(-context->cam.rotation_sin.x,
				-context->cam.rotation_cos.x), speed);
	if (context->nacho->inputs.key[NACHO_KEY_A]
		|| context->nacho->inputs.key[NACHO_KEY_LEFT])
		move_cam(context, vec2f_new(-context->cam.rotation_cos.x,
				context->cam.rotation_sin.x), speed);
	if (context->nacho->inputs.key[NACHO_KEY_S]
		|| context->nacho->inputs.key[NACHO_KEY_DOWN])
		move_cam(context, vec2f_new(context->cam.rotation_sin.x,
				context->cam.rotation_cos.x), speed);
	if (context->nacho->inputs.key[NACHO_KEY_D]
		|| context->nacho->inputs.key[NACHO_KEY_RIGHT])
		move_cam(context, vec2f_new(context->cam.rotation_cos.x,
				-context->cam.rotation_sin.x), speed);
}

void	set_rotation_x(t_cam *cam, float x)
{
	cam->rotation.x = x;
	cam->rotation_cos.x = cosf(x);
	cam->rotation_sin.x = sinf(x);
}

void	set_rotation_y(t_cam *cam, float y)
{
	cam->rotation.y = y;
	cam->rotation_cos.y = cosf(y);
	cam->rotation_sin.y = sinf(y);
}

void	update_rotation(t_context *context)
{
	if (!context->record_mouse)
		return ;
	if (!context->nacho->inputs.btn[NACHO_BUTTON_LEFT])
	{
		set_rotation_y(&context->cam, clamp(context->cam.rotation.y
				+ (context->nacho->viewport.height / 2
					- context->nacho->inputs.mouse.y)
				* MOUSE_SENSITIVITY, 0, M_PI));
	}
	if (!context->nacho->inputs.btn[NACHO_BUTTON_RIGHT])
	{
		set_rotation_x(&context->cam, loop(context->cam.rotation.x
				+ (context->nacho->viewport.width / 2
					- context->nacho->inputs.mouse.x)
				* MOUSE_SENSITIVITY, 0, M_PI * 2));
	}
	nacho_warp_mouse(context->nacho, context->nacho->viewport.width / 2,
		context->nacho->viewport.height / 2);
}
