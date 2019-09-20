# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/16 19:33:34 by skerkour          #+#    #+#              #
#    Updated: 2015/06/16 20:13:18 by skerkour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= replace
SRC		=	main.cpp \
			sed.cpp

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
