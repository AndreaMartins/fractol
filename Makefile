# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andmart2 <andmart2@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 11:17:27 by andmart2          #+#    #+#              #
#    Updated: 2024/01/15 11:17:33 by andmart2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fractol
CC = cc
FLAGS = -Wall -Wextra -Werror -MMD -I ./ -o3
ML_FLAGS = -framework OpenGL -framewwork AppKit

SRC = fractol.c aux.c events.c mandelbrot.c julia.c burning_ship.c

OBJ = $(SRC: .c=.o)
DEPS = $(SRC: .c = .d)

SRC_LIBFT = ./libft/libft.a
MAKE_LIBFT = make -C libft --no-print-directory

SRC_ML = ./mlx/libmlx.a
MAKE_ML = make -C mlx --no--print-directory

%.o: %.c Makefile
	$(CC) $(FLAGS) -Iminilibx -Ilibft -c $< -0 $@

all: make_lib make_ml $(NAME)


