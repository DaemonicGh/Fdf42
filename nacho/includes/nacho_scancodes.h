/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scancodes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:25:27 by rprieur           #+#    #+#             */
/*   Updated: 2025/11/25 17:25:38 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NACHO_SCANCODES_H
# define NACHO_SCANCODES_H

// Simplified version of SLD2's scancodes
// [https://wiki.libsdl.org/SDL2/SDL_Scancode]

# define NACHO_KEY_SCANCODE_LENGTH 256
# define NACHO_BUTTON_SCANCODE_LENGTH 5
# define NACHO_WINDOW_SCANCODE_LENGTH 19

# define NACHO_KEY_NONE 0

# define NACHO_KEY_A 4
# define NACHO_KEY_B 5
# define NACHO_KEY_C 6
# define NACHO_KEY_D 7
# define NACHO_KEY_E 8
# define NACHO_KEY_F 9
# define NACHO_KEY_G 10
# define NACHO_KEY_H 11
# define NACHO_KEY_I 12
# define NACHO_KEY_J 13
# define NACHO_KEY_K 14
# define NACHO_KEY_L 15
# define NACHO_KEY_M 16
# define NACHO_KEY_N 17
# define NACHO_KEY_O 18
# define NACHO_KEY_P 19
# define NACHO_KEY_Q 20
# define NACHO_KEY_R 21
# define NACHO_KEY_S 22
# define NACHO_KEY_T 23
# define NACHO_KEY_U 24
# define NACHO_KEY_V 25
# define NACHO_KEY_W 26
# define NACHO_KEY_X 27
# define NACHO_KEY_Y 28
# define NACHO_KEY_Z 29

# define NACHO_KEY_1 30
# define NACHO_KEY_2 31
# define NACHO_KEY_3 32
# define NACHO_KEY_4 33
# define NACHO_KEY_5 34
# define NACHO_KEY_6 35
# define NACHO_KEY_7 36
# define NACHO_KEY_8 37
# define NACHO_KEY_9 38
# define NACHO_KEY_0 39

# define NACHO_KEY_RETURN 40
# define NACHO_KEY_ENTER 40
# define NACHO_KEY_ESCAPE 41
# define NACHO_KEY_BACKSPACE 42
# define NACHO_KEY_TAB 43
# define NACHO_KEY_SPACE 44

# define NACHO_KEY_MINUS 45
# define NACHO_KEY_EQUALS 46
# define NACHO_KEY_LEFTBRACKET 47
# define NACHO_KEY_RIGHTBRACKET 48
# define NACHO_KEY_BACKSLASH 49
# define NACHO_KEY_NONUSHASH 50
# define NACHO_KEY_SEMICOLON 51
# define NACHO_KEY_APOSTROPHE 52
# define NACHO_KEY_GRAVE 53
# define NACHO_KEY_COMMA 54
# define NACHO_KEY_PERIOD 55
# define NACHO_KEY_SLASH 56

# define NACHO_KEY_CAPSLOCK 57

# define NACHO_KEY_F1 58
# define NACHO_KEY_F2 59
# define NACHO_KEY_F3 60
# define NACHO_KEY_F4 61
# define NACHO_KEY_F5 62
# define NACHO_KEY_F6 63
# define NACHO_KEY_F7 64
# define NACHO_KEY_F8 65
# define NACHO_KEY_F9 66
# define NACHO_KEY_F10 67
# define NACHO_KEY_F11 68
# define NACHO_KEY_F12 69

# define NACHO_KEY_PRINTSCREEN 70
# define NACHO_KEY_SCROLLLOCK 71
# define NACHO_KEY_PAUSE 72
# define NACHO_KEY_INSERT 73
# define NACHO_KEY_HOME 74
# define NACHO_KEY_PAGEUP 75
# define NACHO_KEY_DELETE 76
# define NACHO_KEY_END 77
# define NACHO_KEY_PAGEDOWN 78
# define NACHO_KEY_RIGHT 79
# define NACHO_KEY_LEFT 80
# define NACHO_KEY_DOWN 81
# define NACHO_KEY_UP 82

# define NACHO_KEY_NUMLOCKCLEAR 83
# define NACHO_KEY_KP_DIVIDE 84
# define NACHO_KEY_KP_MULTIPLY 85
# define NACHO_KEY_KP_MINUS 86
# define NACHO_KEY_KP_PLUS 87
# define NACHO_KEY_KP_ENTER 88
# define NACHO_KEY_KP_1 89
# define NACHO_KEY_KP_2 90
# define NACHO_KEY_KP_3 91
# define NACHO_KEY_KP_4 92
# define NACHO_KEY_KP_5 93
# define NACHO_KEY_KP_6 94
# define NACHO_KEY_KP_7 95
# define NACHO_KEY_KP_8 96
# define NACHO_KEY_KP_9 97
# define NACHO_KEY_KP_0 98
# define NACHO_KEY_KP_PERIOD 99

# define NACHO_KEY_LCTRL 224
# define NACHO_KEY_LSHIFT 225
# define NACHO_KEY_LALT 226
# define NACHO_KEY_LGUI 227
# define NACHO_KEY_RCTRL 228
# define NACHO_KEY_RSHIFT 229
# define NACHO_KEY_RALT 230
# define NACHO_KEY_RGUI 231

// Mouse events

# define NACHO_BUTTON_LEFT 1
# define NACHO_BUTTON_MIDDLE 2
# define NACHO_BUTTON_RIGHT 3
# define NACHO_BUTTON_X1 4
# define NACHO_BUTTON_X2 5

# define NACHO_SCROLL_UP 1
# define NACHO_SCROLL_DOWN -1

// Window events (not tested)

# define NACHO_WINDOW_CLOSE 0

#endif
