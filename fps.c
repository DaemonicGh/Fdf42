/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:43:26 by rprieur           #+#    #+#             */
/*   Updated: 2025/12/01 16:43:27 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	update_fps(t_context *context)
{
	int	i;

	i = 0;
	while (i + 1 < FPS_ARRAY_SIZE)
	{
		context->fps_record[i] = context->fps_record[i + 1];
		i++;
	}
	context->fps_record[i] = 1 / context->nacho->deltatime;
}

float	average_fps(t_context *context)
{
	float	sum;
	int		i;

	sum = 0;
	i = 0;
	while (i < FPS_ARRAY_SIZE)
		sum += context->fps_record[i++];
	return (sum / FPS_ARRAY_SIZE);
}
