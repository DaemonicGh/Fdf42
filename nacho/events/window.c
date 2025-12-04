/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:51:29 by rprieur           #+#    #+#             */
/*   Updated: 2025/11/27 11:51:31 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nacho.h"

#include <stdio.h>

void	window_hook(int event, void *param)
{
	t_ncontext	*nacho;

	if (event < 0 || event > NACHO_WINDOW_SCANCODE_LENGTH)
		return ;
	nacho = param;
	if (event == NACHO_WINDOW_CLOSE)
		nacho->inputs.should_exit = true;
	nacho->inputs.window[event] = true;
}
