/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:51:10 by rprieur           #+#    #+#             */
/*   Updated: 2025/11/27 11:51:12 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../nacho.h"

void	key_down_hook(int key, void *param)
{
	t_ncontext	*nacho;

	if (key < 0 || key > NACHO_KEY_SCANCODE_LENGTH)
		return ;
	nacho = param;
	if (nacho->inputs.key[key])
		return ;
	nacho->inputs.key[key] = true;
	nacho->inputs.keyp[key] = true;
}

void	key_up_hook(int key, void *param)
{
	t_ncontext	*nacho;

	if (key < 0 || key > NACHO_KEY_SCANCODE_LENGTH)
		return ;
	nacho = param;
	nacho->inputs.key[key] = false;
	nacho->inputs.keyr[key] = true;
}
