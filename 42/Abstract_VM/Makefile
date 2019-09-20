# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/30 03:14:36 by skerkour          #+#    #+#              #
#    Updated: 2016/03/30 03:14:36 by skerkour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.PHONY: $(NAME) all clean fclean re folders test

NAME = avm
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++14
INCLUDES = -I include/
INCLUDES_DIRECTORY = include/
SRC_DIRECTORY = src/
TARGET_DIRECTORY = target/
TEST_DIRECTORY = tests/

DEPS = Token.hpp \
	   Lexer.hpp \
	   Parser.hpp \
	   IOperand.hpp \
	   Operand.hpp \
	   VM.hpp
DEPS := $(addprefix $(INCLUDES_DIRECTORY), $(DEPS))
SRC_FILES = utils.cpp \
			Token.cpp \
			Lexer.cpp \
			Parser.cpp \
			Operand.cpp \
			VM.cpp
SRC = $(addprefix $(SRC_DIRECTORY), $(SRC_FILES))
SRC_MAIN = main.cpp
SRC_MAIN := $(addprefix $(SRC_DIRECTORY), $(SRC_MAIN))

TEST_FILES = main_test.cpp \
			 token_test.cpp \
			 lexer_test.cpp
TEST_SRC = $(addprefix $(TEST_DIRECTORY), $(TEST_FILES))
TEST_CXXFLAGS = -Wall -Wextra -g -std=c++14 -I $(TEST_DIRECTORY)
TEST_NAME = test

OBJ =  $(patsubst %.cpp, $(TARGET_DIRECTORY)%.o, $(SRC_FILES))

################################################################################

$(TARGET_DIRECTORY)%.o : $(SRC_DIRECTORY)%.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

folders:
	mkdir -p $(TARGET_DIRECTORY)
	mkdir -p $(TARGET_DIRECTORY)/bin

$(NAME): folders $(OBJ)
	$(CXX) $(OBJ) $(SRC_MAIN) $(INCLUDES) -o $(TARGET_DIRECTORY)/bin/$(NAME) $(CXXFLAGS)
	cp $(TARGET_DIRECTORY)/bin/$(NAME) .

test: folders $(OBJ)
	$(CXX) $(OBJ) $(TEST_SRC) $(INCLUDES) $(TEST_CXXFLAGS) -o $(TEST_DIRECTORY)/$(TEST_NAME)
	$(TEST_DIRECTORY)/$(TEST_NAME) -s

clean:
	rm -rf $(TARGET_DIRECTORY)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(TEST_DIRECTORY)/$(TEST_NAME)

re: fclean all
