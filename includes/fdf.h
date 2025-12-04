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

# include "../nacho/includes/nacho.h"
# include "fdf_constants.h"
# include "fdf_structs.h"

// LOOP

t_context		init_context(t_grid *grid, char *file);
void			handle_key_inputs(t_context *context);
void			update_inputs(t_context *context);
void			put_exit(int status, char *message);
void			free_exit(t_context *context, int status, char *message);

// GRID

int				get_cell(t_grid *grid, int x, int y);
int				*get_cell_p(t_grid *grid, int x, int y);
t_vec3			get_cell_at_i(t_grid *grid, int i);
float			normalize_z(t_grid *grid, float z);
mlx_color		normalize_z_color(t_grid *grid, float z);
void			color_grid(t_grid *grid, mlx_color col1, mlx_color col2);
void			update_grid_limits(t_grid *grid);
void			update_point(t_context *context, t_vec2 point, int increment);
t_grid			get_grid(char *file);
void			save_grid(t_context *context);

// HEIGHTMAP

void			toggle_heightmap(t_context *context);
void			handle_heightmap_movement(t_context *context);
void			handle_heightmap_scroll(t_context *context);
t_heightmap		make_heightmap(t_context *context);
void			update_heightmap_colors(t_context *context, mlx_image image);
void			update_heightmap_focus(t_context *context);

// RENDERING

void			handle_camera_movement(t_context *context);
void			set_rotation_x(t_cam *cam, float x);
void			set_rotation_y(t_cam *cam, float y);
void			update_rotation(t_context *context);

t_vec2			project_iso(t_cam *cam, t_vec3 p);
void			line_put(t_context *context,
					t_vec2 pos1, t_vec2 pos2, mlx_color *buffer);
void			draw_line(t_context *context,
					int p1, int p2, mlx_color *buffer);
void			draw_grid(t_context *context);

// MONITORING

void			draw_monitoring_iso(t_context *context);
void			draw_monitoring_hm(t_context *context);
void			draw_monitoring_bg(t_context *context);
void			draw_monitor_save_str(t_context *context);
void			update_fps(t_context *context);
float			average_fps(t_context *context);

// UTILS

char			*read_all(int fd);
mlx_color		color(unsigned int hex);
mlx_color		color_lerp(mlx_color col1, mlx_color col2, float t);
size_t			ft_strlen(char *str);
int				ft_atoi(const char *str);
unsigned int	ahextocol(const char *str);
char			*setstr(char *str, char *section, int pos);
int				ft_itostr(int nbr, char *str);
int				nbrlen_base(int nbr, int base);
void			ft_putnbr_fd(int fd, int nbr);
void			ft_putuhex_fd(int fd, unsigned int nbr);
int				min(int val1, int val2);
int				max(int val1, int val2);
float			clamp(float val, float min, float max);
float			loop(float val, float min, float max);

#endif
