/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:18:28 by rprieur           #+#    #+#             */
/*   Updated: 2025/12/01 17:18:29 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

inline int	min(int val1, int val2)
{
	if (val1 < val2)
		return (val1);
	return (val2);
}

inline int	max(int val1, int val2)
{
	if (val1 > val2)
		return (val1);
	return (val2);
}

inline float	clamp(float val, float min, float max)
{
	return (fmin(fmax(val, min), max));
}

inline float	loop(float val, float min, float max)
{
	while (val < min)
		val += max - min;
	while (val >= max)
		val -= max - min;
	return (val);
}
