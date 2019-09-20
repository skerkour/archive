# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skerkour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:52:54 by skerkour          #+#    #+#              #
#    Updated: 2014/11/27 16:55:39 by skerkour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRC		=	ft_atoi.c \
			ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strcpy.c \
			ft_strdup.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strncat.c \
			ft_strncpy.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_putchar.c \
			ft_putendl.c \
			ft_putstr.c \
			ft_putnbr.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_itoa.c \
			ft_strsplit.c \
			ft_strlenc.c \
			ft_strcpyc.c \
			ft_strdupc.c \
			ft_memcpyb.c \
			ft_memrepc.c \
			ft_memreps.c \
			ft_memrepi.c \
			ft_memrepl.c \
			ft_memdup.c \
			ft_strrev.c \
			ft_memrealloc.c \
			ft_stack_init.c \
			ft_stack_push.c \
			ft_stack_pop.c \
			ft_stack_peek.c \
			ft_stack_destroy.c \
			ft_putcharx.c \
			ft_putcharx_fd.c \
			ft_btree_create_node.c \
			ft_btree_apply_prefix.c \
			ft_btree_apply_infix.c \
			ft_btree_apply_suffix.c \
			ft_btree_insert_data.c \
			ft_btree_search_item.c \
			ft_btree_level_count.c \
			ft_btree_destroy.c \
			ft_buffer_dup.c \
			ft_buffer_destroy.c \
			ft_buffer_new.c \
			ft_match.c \
			ft_nmatch.c \
			ft_xmalloc.c \
			ft_lstpush.c \
			ft_lstpop.c \
			ft_lstadd_end.c \
			ft_lstaddi.c \
			ft_lstpeek.c \
			ft_lstdel_end.c \
			ft_lstdel.c \
			ft_lstnew.c \
			ft_lstadd_srt.c \
			ft_lstadd_rev.c \
			ft_strjoinf.c \
			ft_strjoinff.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_count_isize.c \
			ft_lstrev.c \
			ft_strcountc.c
OBJ		= $(SRC:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -Ofast

# **************************************************************************** #

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)
