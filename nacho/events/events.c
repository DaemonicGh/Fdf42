/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:51:43 by rprieur           #+#    #+#             */
/*   Updated: 2025/11/27 11:51:45 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../nacho.h"

void	nacho_flush_inputs(t_ncontext *nacho)
{
	int	i;

	i = 0;
	while (i < NACHO_KEY_SCANCODE_LENGTH)
	{
		nacho->inputs.keyp[i] = false;
		nacho->inputs.keyr[i++] = false;
	}
	i = 0;
	while (i < NACHO_BUTTON_SCANCODE_LENGTH)
	{
		nacho->inputs.btnp[i] = false;
		nacho->inputs.btnr[i++] = false;
	}
	i = 0;
	while (i < NACHO_WINDOW_SCANCODE_LENGTH)
		nacho->inputs.window[i++] = false;
	nacho->inputs.mouse_wheel = 0;
}

void	nacho_start_events(t_ncontext *nacho)
{
	mlx_on_event(nacho->mlx, nacho->window.win,
		MLX_KEYDOWN, key_down_hook, nacho);
	mlx_on_event(nacho->mlx, nacho->window.win,
		MLX_KEYUP, key_up_hook, nacho);
	mlx_on_event(nacho->mlx, nacho->window.win,
		MLX_MOUSEDOWN, mouse_down_hook, nacho);
	mlx_on_event(nacho->mlx, nacho->window.win,
		MLX_MOUSEUP, mouse_up_hook, nacho);
	mlx_on_event(nacho->mlx, nacho->window.win,
		MLX_MOUSEWHEEL, mouse_wheel_hook, nacho);
	mlx_on_event(nacho->mlx, nacho->window.win,
		MLX_WINDOW_EVENT, window_hook, nacho);
}
