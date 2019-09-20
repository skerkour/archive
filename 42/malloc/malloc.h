/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:45:25 by skerkour          #+#    #+#             */
/*   Updated: 2016/12/15 17:28:00 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/mman.h>

# define TINY_SIZE 128
# define SMALL_SIZE 1024

# define TINY_LENGTH (4 * getpagesize())
# define SMALL_LENGTH (28 * getpagesize())

# define BLOCK_SIZE (sizeof(t_block))
# define PAGE_SIZE  (sizeof(t_page))

# define BDATA(blk) ((void*)((char*)blk + sizeof(t_block) + 1))
# define PDATA(page) ((void*)((char*)page + sizeof(t_page) + 1))

void				ft_free(void *ptr);
void				*ft_malloc(size_t size);
void				*ft_realloc(void *ptr, size_t size);
void				show_alloc_mem(void);

typedef enum		e_page_type
{
	TINY,
	SMALL,
	LARGE
}					t_page_type;

typedef struct		s_block
{
	size_t			size;
	int				is_free;
	struct s_block	*next;
	struct s_block	*prev;
}					t_block;

typedef struct		s_page
{
	t_page_type		type;
	size_t			size;
	struct s_page	*next;
	struct s_page	*prev;
	struct s_block	*first;
	int				nb_block;
}					t_page;

t_page				**ft_get_first_page(void);
t_page				*ft_first_page(void);
t_page_type			ft_get_page_type(size_t size);
t_page				*ft_page_of_block(t_block *block);
void				ft_delete_page(t_page *page);
t_block				*ft_merge_blocks(t_block *start);
void				ft_check_page(t_block *block);
void				ft_add_page(t_page *page);
void				ft_init_page(void *ptr, t_page_type size,
						size_t block_size);
size_t				ft_page_length(size_t size);
size_t				ft_page_length2(t_page_type size);
t_page				*ft_new_page(size_t size);
void				ft_init_block(void *ptr, size_t size);
t_block				*ft_add_block_to_page(t_page *page, size_t size);
t_block				*ft_new_block(size_t size);
void				ft_set_next_free_block(t_block *block, size_t block_size);
t_block				*ft_find_free_space_in_page(t_page *page, size_t size);
t_block				*ft_find_free_space(size_t size);
t_block				*ft_find_ptr(void *ptr);
void				ft_putendl(char *str);
void				ft_putaddr(void *addr);
void				ft_putstr(char *str);
void				ft_putendl(char *str);
void				ft_putnbr(int nb);
void				ft_putchar(char c);
void				ft_itoa_hex(uint64_t n, int is_upcase, char *buff);

#endif
