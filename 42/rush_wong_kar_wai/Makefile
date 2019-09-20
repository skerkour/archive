# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/27 21:28:36 by skerkour          #+#    #+#              #
#    Updated: 2015/03/01 19:32:39 by skerkour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= game_2048
SRC		= 	main.c \
			wkw_check_win_loose.c \
			wkw_check_windows_size.c \
			wkw_color_off.c \
			wkw_color_on.c \
			wkw_display_nbrs.c \
			wkw_draw_grid.c \
			wkw_error.c \
			wkw_exit.c \
			wkw_exit_signal.c \
			wkw_init.c \
			wkw_parse_args.c \
			wkw_play_down.c \
			wkw_play_left.c \
			wkw_play_right.c \
			wkw_play_up.c \
			wkw_resize_handler.c \
			wkw_save_score.c \
			wkw_spawn_nbr.c \
			wkw_start_game.c

OBJ     = $(SRC:.c=.o)
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -I libft/ -lncurses -L libft/ -lft
# **************************************************************************** #
.PHONY: $(NAME) all clean fclean re

$(NAME): $(OBJ) wong_kar_wai.h
	make -C libft/
	gcc $(OBJ) -o $(NAME) $(CFLAGS)

all: $(NAME)

clean:
	make -C libft/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME) .game_2048_scores scores.txt

re: fclean $(NAME)
