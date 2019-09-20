# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/01 22:39:47 by skerkour          #+#    #+#              #
#    Updated: 2015/05/03 22:04:33 by skerkour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= arkanoid
LIB_GLFW	= -L glfw/src/ -lglfw3
LIB_FT		= -L libft/ -lft -lm
FRAMWORK	= -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
CFLAGS		= -g -Werror -Wextra -Wall -I libft/ -I glfw/include/GLFW/
BINAIRES	= $(SRC:.c=.o)
GLFW		= glfw/src/libglfw3.a
CC			= gcc
SRC			=	ark_callbacks.c \
				ark_collide.c \
				ark_init.c \
				ark_lst.c \
				ark_parse_lvl.c \
				ark_render.c \
				ark_score.c \
				ark_score2.c \
				ark_score3.c \
				ark_scores.c \
				arkanoid.c \
				main.c

# **************************************************************************** #
.PHONY: all lib clean fclean re libft_build glfw_build glfw

.SECONDARY: $(NAME)

all: glfw libft_build glfw_build $(NAME)

$(NAME): $(BINAIRES) libft/libft.a $(GLFW)
	gcc -o $(NAME) $(BINAIRES) $(LIB_GLFW) $(LIB_FT) $(FRAMWORK)

glfw:
	git submodule init
	git submodule update
	cd glfw/ ; cmake . ; cd ..

libft_build:
	make -C libft/

glfw_build:
	make -C glfw/

clean:
	rm -f $(BINAIRES)
	make -C libft/ clean
	make -C glfw/ clean

fclean: clean
	rm -f $(NAME) .score
	make -C libft/ fclean

re: fclean all
