/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nacho.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:17:20 by rprieur           #+#    #+#             */
/*   Updated: 2025/11/25 17:17:21 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NACHO_H
# define NACHO_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <sys/time.h>

# include "../MacroLibX-2.2.2/includes/mlx.h"
# include "../MacroLibX-2.2.2/includes/mlx_extended.h"

# include "nacho_structs.h"
# include "nacho_scancodes.h"

t_nimage	nacho_make_image(t_ncontext *nacho, int width, int height);
t_nimage	nacho_make_image_from_mlx(mlx_image image, int width, int height);
void		nacho_fill_image(t_ncontext *nacho,
				t_nimage image, mlx_color color);

t_nwindow	nacho_make_window(t_ncontext *nacho,
				t_vec2 size, char *title, int mode);
t_nwindow	nacho_make_window_target(t_ncontext *nacho, t_nimage image);
void		nacho_refresh_window(t_ncontext *nacho);
void		nacho_center_window(t_ncontext *nacho);

void		nacho_run(t_ncontext *nacho,
				void (*update)(void *args), void *args);
t_ncontext	*nacho_init(t_vec2 win_size, char *win_title, int win_mode);
void		nacho_exit(t_ncontext *nacho);

void		nacho_start_events(t_ncontext *nacho);
void		nacho_flush_inputs(t_ncontext *nacho);
void		key_down_hook(int key, void *param);
void		key_up_hook(int key, void *param);
void		mouse_down_hook(int button, void *param);
void		mouse_up_hook(int button, void *param);
void		mouse_wheel_hook(int button, void *param);
void		window_hook(int event, void *param);
void		nacho_warp_mouse(t_ncontext *nacho, int x, int y);

#endif
