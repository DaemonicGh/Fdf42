/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:33:36 by rprieur           #+#    #+#             */
/*   Updated: 2025/11/25 18:33:38 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/nacho.h"

t_nwindow	nacho_make_window(t_ncontext *nacho,
		t_vec2 size, char *title, int mode)
{
	t_nwindow	win;

	win.image = NULL;
	win.width = size.x;
	win.height = size.y;
	win.title = title;
	win.is_fullscreen = mode >> 1 & 1;
	win.is_resizable = mode & 1;
	win.win = mlx_new_window(nacho->mlx, &(mlx_window_create_info){
			NULL, win.title, win.width, win.height,
			win.is_fullscreen, win.is_resizable});
	return (win);
}

t_nwindow	nacho_make_window_target(t_ncontext *nacho, t_nimage image)
{
	t_nwindow	win;

	win.image = image.img;
	win.width = image.width;
	win.height = image.height;
	win.title = "";
	win.is_fullscreen = false;
	win.is_resizable = false;
	win.win = mlx_new_window(nacho->mlx, &(mlx_window_create_info){
			win.image, win.title, win.width, win.height,
			win.is_fullscreen, win.is_resizable});
	return (win);
}

void	nacho_refresh_window(t_ncontext *nacho)
{
	mlx_set_window_size(nacho->mlx, nacho->window.win,
		nacho->window.width, nacho->window.height);
	mlx_set_window_title(nacho->mlx, nacho->window.win, nacho->window.title);
	mlx_set_window_fullscreen(nacho->mlx, nacho->window.win, nacho->window.is_fullscreen);
}

void	nacho_center_window(t_ncontext *nacho)
{
	t_vec2	screen;

	mlx_get_screen_size(nacho->mlx, nacho->window.win, &screen.x, &screen.y);
 	mlx_set_window_position(nacho->mlx, nacho->window.win,
		screen.x / 2 - nacho->window.width / 2, screen.y / 2 - nacho->window.height / 2);
}
