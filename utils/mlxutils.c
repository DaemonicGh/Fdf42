/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:00:49 by rprieur           #+#    #+#             */
/*   Updated: 2025/11/12 15:00:50 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

mlx_color	color(unsigned int hex)
{
	return ((mlx_color){.rgba = hex});
}

mlx_color	color_lerp(mlx_color col1, mlx_color col2, float t)
{
	t = fmin(fmax(t, 0), 1);
	return ((mlx_color){
		.r = (1 - t) * col1.r + t * col2.r,
		.g = (1 - t) * col1.g + t * col2.g,
		.b = (1 - t) * col1.b + t * col2.b,
		.a = (1 - t) * col1.a + t * col2.a});
}

bool	point_on_screen(t_context *context, t_vec2 p)
{
	return (p.x >= 0 && p.x < context->nacho->viewport.width
		&& p.y >= 0 && p.y < context->nacho->viewport.height);
}
