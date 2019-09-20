# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/20 11:39:17 by skerkour          #+#    #+#              #
#    Updated: 2015/06/23 20:24:18 by skerkour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= des_ser
SRC		=	main.cpp

OBJ			= $(SRC:.cpp=.o)
CXX			= clang++
CXXFLAGS	= -Wall -Wextra -Werror -O3

# **************************************************************************** #
.PHONY: $(NAME) all clean fclean re

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)
