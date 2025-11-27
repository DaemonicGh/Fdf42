/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_overlay.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:47:00 by rprieur           #+#    #+#             */
/*   Updated: 2025/11/17 16:47:02 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_monitoring_bg(t_context *context)
{
	mlx_color	*pixels;
	int			i;

	i = 0;
	pixels = malloc(sizeof(mlx_color) * context->nacho->viewport.width * 12);
	if (!pixels)
		return ;
	while (i < context->nacho->viewport.width * 12)
		pixels[i++] = color(MONITORING_BG_COLOR);
	mlx_pixel_put_region(context->nacho->mlx, context->nacho->viewport.win,
		0, 0, context->nacho->viewport.width, 12, pixels);
	if (!context->nacho->inputs.record_mouse || context->heightmap_mode)
		mlx_pixel_put_region(context->nacho->mlx, context->nacho->viewport.win,
			0, context->nacho->viewport.height - 12,
			context->nacho->viewport.width, 12, pixels);
	free(pixels);
}

void	make_monitoring_str_iso(t_context *context, char *str)
{
	int		i;

	i = 0;
	while (i < 79)
		str[i++] = ' ';
	str[79] = 0;
	setstr(str, "X=");
	ft_itostr(context->cam.focus.x, str + 2);
	setstr(str + 13, "Y=");
	ft_itostr(context->cam.focus.y, str + 15);
	setstr(str + 26, "Z=");
	ft_itostr(get_cell(&context->grid, context->cam.focus.x,
			context->cam.focus.y), str + 28);
	setstr(str + 39, "Angle=");
	ft_itostr((int)(context->cam.hrot.angle / (2 * M_PI) * 360), str + 45);
	setstr(str + 56, "Zoom=");
	ft_itostr(context->cam.zoom * 100, str + 61);
}

void	make_monitoring_str_hm(t_context *context, char *str)
{
	int		i;

	i = 0;
	while (i < 79)
		str[i++] = ' ';
	str[79] = 0;
	setstr(str, "X=");
	ft_itostr(context->heightmap.focus.x, str + 2);
	setstr(str + 13, "Y=");
	ft_itostr(context->heightmap.focus.y, str + 15);
	setstr(str + 26, "Z=");
	ft_itostr(get_cell(&context->grid, context->heightmap.focus.x,
			context->heightmap.focus.y), str + 28);
	setstr(str + 39, "Zoom=");
	ft_itostr(context->heightmap.zoom * 100, str + 44);
}
