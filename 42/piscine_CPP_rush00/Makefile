# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/20 11:39:17 by skerkour          #+#    #+#              #
#    Updated: 2015/06/21 15:26:17 by skerkour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_retro
SRC		=	main.cpp \
			Game.cpp \
			AEntity.cpp \
			Map.cpp \
			Player.cpp \
			Blast.cpp \
			Starship.cpp \
			Enemy.cpp \
			Boss.cpp \
			Asteroid.cpp

OBJ			= $(SRC:.cpp=.o)
CXX			= clang++
CXXFLAGS	= -Wall -Wextra -Werror -O3
LIBS		= -lncurses

# **************************************************************************** #
.PHONY: $(NAME) all clean fclean re

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME) $(LIBS)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) a.out

re: fclean $(NAME)
