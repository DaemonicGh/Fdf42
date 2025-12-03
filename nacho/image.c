/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:34:34 by rprieur           #+#    #+#             */
/*   Updated: 2025/11/25 18:34:35 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/nacho.h"

t_nimage	nacho_make_image(t_ncontext *nacho, int width, int height)
{
	t_nimage	img;

	img.img = mlx_new_image(nacho->mlx, width, height);
	img.width = width;
	img.height = height;
	return (img);
}

t_nimage	nacho_make_image_from_mlx(mlx_image image, int width, int height)
{
	t_nimage	img;

	img.img = image;
	img.width = width;
	img.height = height;
	return (img);
}

void	nacho_fill_image(t_ncontext *nacho, t_nimage image, mlx_color color)
{
	mlx_color	*buffer;
	int			i;

	buffer = malloc(sizeof(mlx_color) * image.width * image.height);
	i = 0;
	while (i < image.width * image.height)
		buffer[i++] = color;
 	mlx_set_image_region(nacho->mlx, image.img, 0, 0, image.width, image.height, buffer);
	free(buffer);
}
