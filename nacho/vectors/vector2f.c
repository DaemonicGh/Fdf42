/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:55:25 by rprieur           #+#    #+#             */
/*   Updated: 2025/11/07 17:55:26 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nacho.h"

t_vec2f	vec2f_new(float x, float y)
{
	return ((t_vec2f){.x = x, .y = y});
}

t_vec2	vec2f_round(t_vec2f p)
{
	return ((t_vec2){.x = roundf(p.x), .y = roundf(p.y)});
}

t_vec2f	vec2f_add(t_vec2f p1, t_vec2f p2)
{
	return ((t_vec2f){.x = p1.x + p2.x, .y = p1.y + p2.y});
}

t_vec2f	vec2f_addto(t_vec2f *p1, t_vec2f p2)
{
	p1->x += p2.x;
	p1->y += p2.y;
	return (*p1);
}

t_vec2f	vec2f_sub(t_vec2f p1, t_vec2f p2)
{
	return ((t_vec2f){.x = p1.x - p2.x, .y = p1.y - p2.y});
}
