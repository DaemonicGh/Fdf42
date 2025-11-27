/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:37:07 by rprieur           #+#    #+#             */
/*   Updated: 2025/11/06 17:37:09 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef READ_BUFFER_SIZE
#  define READ_BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# include <stdio.h>

# include "nacho/nacho.h"

# define WINDOW_WIDTH 640
# define WINDOW_HEIGHT 360
# define WINDOW_TITLE "FdF"
# define WINDOW_FLAGS 0b01

# define CAMERA_ZOOM_AMPLIFIER 1.15
# define HEIGHT_MOD_AMPLIFIER 1.25
# define MOUSE_SENSITIVITY 0.0025
# define HEIGHTMAP_DISP_SPEED 12.0

# define AUTO_CAMERA_HEIGHT true

# define MONITORING_BG_COLOR 0x222244EE
# define ISO_BG_COLOR 0x777755FF
# define ACTUAL_ISO_BG_COLOR 0xB6B69CFF
# define HM_BG_COLOR 0x555599FF
# define TEXT_COLOR 0x6699BBFF
# define LOW_LINE_COLOR 0x0000FFFF
# define HIGH_LINE_COLOR 0xFF0000FF
# define NULL_COLOR 0xFFFFFF00

typedef mlx_window_create_info	t_winfo;

typedef struct s_grid
{
	int				*grid;
	unsigned int	*colors;
	int				width;
	int				height;
	int				size;
	int				min;
	int				max;
}	t_grid;

typedef struct s_angle
{
	float	angle;
	float	cos;
	float	sin;
}	t_angle;

typedef struct s_camera
{
	float	matrix[3][2];
	t_angle	hrot;
	float	zoom;
	t_vec2	disp;
	t_vec3	focus;
	float	height_mod;
}	t_cam;

typedef struct s_heightmap
{
	mlx_image	img;
	float		zoom;
	float		dispx;
	float		dispy;
	t_vec2		focus;
}	t_heightmap;

typedef struct s_context
{
	t_ncontext			*nacho;
	t_grid				grid;
	t_vec2				*proj_grid;
	t_cam				cam;
	bool				heightmap_mode;
	t_heightmap			heightmap;
	mlx_image			crosshair;
}	t_context;

int				get_cell(t_grid *grid, int x, int y);
t_vec3			get_cell_at_i(t_grid *grid, int i);
float			normalize_z(t_grid *grid, float z);
mlx_color		normalize_z_color(t_grid *grid, float z);

void			move_cam(t_context *context, t_vec2 disp);
void			handle_camera_movement(t_context *context);
void			update_rotation(t_context *context);

t_context		init_window(t_grid *grid);

void			update_inputs(t_context *context);

mlx_color		color(unsigned int hex);
mlx_color		color_lerp(mlx_color col1, mlx_color col2, float t);
bool			point_on_screen(const t_context *context, t_vec2 p);
void			exit_mlx(t_context *context);

void			line_put(const t_context *context,
					t_vec2 pos1, t_vec2 pos2, mlx_color col);

t_vec2			project_iso(t_cam *cam, t_vec3 p);
void			draw_grid(t_context *context);

void			toggle_heightmap(t_context *context);
void			handle_heightmap_movement(t_context *context);
void			handle_heightmap_zoom(t_context *context);
t_heightmap		make_heightmap(t_context *context);
void			update_heightmap(t_context *context);

size_t			ft_strlen(char *str);
int				ft_isspace(int c);
int				ft_atoi(const char *str);
void			ft_putnbr(int nbr);
int				min(int val1, int val2);
int				max(int val1, int val2);

void			draw_monitoring_bg(t_context *context);
void			make_monitoring_str_iso(t_context *context, char *str);
void			make_monitoring_str_hm(t_context *context, char *str);
int				ft_itostr(int nbr, char *str);
int				setstr(char *str, char *replacement);

unsigned int	ahextocol(const char *str);
char			*allocdstrjoin(char *str1, char *str2);
char			*read_all(int fd);
t_grid			get_grid(char *file);

#endif
