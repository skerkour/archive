# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skerkour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/04 18:16:48 by skerkour          #+#    #+#              #
#    Updated: 2015/01/04 18:22:10 by skerkour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= tests
SRC		= main.c
CC		= gcc
CFLAGS	= -Wall -Wextra -I .. -I . -L .. -lftprintf

# **************************************************************************** #

.PHONY: $(NAME) all clean fclean re

$(NAME):
	make -C ..
	gcc $(SRC) $(CFLAGS) -o $(NAME)

all: $(NAME)

clean:
	make -C .. clean

fclean: clean
	make -C .. fclean
	rm -rf $(NAME)

re: fclean $(NAME)
