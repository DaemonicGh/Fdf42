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
#include "includes/fdf_structs.h"

t_vec2	project_iso(t_cam *cam, t_vec3 p)
{
	const t_vec3	d = vec3_sub(p, vec3f_round(cam->focus));
	t_vec2			proj;

	proj = cam->disp;
	proj.x += (d.x * cam->rotation_cos.x - d.y * cam->rotation_sin.x)
		* cam->zoom;
	proj.y += (d.x * cam->rotation_sin.x + d.y * cam->rotation_cos.x)
		* cam->rotation_cos.y * cam->zoom;
	proj.y -= d.z * cam->rotation_sin.y * cam->zoom * cam->height_mod;
	return (proj);
}

mlx_color	*get_line_color_region(t_context *context,
		int pi1, int pi2, mlx_color *buffer)
{
	mlx_color	col;
	int			i;

	i = 0;
	col = color_lerp(context->grid.colors[pi1].color,
			context->grid.colors[pi2].color, 0.5);
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

void	draw_line(t_context *context, int p1, int p2, mlx_color *buffer)
{
	if (!should_cull_line(context->nacho,
			context->proj_grid[p1], context->proj_grid[p2]))
		line_put(context, context->proj_grid[p1], context->proj_grid[p2],
			get_line_color_region(context, p1, p2, buffer));
}
