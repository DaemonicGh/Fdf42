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

# include "MacroLibX/includes/mlx.h"
# include "MacroLibX/includes/mlx_extended.h"
# include "events/scancodes.h"

# define NACHO_KEY_SCANCODE_LENGTH 256
# define NACHO_BUTTON_SCANCODE_LENGTH 5
# define NACHO_WINDOW_SCANCODE_LENGTH 19

typedef struct s_vec2
{
	int	x;
	int	y;
}	t_vec2;

t_vec2		vec2_new(int x, int y);
void		vec2_print(t_vec2 *p);
t_vec2		vec2_add(t_vec2 p1, t_vec2 p2);
t_vec2		vec2_addto(t_vec2 *p1, t_vec2 p2);
t_vec2		vec2_sub(t_vec2 p1, t_vec2 p2);

typedef struct s_vec3
{
	int	x;
	int	y;
	int	z;
}	t_vec3;

t_vec3		vec3_new(int x, int y, int z);
void		vec3_print(t_vec3 *p);
t_vec3		vec3_add(t_vec3 p1, t_vec3 p2);
t_vec3		vec3_addto(t_vec3 *p1, t_vec3 p2);
t_vec3		vec3_sub(t_vec3 p1, t_vec3 p2);

typedef struct s_nachoimage
{
	mlx_image	img;
	int			width;
	int			height;
}	t_nimage;

typedef struct s_nachoinputhandler
{
	bool		key[NACHO_KEY_SCANCODE_LENGTH];
	bool		keyp[NACHO_KEY_SCANCODE_LENGTH];
	bool		keyr[NACHO_KEY_SCANCODE_LENGTH];
	bool		record_mouse;
	t_vec2		mouse;
	t_vec2		prev_mouse;
	bool		btn[NACHO_BUTTON_SCANCODE_LENGTH];
	bool		btnp[NACHO_BUTTON_SCANCODE_LENGTH];
	bool		btnr[NACHO_BUTTON_SCANCODE_LENGTH];
	int			mouse_wheel;
	bool		window[NACHO_WINDOW_SCANCODE_LENGTH];
	bool		should_exit;
}	t_ninputhandler;

typedef struct s_nachowindow
{
	mlx_window	win;
	mlx_image	image;
	int			width;
	int			height;
	char		*title;
	bool		is_fullscreen;
	bool		is_resizable;

}	t_nwindow;

typedef struct s_nachocontext
{
	mlx_context				mlx;
	t_nwindow				window;
	t_nwindow				viewport;
	t_ninputhandler			inputs;
	unsigned long			frame_elapsed;
}	t_ncontext;

typedef struct s__nacholoopcontext
{
	t_ncontext	*nacho;
	void		(*update)(void *args);
	void		*args;
}	t__nloopcontext;

t_nimage	nacho_make_image(t_ncontext *nacho, int width, int height);
t_nimage	nacho_make_image_from_mlx(mlx_image image, int width, int height);
void		nacho_fill_image(t_ncontext *nacho, t_nimage image, mlx_color color);

t_nwindow	nacho_make_window(t_ncontext *nacho,
				t_vec2 size, char *title, int mode);
t_nwindow	nacho_make_window_target(t_ncontext *nacho, t_nimage image);
void		nacho_refresh_window(t_ncontext *nacho);
void		nacho_center_window(t_ncontext *nacho);

void		nacho_run(t_ncontext *nacho,
				void (*update)(void *args), void *args);

t_ncontext	*nacho_init(t_vec2 win_size, char *win_title, int win_mode);

void		nacho_start_events(t_ncontext *nacho);
void		key_down_hook(int key, void *param);
void		key_up_hook(int key, void *param);
void		mouse_down_hook(int button, void *param);
void		mouse_up_hook(int button, void *param);
void		mouse_wheel_hook(int button, void *param);
void		nacho_flush_inputs(t_ncontext *nacho);
void		window_hook(int event, void *param);

void		nacho_exit(t_ncontext *nacho, int exit_code);

void		nacho_warp_mouse(t_ncontext *nacho, int x, int y);

#endif
