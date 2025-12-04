/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:12:15 by rprieur           #+#    #+#             */
/*   Updated: 2025/11/25 17:12:16 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/nacho.h"

void	nacho_start_frame(t_ncontext *nacho)
{
	nacho->inputs.prev_mouse.x = nacho->inputs.mouse.x;
	nacho->inputs.prev_mouse.y = nacho->inputs.mouse.y;
	mlx_mouse_get_pos(nacho->mlx,
		&nacho->inputs.mouse.x, &nacho->inputs.mouse.y);
	nacho->inputs.mouse.x *= (float)nacho->viewport.width
		/ nacho->window.width;
	nacho->inputs.mouse.y *= (float)nacho->viewport.height
		/ nacho->window.height;
	mlx_get_window_size(nacho->mlx, nacho->window.win,
		&nacho->window.width, &nacho->window.height);
	mlx_clear_window(nacho->mlx, nacho->window.win, (mlx_color){.rgba = 0x0});
}

void	nacho_end_frame(t_ncontext *nacho)
{
	nacho_refresh_window(nacho);
	nacho_flush_inputs(nacho);
	nacho->frame_elapsed++;
}

static void	nacho_loop(void *rawcontext)
{
	static struct timeval	start;
	struct timeval			end;
	t__nloopcontext			*context;

	context = rawcontext;
	gettimeofday(&end, NULL);
	context->nacho->delta_time = (float)(end.tv_sec - start.tv_sec)
		+ (float)(end.tv_usec - start.tv_usec) / 1000000;
	gettimeofday(&start, NULL);
	nacho_start_frame(context->nacho);
	context->update(context->args);
	nacho_end_frame(context->nacho);
}

void	nacho_run(t_ncontext *nacho,
		void (*update)(void *args), void *args)
{
	t__nloopcontext	context;

	context.nacho = nacho;
	context.update = update;
	context.args = args;
	mlx_add_loop_hook(nacho->mlx, nacho_loop, &context);
	mlx_loop(nacho->mlx);
}
