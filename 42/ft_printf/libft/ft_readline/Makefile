# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skerkour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:52:54 by skerkour          #+#    #+#              #
#    Updated: 2014/12/09 14:26:21 by skerkour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= libftreadline.a
SRC		=	ft_readline.c \
			rl_putline.c \
			rl_movecursor.c \
			rl_lst.c \
			rl_list_to_tab.c \
			rl_header.c \
			rl_ctx.c
OBJ		= $(SRC:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -Ofast -I ../ -I .
# **************************************************************************** #

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

all: $(NAME)

.PHONY: clean fclean re test

clean:
	rm -rf $(OBJ) test

fclean: clean
	rm -rf $(NAME) test

re: fclean $(NAME)

test: $(NAME)
	make -C libft/
	gcc main.c -L. -lftreadline -L .. -lft -o test -I ..
