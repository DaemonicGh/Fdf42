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

NAME := fdf.a

SRCF := main \ parsing \ parseutils \ utils \ gridutils

SRC := $(addsuffix .c, $(SRCF))

HDR := fdf.h

OBJDIR := objs/
OBJ := $(addprefix $(OBJDIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

$(OBJDIR)%.o: %.c | $(OBJDIR)
	$(CC) -c $(CFLAGS) -I $(HDR) $< -o $@

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	rm -f $(OBJ)
	rm -df $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
