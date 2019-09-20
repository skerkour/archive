# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/14 14:01:19 by skerkour          #+#    #+#              #
#    Updated: 2016/06/07 14:03:40 by skerkour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC =	main.c \
		fdf_errors.c \
		fdf_errors2.c \
		fdf_parse_file.c \
		fdf_parse_file2.c \
		fdf_lst.c \
		fdf_hooks.c \
		fdf_compute.c \
		fdf_utils.c \
		fdf_graphics.c \
		fdf_graphics2.c \
		fdf_matrices.c

OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I libft/ -I . -g
LIBS = -L libft/ -L minilibx_macos/ -lft -lm -lmlx -framework OpenGL -framework AppKit -O2

# **************************************************************************** #
.PHONY: $(NAME) all clean fclean re

$(NAME): $(OBJ)
	make -C minilibx_macos/
	make -C libft/
	gcc $(OBJ) -o $(NAME) $(LIBS)

all: $(NAME)

clean:
	make -C libft/ clean
	make -C minilibx_macos/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean $(NAME)
