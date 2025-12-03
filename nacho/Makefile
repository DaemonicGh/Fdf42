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
CFLAGS := -Wall -Wextra -Werror
AR := ar rcs

NAME := nacho.a

SRCF := exit image init loop mouse window \
		events/events events/keyboard events/mouse events/window \
		vectors/vector2 vectors/vector3 vectors/vector2f vectors/vector3f

SRC := $(addsuffix .c, $(SRCF))

HDR :=	includes

OBJDIR := objs/
OBJ := $(addprefix $(OBJDIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

$(OBJDIR)%.o: %.c | $(OBJDIR)
	$(CC) -c $(CFLAGS) -I $(HDR) $< -o $@

$(OBJDIR):
	mkdir $(OBJDIR)
	mkdir $(OBJDIR)/events
	mkdir $(OBJDIR)/vectors

clean:
	rm -f $(OBJ)
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
