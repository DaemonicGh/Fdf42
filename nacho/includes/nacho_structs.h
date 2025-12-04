/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nacho_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:14:40 by rprieur           #+#    #+#             */
/*   Updated: 2025/12/03 16:14:42 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NACHO_STRUCTS_H
# define NACHO_STRUCTS_H

# include "../MacroLibX-2.2.2/includes/mlx.h"
# include "nacho_scancodes.h"

typedef struct s_vec2
{
	int	x;
	int	y;
}	t_vec2;

t_vec2		vec2_new(int x, int y);
t_vec2		vec2_add(t_vec2 p1, t_vec2 p2);
t_vec2		vec2_addto(t_vec2 *p1, t_vec2 p2);
t_vec2		vec2_sub(t_vec2 p1, t_vec2 p2);

typedef struct s_vec2f
{
	float	x;
	float	y;
}	t_vec2f;

t_vec2f		vec2f_new(float x, float y);
t_vec2		vec2f_round(t_vec2f p);
t_vec2f		vec2f_add(t_vec2f p1, t_vec2f p2);
t_vec2f		vec2f_addto(t_vec2f *p1, t_vec2f p2);
t_vec2f		vec2f_sub(t_vec2f p1, t_vec2f p2);

typedef struct s_vec3
{
	int	x;
	int	y;
	int	z;
}	t_vec3;

t_vec3		vec3_new(int x, int y, int z);
t_vec3		vec3_add(t_vec3 p1, t_vec3 p2);
t_vec3		vec3_addto(t_vec3 *p1, t_vec3 p2);
t_vec3		vec3_sub(t_vec3 p1, t_vec3 p2);

typedef struct s_vec3f
{
	float	x;
	float	y;
	float	z;
}	t_vec3f;

t_vec3f		vec3f_new(float x, float y, float z);
t_vec3		vec3f_round(t_vec3f p);
t_vec3f		vec3f_add(t_vec3f p1, t_vec3f p2);
t_vec3f		vec3f_addto(t_vec3f *p1, t_vec3f p2);
t_vec3f		vec3f_sub(t_vec3f p1, t_vec3f p2);

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
	int			last_key;
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
	float					delta_time;
}	t_ncontext;

typedef struct s__nacholoopcontext
{
	t_ncontext	*nacho;
	void		(*update)(void *args);
	void		*args;
}	t__nloopcontext;

#endif
