# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/10 22:19:47 by skerkour          #+#    #+#              #
#    Updated: 2015/03/20 17:06:13 by skerkour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libfts.a

SRC_PATH= ./src
SRC		=	$(SRC_PATH)/ft_arrlen.s \
			$(SRC_PATH)/ft_bzero.s \
			$(SRC_PATH)/ft_cat.s \
			$(SRC_PATH)/ft_indexof.s \
			$(SRC_PATH)/ft_isalnum.s \
			$(SRC_PATH)/ft_isalpha.s \
			$(SRC_PATH)/ft_isascii.s \
			$(SRC_PATH)/ft_isdigit.s \
			$(SRC_PATH)/ft_isprint.s \
			$(SRC_PATH)/ft_memcpy.s \
			$(SRC_PATH)/ft_memset.s \
			$(SRC_PATH)/ft_putchar_fd.s \
			$(SRC_PATH)/ft_putnbr.s \
			$(SRC_PATH)/ft_puts.s \
			$(SRC_PATH)/ft_strcat.s \
			$(SRC_PATH)/ft_strcpy.s \
			$(SRC_PATH)/ft_strdup.s \
			$(SRC_PATH)/ft_strlen.s \
			$(SRC_PATH)/ft_tolower.s \
			$(SRC_PATH)/ft_toupper.s

OBJ		= 	$(SRC:.s=.o)

AS		= nasm
ASFLAGS	= -f macho64
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -Ofast -I .

# **************************************************************************** #

.PHONY: $(NAME) all clean fclean re test

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) test

re: fclean $(NAME)

test: $(NAME)
	gcc main.c -o test -L . -lfts
