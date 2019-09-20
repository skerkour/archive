# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/21 10:47:13 by skerkour          #+#    #+#              #
#    Updated: 2015/03/25 23:36:50 by skerkour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= push_swap
SRC		=	main.c \
			ps_args.c \
			ps_ops.c \
			ps_ops2.c \
			ps_ops3.c \
			ps_push_swap.c \
			ps_stack.c \
			ps_stack2.c \
			ps_stack3.c \
			ps_stack4.c

OBJ		= $(SRC:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I libft/

# **************************************************************************** #
.PHONY: $(NAME) all clean fclean re

$(NAME): $(OBJ)
	make -C libft/
	gcc $(OBJ) -o $(NAME) -L libft/ -lft

all: $(NAME)

clean:
	make -C libft/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean $(NAME)
