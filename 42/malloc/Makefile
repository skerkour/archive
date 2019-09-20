# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/21 10:47:13 by skerkour          #+#    #+#              #
#    Updated: 2016/12/15 17:49:21 by skerkour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME_HOST = libft_malloc_$(HOSTTYPE).so
NAME = libft_malloc.so

SRC_DIR = src
SRC		= $(SRC_DIR)/malloc.c \
		  $(SRC_DIR)/malloc2.c \
		  $(SRC_DIR)/malloc3.c \
		  $(SRC_DIR)/free.c \
		  $(SRC_DIR)/free2.c \
		  $(SRC_DIR)/free3.c \
		  $(SRC_DIR)/realloc.c \
		  $(SRC_DIR)/show_alloc_mem.c \
		  $(SRC_DIR)/put_utils.c \
		  $(SRC_DIR)/put_utils2.c \

OBJ		= $(SRC:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I .

# **************************************************************************** #

.PHONY: clean fclean re all

$(NAME_HOST): $(OBJ)
	gcc $(OBJ) -shared -o $(NAME_HOST)
	ln -s $(NAME_HOST) $(NAME)

all: $(NAME_HOST)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME_HOST) $(NAME)

re: fclean $(NAME_HOST)
