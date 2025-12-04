/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:17:41 by rprieur           #+#    #+#             */
/*   Updated: 2025/12/02 15:17:42 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_H
# define FDF_STRUCTS_H

# include "../nacho/includes/nacho.h"
# include "fdf_constants.h"

typedef struct s_gridcolor
{
	mlx_color	color;
	bool		is_override;
}	t_gridcolor;

typedef struct s_grid
{
	int				*grid;
	t_gridcolor		*colors;
	int				width;
	int				height;
	int				size;
	int				min;
	int				max;
}	t_grid;

typedef struct s_camera
{
	t_vec2f	rotation;
	t_vec2f	rotation_cos;
	t_vec2f	rotation_sin;
	float	zoom;
	t_vec2	disp;
	t_vec3f	focus;
	float	height_mod;
}	t_cam;

typedef struct s_heightmap
{
	mlx_image	img;
	float		zoom;
	t_vec2f		disp;
	t_vec3		focus;
}	t_heightmap;

typedef struct s_context
{
	t_ncontext			*nacho;
	t_grid				grid;
	t_vec2				*proj_grid;
	int					line_size;
	bool				colorize_grid;
	t_cam				cam;
	bool				record_mouse;
	bool				heightmap_mode;
	t_heightmap			heightmap;
	float				fps_record[FPS_ARRAY_SIZE];
	mlx_image			crosshair;
	char				*file;
	bool				is_save_success;
}	t_context;

#endif