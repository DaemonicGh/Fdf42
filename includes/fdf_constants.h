/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_constants.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:55:00 by rprieur           #+#    #+#             */
/*   Updated: 2025/12/02 14:55:01 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_CONSTANTS_H
# define FDF_CONSTANTS_H

# ifndef READ_BUFFER_SIZE
#  define READ_BUFFER_SIZE 2048
# endif

# define WINDOW_WIDTH 640
# define WINDOW_HEIGHT 360
# define WINDOW_TITLE "FdF"
# define WINDOW_FLAGS 0b00

# define FPS_ARRAY_SIZE 20

# define CAMERA_ZOOM_AMPLIFIER 1.15
# define HEIGHT_MOD_AMPLIFIER 8
# define MOUSE_SENSITIVITY 0.0025
# define CAMERA_SPEED 10
# define CAMERA_SPEED_ADD 20
# define HEIGHTMAP_DISP_SPEED 12.0

# define AUTO_CAMERA_HEIGHT true

# define MONITORING_BG_COLOR 0x222244EE
// Fsr la norminette est pas contente avec 0xBBBB66FF aled
# define ISO_BG_COLOR 0xBBBA66FF
# define ISO_BG_COLOR_DARK 0x222211FF
# define HM_BG_COLOR 0x555599FF
# define TEXT_COLOR 0x6699BBFF
# define BASE_LINE_COLOR 0x333333FF
# define LOW_LINE_COLOR 0x002288FF
# define HIGH_LINE_COLOR 0xEE4444FF

#endif
