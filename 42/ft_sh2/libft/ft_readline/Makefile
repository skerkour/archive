# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skerkour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:52:54 by skerkour          #+#    #+#              #
#    Updated: 2015/03/20 17:05:10 by skerkour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= libftreadline.a
SRC		=	ft_readline.c \
			rl_ctx.c \
			rl_delete.c \
			rl_dlist_to_arr.c \
			rl_dlst.c \
			rl_output.c \
			rl_resize_handler.c \
			rl_arrows.c

OBJ		= $(SRC:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -Ofast -I ../ -I . -F termcap
# **************************************************************************** #
.PHONY: clean fclean re test

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -rf $(OBJ) test

fclean: clean
	rm -rf $(NAME) test

re: fclean $(NAME)

test: $(NAME)
	make -C ..
	gcc main.c -L .. -lft -o test -I .. -ltermcap
