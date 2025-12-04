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

#include "includes/fdf.h"

static void	make_monitoring_str_hm(t_context *context, char str[80])
{
	setstr(str, "X=", 0);
	ft_itostr(context->heightmap.focus.x, str + 2);
	setstr(str, "Y=", 13);
	ft_itostr(context->heightmap.focus.y, str + 15);
	setstr(str, "Z=", 26);
	ft_itostr(context->heightmap.focus.z, str + 28);
	setstr(str, "Zoom=", 39);
	ft_itostr(context->heightmap.zoom * 100, str + 44);
	ft_itostr(average_fps(context), str + 73);
	setstr(str, "FPS", 76);
}

static void	make_monitoring_str_iso(t_context *context, char str[80])
{
	setstr(str, "X=", 0);
	ft_itostr(context->cam.focus.x, str + 2);
	setstr(str, "Y=", 13);
	ft_itostr(context->cam.focus.y, str + 15);
	setstr(str, "Z=", 26);
	ft_itostr(context->cam.focus.z, str + 28);
	setstr(str, "Pitch=", 39);
	ft_itostr(context->cam.rotation.x / (2 * M_PI) * 360, str + 45);
	setstr(str, "Yaw=", 50);
	ft_itostr(context->cam.rotation.y / (2 * M_PI) * 360, str + 54);
	setstr(str, "Zoom=", 59);
	ft_itostr(context->cam.zoom * 100, str + 64);
	ft_itostr(average_fps(context), str + 73);
	setstr(str, "FPS", 76);
}

void	draw_monitoring_hm(t_context *context)
{
	char	str[80];
	int		i;

	i = 0;
	while (i < 79)
		str[i++] = ' ';
	str[79] = 0;
	draw_monitoring_bg(context);
	make_monitoring_str_hm(context, str);
	mlx_string_put(context->nacho->mlx, context->nacho->viewport.win, 2, 9,
		color(TEXT_COLOR), str);
	if (context->nacho->inputs.last_key == NACHO_KEY_ENTER)
		draw_monitor_save_str(context);
	else
		mlx_string_put(context->nacho->mlx, context->nacho->viewport.win,
			context->nacho->viewport.width / 2 - 80,
			context->nacho->viewport.height - 2, color(TEXT_COLOR),
			"HEIGHTMAP MODE [TAB]");
}

void	draw_monitoring_iso(t_context *context)
{
	char	str[80];
	int		i;

	i = 0;
	while (i < 79)
		str[i++] = ' ';
	str[79] = 0;
	draw_monitoring_bg(context);
	make_monitoring_str_iso(context, str);
	mlx_string_put(context->nacho->mlx, context->nacho->viewport.win, 2, 9,
		color(TEXT_COLOR), str);
	if (context->nacho->inputs.last_key == NACHO_KEY_ENTER)
		draw_monitor_save_str(context);
	else if (!context->record_mouse)
		mlx_string_put(context->nacho->mlx, context->nacho->viewport.win,
			context->nacho->viewport.width / 2 - 120,
			context->nacho->viewport.height - 2, color(TEXT_COLOR),
			"MOUSE RECORDING PAUSED [SPACE]");
}
