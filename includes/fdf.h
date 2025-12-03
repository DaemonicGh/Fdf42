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

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# include <stdio.h>

# include "../nacho/includes/nacho.h"
# include "fdf_constants.h"
# include "fdf_structs.h"

int				get_cell(t_grid *grid, int x, int y);
int				*get_cell_p(t_grid *grid, int x, int y);
t_vec3			get_cell_at_i(t_grid *grid, int i);
float			normalize_z(t_grid *grid, float z);
mlx_color		normalize_z_color(t_grid *grid, float z);

void			color_grid(t_grid *grid, mlx_color col1, mlx_color col2);
void			update_grid_limits(t_grid *grid);
void			update_point(t_context *context, t_vec2 point, int increment);

void			handle_camera_movement(t_context *context);
void			update_rotation(t_context *context);

t_context		init_window(t_grid *grid, char *file);

void			handle_key_inputs(t_context *context);
void			update_inputs(t_context *context);

void			update_fps(t_context *context);
float			average_fps(t_context *context);

mlx_color		color(unsigned int hex);
mlx_color		color_lerp(mlx_color col1, mlx_color col2, float t);
bool			point_on_screen(t_context *context, t_vec2 p);
void			put_exit(int status, char *message);
void			exit_mlx(t_context *context, int status, char *message);

void			line_put(t_context *context,
					t_vec2 pos1, t_vec2 pos2, mlx_color *buffer);

t_vec2			project_iso(t_cam *cam, t_vec3 p);
mlx_color		*get_line_color_region(t_context *context, int pi1, int pi2);
bool			should_cull_line(t_ncontext *nacho, t_vec2 p1, t_vec2 p2);
void			draw_grid(t_context *context);

void			toggle_heightmap(t_context *context);
void			handle_heightmap_movement(t_context *context);
void			handle_heightmap_scroll(t_context *context);
t_heightmap		make_heightmap(t_context *context);
void			update_heightmap_colors(t_context *context, mlx_image image);
void			update_heightmap_focus(t_context *context);

size_t			ft_strlen(char *str);
int				ft_isspace(int c);
int				ft_atoi(const char *str);
void			ft_putnbr(int nbr);
int				min(int val1, int val2);
int				max(int val1, int val2);
float			clamp(float val, float min, float max);
float			loop(float val, float min, float max);

void			draw_monitoring_iso(t_context *context);
void			draw_monitoring_hm(t_context *context);
int				ft_itostr(int nbr, char *str);
char			*setstr(char *str, char *section, int pos);

unsigned int	ahextocol(const char *str);
char			*read_all(int fd);
t_grid			get_grid(char *file);
void			save_grid(t_context *context);

#endif
