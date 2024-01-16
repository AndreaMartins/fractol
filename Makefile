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
FLAGS = -Wall -Wextra -Werror -MMD -I ./ -O3
ML_FLAGS = -framework OpenGL -framework AppKit  # Corrected typo in the framework option

SRC = fractol.c aux.c events.c mandelbrot.c julia.c burning_ship.c

OBJ = $(SRC:.c=.o)  # Corrected typo in the substitution

SRC_LIBFT = ./libft/libft.a
MAKE_LIBFT = make -C libft --no-print-directory

SRC_ML = ./mlx/libmlx.a
MAKE_ML = make -C mlx --no-print-directory  # Corrected typo in --no--print-directory

%.o: %.c Makefile
	$(CC) $(FLAGS) -Iminilibx -Ilibft -c $< -o $@  # Corrected typo in -o option

all: make_lib make_ml $(NAME)

make_lib:
	$(MAKE_LIBFT)

make_ml:
	$(MAKE_ML)

-include $(DEPS)
$(NAME): $(OBJ) $(SRC_LIBFT) $(SRC_ML)
	$(CC) $(FLAGS) -Lminilibx $(ML_FLAGS) $(^) -o $(NAME)

clean:
	rm -f $(OBJ) $(DEPS)
	$(MAKE_LIBFT) clean  # Changed to `clean` instead of `fclean` for library clean

fclean: clean
	rm -f $(NAME)
	$(MAKE_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re make_lib make_ml

