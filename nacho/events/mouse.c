/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:51:18 by rprieur           #+#    #+#             */
/*   Updated: 2025/11/27 11:51:19 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nacho.h"

void	mouse_down_hook(int button, void *param)
{
	t_ncontext	*nacho;

	if (button < 0 || button > NACHO_BUTTON_SCANCODE_LENGTH)
		return ;
	nacho = param;
	if (nacho->inputs.btn[button])
		return ;
	nacho->inputs.btn[button] = true;
	nacho->inputs.btnp[button] = true;
}

void	mouse_up_hook(int button, void *param)
{
	t_ncontext	*nacho;

	if (button < 0 || button > NACHO_BUTTON_SCANCODE_LENGTH)
		return ;
	nacho = param;
	nacho->inputs.btn[button] = false;
	nacho->inputs.btnr[button] = true;
}

void	mouse_wheel_hook(int button, void *param)
{
	t_ncontext	*nacho;

	if (button < 0 || button > 2)
		return ;
	nacho = param;
	if (button == 1)
		nacho->inputs.mouse_wheel = NACHO_SCROLL_UP;
	else if (button == 2)
		nacho->inputs.mouse_wheel = NACHO_SCROLL_DOWN;
}
