# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/14 14:01:19 by skerkour          #+#    #+#              #
#    Updated: 2016/03/11 15:52:07 by skerkour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC =	main.c \
		ftl_hooks.c \
		ftl_graphics.c \
		ftl_fractals.c \
		ftl_utils.c \
		ftl_hooks_subfunctions.c \
		ftl_utils_fractals.c

OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I libft/ -I . -O2
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
