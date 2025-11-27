/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:20:24 by rprieur           #+#    #+#             */
/*   Updated: 2025/11/25 18:20:26 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nacho.h"

static void	flush_inputs(t_ncontext *nacho)
{
	int	i;

	mlx_mouse_get_pos(nacho->mlx,
		&nacho->inputs.mouse.x, &nacho->inputs.mouse.y);
	nacho->inputs.prev_mouse = nacho->inputs.mouse;
	i = 0;
	while (i < NACHO_KEY_SCANCODE_LENGTH)
		nacho->inputs.key[i++] = false;
	i = 0;
	while (i < NACHO_BUTTON_SCANCODE_LENGTH)
		nacho->inputs.btn[i++] = false;
	nacho_flush_inputs(nacho);
	nacho->inputs.record_mouse = true;
	nacho->inputs.should_exit = false;
}

t_ncontext	*nacho_init(t_vec2 win_size, char *win_title, int win_mode)
{
	t_ncontext	*nacho;

	nacho = malloc(sizeof(t_ncontext));
	nacho->mlx = mlx_init();
	nacho->window = nacho_make_window(nacho, win_size, win_title, win_mode);
	nacho->viewport = nacho_make_window_target(nacho,
			nacho_make_image(nacho, win_size.x, win_size.y));
	flush_inputs(nacho);
	nacho_start_events(nacho);
	nacho->frame_elapsed = 0;
	return (nacho);
}
