/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:05:40 by rprieur           #+#    #+#             */
/*   Updated: 2025/11/27 18:05:41 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

t_vec2	project_iso(t_cam *cam, t_vec3 p)
{
	const t_vec3	d = vec3_sub(p, vec3f_round(cam->focus));
	t_vec2			proj;

	proj = cam->disp;
	proj.x += (d.x * cosf(cam->rotation.x) - d.y * sinf(cam->rotation.x)) * cam->zoom;
	proj.y += (d.x * sinf(cam->rotation.x) + d.y * cosf(cam->rotation.x)) * cosf(cam->rotation.y) * cam->zoom;
	proj.y -= (p.z - cam->focus.z) * sinf(cam->rotation.y) * cam->zoom * cam->height_mod;
	return (proj);
}

mlx_color	*get_line_color_region(t_context *context, int pi1, int pi2)
{
	const mlx_color	col = color_lerp(context->grid.colors[pi1].color,
			context->grid.colors[pi2].color, 0.5);
	mlx_color		*buffer;
	int				i;

	buffer = malloc(sizeof(mlx_color) * context->line_size);
	i = 0;
	while (i < context->line_size)
		buffer[i++] = col;
	return (buffer);
}

bool	should_cull_line(t_ncontext *nacho, t_vec2 p1, t_vec2 p2)
{
	return ((p1.x < 0 && p2.x < 0) || (p1.y < 0 && p2.y < 0)
		|| (p1.x >= nacho->viewport.width && p2.x >= nacho->viewport.width)
		|| (p1.y >= nacho->viewport.height && p2.y >= nacho->viewport.height));
}
