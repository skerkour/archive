.PHONY: $(NAME) all clean fclean re folders

NAME = bfuck
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -Ofast -std=c++14
INCLUDES = -I include/
INCLUDES_DIRECTORY = include/
SRC_DIRECTORY = src/
TARGET_DIRECTORY = target/

SRC_FILES = Interpreter.cpp \
			main.cpp \
			Parser.cpp
SRC = $(addprefix $(SRC_DIRECTORY), $(SRC_FILES))

OBJ =  $(patsubst %.cpp, $(TARGET_DIRECTORY)%.o, $(SRC_FILES))

################################################################################

$(TARGET_DIRECTORY)%.o : $(SRC_DIRECTORY)%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

folders:
	mkdir -p $(TARGET_DIRECTORY)
	mkdir -p $(TARGET_DIRECTORY)/bin

$(NAME): folders $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET_DIRECTORY)/bin/$(NAME) $(CXXFLAGS)
	cp $(TARGET_DIRECTORY)/bin/$(NAME) .

clean:
	rm -rf $(TARGET_DIRECTORY)

fclean: clean
	rm -rf $(NAME)

re: fclean all
