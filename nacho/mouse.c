/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:13:49 by rprieur           #+#    #+#             */
/*   Updated: 2025/11/27 11:13:51 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/nacho.h"

void	nacho_warp_mouse(t_ncontext *nacho, int x, int y)
{
	mlx_mouse_move(nacho->mlx, nacho->window.win,
		x * nacho->window.width / nacho->viewport.width,
		y * nacho->window.height / nacho->viewport.height);
}
