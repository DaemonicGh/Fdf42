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

#include "nacho.h"

t_vec3	vec3_new(int x, int y, int z)
{
	return ((t_vec3){.x = x, .y = y, .z = z});
}

t_vec3	vec3_add(t_vec3 p1, t_vec3 p2)
{
	return ((t_vec3){.x = p1.x + p2.x, .y = p1.y + p2.y, .z = p1.z + p2.z});
}

t_vec3	vec3_addto(t_vec3 *p1, t_vec3 p2)
{
	p1->x += p2.x;
	p1->y += p2.y;
	p1->z += p2.z;
	return (*p1);
}

t_vec3	vec3_sub(t_vec3 p1, t_vec3 p2)
{
	return ((t_vec3){.x = p1.x - p2.x, .y = p1.y - p2.y, .z = p1.z - p2.z});
}
