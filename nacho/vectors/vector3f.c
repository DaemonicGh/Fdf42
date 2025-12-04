/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:00:09 by rprieur           #+#    #+#             */
/*   Updated: 2025/11/07 18:00:10 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nacho.h"

t_vec3f	vec3f_new(float x, float y, float z)
{
	return ((t_vec3f){.x = x, .y = y, .z = z});
}

t_vec3	vec3f_round(t_vec3f p)
{
	return ((t_vec3){.x = roundf(p.x), .y = roundf(p.y), .z = roundf(p.z)});
}

t_vec3f	vec3f_add(t_vec3f p1, t_vec3f p2)
{
	return ((t_vec3f){.x = p1.x + p2.x, .y = p1.y + p2.y, .z = p1.z + p2.z});
}

t_vec3f	vec3f_addto(t_vec3f *p1, t_vec3f p2)
{
	p1->x += p2.x;
	p1->y += p2.y;
	p1->z += p2.z;
	return (*p1);
}

t_vec3f	vec3f_sub(t_vec3f p1, t_vec3f p2)
{
	return ((t_vec3f){.x = p1.x - p2.x, .y = p1.y - p2.y, .z = p1.z - p2.z});
}
