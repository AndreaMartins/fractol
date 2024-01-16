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
FLAGS = -Wall -Wextra -Werror -MMD -I ./ -o3 #-g -fsanitize=address
ML_FLAGS = -framework OpenGL -framework AppKit

SRC = fractol.c aux.c events.c mandelbrot.c julia.c burning_ship.c

OBJ = $(SRC:.c=.o)
DEPS = $(SRC:.c=.d)

SRC_LIBFT = ./libft/libft.a
MAKE_LIBFT = make -C libft --no-print-directory

SRC_ML = ./minilibx/libmlx.a
MAKE_ML = make -C minilibx --no-print-directory

%.o: %.c Makefile
	$(CC) $(FLAGS) -Iminilibx -Ilibft -c $< -o $@

all: make_lib make_ml $(NAME)

make_lib:
	$(MAKE_LIBFT)

make_ml:
	$(MAKE_ML)

-include $(DEPS)
$(NAME): $(OBJ) $(SRC_LIBFT) $(SRC_ML)
	$(CC) $(FLAGS) -Lminilibx $(ML_FLAGS) $(^) -o $(NAME)

clean:
	rm -f $(OBJ) $(DEPS) $(OBJ_BONUS)
	$(MAKE_LIBFT) clean
	$(MAKE_ML) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
