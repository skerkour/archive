# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skerkour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/04 16:15:18 by skerkour          #+#    #+#              #
#    Updated: 2015/01/04 16:21:59 by skerkour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#
NAME	= libftprintf.a
SRC		=	ft_printf.c

FT_DIR	= libft
FT_OBJ	=	$(FT_DIR)/misc/ft_strchr.o \
			$(FT_DIR)/misc/ft_putstr.o \
			$(FT_DIR)/misc/ft_strlen.o \
			$(FT_DIR)/misc/ft_putchar.o \
			$(FT_DIR)/misc/ft_atoi.o \
			$(FT_DIR)/misc/ft_itoa.o \
			$(FT_DIR)/misc/ft_putcharx.o \
			$(FT_DIR)/misc/ft_strcmp.o \
			$(FT_DIR)/misc/ft_putnbr.o

OBJ		= $(SRC:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I $(FT_DIR) 

# **************************************************************************** #
.PHONY: $(NAME) all clean fclean re

$(NAME): $(OBJ)
	make -C $(FT_DIR)
	ar rc $(NAME) $(OBJ) $(FT_OBJ)

all: $(NAME)

clean:
	make -C $(FT_DIR) clean
	rm -rf $(OBJ)

fclean: clean
	make -C $(FT_DIR) fclean
	rm -rf $(NAME)

re: fclean $(NAME)
