/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:00:07 by rprieur           #+#    #+#             */
/*   Updated: 2025/11/26 15:00:08 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/nacho.h"

void	nacho_exit(t_ncontext *nacho)
{
	mlx_loop_end(nacho->mlx);
	mlx_destroy_window(nacho->mlx, nacho->window.win);
	mlx_destroy_context(nacho->mlx);
	free(nacho);
}
