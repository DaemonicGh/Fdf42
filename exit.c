/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:13:18 by rprieur           #+#    #+#             */
/*   Updated: 2025/12/01 17:13:20 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	put_exit(int status, char *message)
{
	int	i;

	i = 0;
	while (message[i])
		i++;
	write(!!status + 1, message, i);
	write(!!status + 1, "\n", 1);
	exit(status);
}

void	exit_mlx(t_context *context, int status, char *message)
{
	mlx_destroy_image(context->nacho->mlx, context->crosshair);
	mlx_destroy_image(context->nacho->mlx, context->heightmap.img);
	mlx_destroy_window(context->nacho->mlx, context->nacho->viewport.win);
	mlx_destroy_image(context->nacho->mlx, context->nacho->viewport.image);
	free(context->grid.grid);
	free(context->grid.colors);
	free(context->proj_grid);
	nacho_exit(context->nacho);
	if (status >= 0)
		put_exit(status, message);
}
