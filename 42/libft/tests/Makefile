# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/09 13:07:31 by skerkour          #+#    #+#              #
#    Updated: 2014/11/11 12:03:49 by skerkour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ		= $(SRC:.c=.o)
CC		= gcc

all:
	make -C ..
	$(CC) test.c -L../ -lft -o test
	$(CC) main.c -L../ -lft -o unit_tests
#	$(CC) main2.c -L../ -lft -I../ -o test2

clean:
	make -C .. clean

fclean: clean
	make -C .. fclean
	rm -rf test test2 unit_tests a.out

re: fclean all
