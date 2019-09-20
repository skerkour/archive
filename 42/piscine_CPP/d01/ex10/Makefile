# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/17 11:30:20 by skerkour          #+#    #+#              #
#    Updated: 2015/06/17 20:30:54 by skerkour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cato9tails
SRC		=	main.cpp \
			ftCat.cpp

OBJ			= $(SRC:.cpp=.o)
CXX			= clang++
CXXFLAGS	= -Wall -Wextra -Werror -O3

# **************************************************************************** #
.PHONY: $(NAME) all clean fclean re

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME) $(CFLAGS)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)
