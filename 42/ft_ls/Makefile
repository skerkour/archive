# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/21 10:47:13 by skerkour          #+#    #+#              #
#    Updated: 2014/12/08 15:40:14 by skerkour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= ft_ls
SRC		=	main.c \
			ls_args.c \
			ls_dirs.c \
			ls_list_dir.c \
			ls_long.c \
			ls_long2.c \
			ls_long3.c \
			ls_long4.c \
			ls_lst.c \
			ls_lst2.c

OBJ		= $(SRC:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

# **************************************************************************** #

$(NAME): $(OBJ)
	make -C libft/
	gcc $(OBJ) -o $(NAME) -L libft/ -lft

all: $(NAME)

.PHONY: clean fclean re

clean:
	make -C libft/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean $(NAME)
