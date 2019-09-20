# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/21 10:47:13 by skerkour          #+#    #+#              #
#    Updated: 2015/03/11 20:51:07 by skerkour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= ft_minishell1
SRC		=	main.c \
			sh1_env.c \
			sh1_extern_exist.c \
			sh1_signals.c \
			sh1_hooked_signals.c \
			sh1_header.c \
			sh1_parse_line.c \
			sh1_xcute.c \
			builtins/sh1_bltin_cd.c \
			builtins/sh1_bltin_exit.c \
			builtins/sh1_bltin_setenv.c \
			builtins/sh1_bltin_unsetenv.c \
			builtins/sh1_bltin_env.c

OBJ		= $(SRC:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I libft/

# **************************************************************************** #
.PHONY: $(NAME) all clean fclean re

$(NAME): $(OBJ)
	make -C libft/
	gcc $(OBJ) -o $(NAME) -L libft/ -lft -ltermcap

all: $(NAME)

clean:
	make -C libft/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean $(NAME)
