# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rprieur <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/24 19:51:36 by rprieur           #+#    #+#              #
#    Updated: 2025/10/13 14:34:30 by rprieur          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Wextra -Werror -g

NAME := fdf

LIB := nacho/nacho.a nacho/MacroLibX-2.2.2/libmlx.so
LIBFLAGS := -lSDL2 -lm

SRCF := camera exit fps grid heightmap heightmap_inputs init inputs keyboard_inputs \
		line main overlay overlay_spe parsing projection rendering \
		utils/gridutils utils/mathutils utils/mlxutils \
		utils/nbrutils utils/parseutils utils/strutils

SRC := $(addsuffix .c, $(SRCF))

HDR :=	includes

OBJDIR := objs/
OBJ := $(addprefix $(OBJDIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIB) $(LIBFLAGS) -o $(NAME)

$(OBJDIR)%.o: %.c | $(OBJDIR)
	$(CC) -c $(CFLAGS) -I $(HDR) $< -o $@

$(OBJDIR):
	mkdir $(OBJDIR)
	mkdir $(OBJDIR)/utils

clean:
	rm -f $(OBJ)
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
