/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:26:02 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/10 18:04:24 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

/*
** ft_readline module:
** let your cl apps be more powerfull using a fonctionnal cli with autocomplete,
** history ...
** use the termcap lib
*/
# include "ft_readline/ft_readline.h"

# ifndef UNUSED
#  define UNUSED(x) ((void)x)
# endif

# ifndef MAX
#  define MAX(x, y) (((x) > (y)) ? (x) : (y))
# endif

# ifndef MIN
#  define MIN(x, y) (((x) < (y)) ? (x) : (y))
# endif

# ifndef SKERKOUR_LIBFT
#  define SKERKOUR_LIBFT
# endif

# ifndef OK
#  define OK	1
# endif

# ifndef KO
#  define KO	0
# endif

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

# ifndef CHAR_BIT
#  define CHAR_BIT 8
# endif

# ifndef SCHAR_MIN
#  define SCHAR_MIN -128
# endif

# ifndef SCHAR_MAX
#  define SCHAR_MAX 127
# endif

# ifndef UCHAR_MAX
#  define UCHAR_MAX 0xff
# endif

# ifndef SH0RT_MIN
#  define SHORT_MIN -32768
# endif

# ifndef SHORT_MAX
#  define SHORT_MAX 32767
# endif

# ifndef USHORT_MAX
#  define USHORT_MAX 0xffff
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef UINT_MAX
#  define UINT_MAX 0xffffffff
# endif

# ifndef LLI_MIN
#  define LLI_MIN -9223372036854775808
# endif

# ifndef LLI_MAX
#  define LLI_MAX 9223372036854775807
# endif

# ifndef ULLI_MAX
#  define ULLI_MAX 0xffffffffffffffff
# endif

# define FT_STDIN	0
# define FT_STDOUT	1
# define FT_STDERR	2

# ifndef BUFF_SIZE
#  define BUFF_SIZE 65
# endif

typedef unsigned char			t_uchar;
typedef unsigned short			t_ushort;
typedef unsigned int			t_uint;
typedef unsigned long			t_ulong;
typedef unsigned long long int	t_llint;
typedef unsigned char			t_bool;

typedef struct	s_ft_buffer
{
	void		*data;
	t_ulong		size;
}				t_ftbuffer;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_ft_stack_elem
{
	t_ftbuffer				*data;
	struct s_ft_stack_elem	*next;
}				t_stack_elem;

typedef struct	s_ft_stack
{
	struct s_ft_stack_elem	*top;
	t_ulong					size;
	t_bool					(*push)(struct s_ft_stack**, t_ftbuffer*);
	t_ftbuffer				*(*pop)(struct s_ft_stack**);
	t_ftbuffer				*(*peek)(struct s_ft_stack**);
	t_bool					(*destroy)(struct s_ft_stack**);
}				t_ftstack;

typedef t_bool	t_stack_fpp(t_ftstack **this, t_ftbuffer *buf);
typedef t_bool	t_stack_fp(t_ftstack **this);

/*
** ft_adt
** Abstract Data Types sub-library
** allow you to not reinvent the wheel for each project
*/
typedef struct	s_dlst
{
	void			*data;
	t_ulong			size;
	struct s_dlst	*next;
	struct s_dlst	*prev;
}				t_dlst;

typedef struct	s_lst
{
	void			*data;
	t_ulong			size;
	struct s_lst	*next;
}				t_lst;

typedef struct	s_ft_btree
{
	struct s_ft_btree	*left;
	struct s_ft_btree	*right;
	t_ftbuffer			*data;
}				t_btree;

t_dlst			*ft_dlstmew(void *data, t_ulong size);
void			ft_dlst_del(t_dlst **lst);
t_uint			ft_dlstlen(t_dlst *list);

char			*ft_strjoinsf(char *s1, char *s2);
void			ft_exit(int n);
void			ft_lstpush_back(t_lst **top, t_lst *elem);
void			ft_qsort(void *base, size_t nmemb, size_t size,
					int (*cmp)(void *, void *));
void			ft_arrcfree(char ***array);
char			**ft_arrccpy(char **array);
t_uint			ft_arrlen(char **arr);
void			ft_lstdeli(t_lst **top, t_uint pos, void (*del)(t_lst*));
t_uint			ft_lstlen(t_lst *lst);
void			ft_lstaddi(t_lst **top, t_lst *elem, t_uint pos);
char			ft_getchar(void);
char			ft_getchar_fd(int fd);
int				ft_strcmpc(char *s1, char *s2, char c);
void			ft_lstpush(t_lst **top, t_lst *elem);
t_lst			*ft_lstpop(t_lst **top);
void			f_lstadd_end(t_list **top, t_list *elem);
t_list			*ft_lstpeek(t_list **top);
void			ft_lstdel_end(t_lst **top, void (*del)(t_lst*));
t_lst			*ft_lstnew(void *data, t_ulong size);
void			ft_lstadd_srt(t_lst **top, t_lst *elem,
					int (*cmp)(t_lst*, t_lst*));
void			ft_lstdelone(t_lst **alst, void (*del)(void *, size_t));
void			ft_lstadd_rev(t_lst **top, t_lst *elem,
						int (*cmp)(t_lst*, t_lst*));
void			ft_lstrev(t_lst **begin_list);
t_uint			ft_strcountc(char *str, char c);

t_ushort		ft_count_isize(int n);

char			*ft_strjoinf(char *s1, char *s2);
char			*ft_strjoinff(char *s1, char *s2);

void			ft_perror(char *name, char *error, int iexit);

int				ft_atoi(const char *nptr);

void			ft_btree_apply_infix(t_btree *root,
					void (*applyf)(t_ftbuffer*));
void			ft_btree_apply_prefix(t_btree *root,
					void (*applyf)(t_ftbuffer *));
void			ft_btree_apply_suffix(t_btree *root,
					void (*applyf)(t_ftbuffer*));
t_btree			*ft_btree_create_node(t_ftbuffer *item);
void			ft_btree_insert_data(t_btree **root, t_ftbuffer *item,
					int (*cmpf)(t_ftbuffer *, t_ftbuffer *));
int				ft_btree_lvl_c(t_btree *root);
void			*ft_btree_search_item(t_btree *root, t_ftbuffer *data_ref,
					int (*cmpf)(t_ftbuffer *, t_ftbuffer *));

void			ft_buffer_destroy(t_ftbuffer **buf);
t_ftbuffer		*ft_buffer_dup(t_ftbuffer *buf);
t_ftbuffer		*ft_buffer_new(void *data, t_ulong size);

int				ft_gnl(int const fd, char **line);

/*
** The ft_bzero() function writes n zeroed bytes to the string s. If n is zero,
** ft_bzero() does nothing.
***
** OUT:
*/
void			ft_bzero(void *s, size_t n);

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);

int				ft_match(char *s1, char *s2);

void			*ft_memalloc(size_t size);

/*
** The ft_memccpy() function copies bytes from string src to string dst. If the
** character c (as converted to an unsigned char) occurs in the string src,
** the copy stops and a pointer to the byte after the copy of c in the string
** dst is returned.  Otherwise, n bytes are copied, and a NULL pointer is
** returned.
** The source and destination strings should not overlap, as the behavior
** is undefined.
***
** OUT:
**	- a pointer to the byte after the copy of c in the string dst.
**	- NULL if no such byte found.
*/
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);

/*
** The ft_memchr() function locates the first occurrence of c (converted to an
** unsigned char) in string s.
***
** OUT:
**	- a pointer to the byte located.
**	- NULL if no such byte exists within n bytes.
*/
void			*ft_memchr(const void *s, int c, size_t n);

/*
** The ft_memcmp() function compares byte string s1 against byte string s2.
** Both strings are assumed to be n bytes long.
***
** OUT:
**	- 0 if the two strings are identical
**	- the difference between the two differing bytes otherwise (treated as
**	  unsigned char).
*/
int				ft_memcmp(const void *s1, const void *s2, size_t n);

/*
** The ft_memcpy() function copies n bytes from memory area src to memory area
** dst.  If dst and src overlap, behavior is undefined.
***
** OUT:
**	- returns the original value of dst.
*/
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memcpyb(void *dst, const void *src, size_t n);

void			ft_memdel(void **ap);
void			*ft_memdup(void *src, t_uint n);
int				ft_memreaalloc(void **ptr, t_uint osize, t_uint nsize);
/*
** The ft_memmove() function copies len bytes from string src to string dst.
** The two strings may overlap; the copy is always done in a non-destructive
** manner.
***
** OUT:
**	- returns the original value of dst.
*/
void			*ft_memmove(void *dst, const void *src, size_t len);
t_ulong			ft_memrepc(void *p, t_ulong n, t_uchar s, t_uchar d);
t_ulong			ft_memrepi(void *p, t_ulong n, t_uint s, t_uint d);
t_ulong			ft_memreps(void *p, t_ulong n, t_ushort s, t_ushort d);

/*
** The ft_memset() function writes len bytes of value c (converted to an
** unsigned char) to the string b.
***
** OUT:
**	- returns the original value of b.
*/
void			*ft_memset(void *b, int c, size_t len);

int				ft_nmatch(char *s1, char *s2);

void			ft_putchar_fd(char c, int fd);
void			ft_putchar(char c);
void			ft_putcharx_fd(t_uchar c, int fd);
void			ft_putcharx(t_uchar c);
void			ft_putendl_fd(char *s, int fd);
void			ft_putendl(char *s);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr(int n);
void			ft_putstr_fd(char *s, int fd);
void			ft_putstr(char *s);

t_bool			ft_stack_destroy(t_ftstack **this);
t_ftstack		*ft_stack_init(void);
t_ftbuffer		*ft_stack_pop(t_ftstack **this);
t_ftbuffer		*ft_stack_peek(t_ftstack **this);
t_bool			ft_stack_push(t_ftstack **this, t_ftbuffer *data);
/*
** append a copy of the null-terminated string s2 to the end of the
** null-terminated string s1, then add a terminating `\0'.  The string s1 must
** have sufficient space to hold the result.
***
** OUT:
**	- returns the original value of s1.
*/
char			*ft_strcat(char *s1, char *s2);

/*
** The ft_strchr() function locates the first occurrence of c (converted to a
** char) in the string pointed to by s.  The terminating null character is con-
** sidered to be part of the string; therefore if c is `\0', the functions
** locate the terminating `\0'.
***
** OUT:
**	- returns a pointer to the located character.
**	- NULL if the character does not appear in the string.
*/
char			*ft_strchr(char *s, int c);
char			**ft_strsplit(char const *s, char c);

void			ft_strclr(char *s);

int				ft_strcmp(char *s1, char *s2);

/*
** Copy the string src to dst (including the terminating `\0' character).
***
** OUT:
**	- returns the original value of src.
*/
char			*ft_strcpy(register char *dst, register char *src);
char			*ft_strcpyc(char *dst, char *src, char c);

void			ft_strdel(char **as);

/*
** The ft_strdup() function allocates sufficient memory for a copy of the string
** s1, does the copy, and returns a pointer to it.  The pointer may subse-
** quently be used as an argument to the function free(3).
***
** OUT:
**	- a pointer to the mew string
**	- NULL if an error occur.
*/
char			*ft_strdup(char *s1);
char			*ft_strdupc(const char *s1, char c);

int				ft_strequ(char *s1, char *s2);

void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char *s1, char *s2);
/*
** Appends the NUL-terminated string src to the end of dst.  It will append at
** most size - strlen(dst) - 1 bytes, NUL-terminating the result.
** The source and destination strings should not overlap, as the behavior is
** undefined.
***
** OUT:
**	- ft_strlcat() function return the total length of the string they tried
**	  to create.
*/
size_t			ft_strlcat(char *dst, const char *src, size_t size);

/*
** The ft_strlen() function computes the length of the string s.
***
** OUT:
**	- the number of characters that precede the terminating NUL character.
*/
size_t			ft_strlen(char *s);
size_t			ft_strlenc(const char *s, char c);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/*
** like ft_strcat but :
** Appends not more than n characters from s2, and then adds a terminating `\0'.
***
** OUT:
**	- returns the original value of s1.
*/
char			*ft_strncat(char *s1, const char *s2, size_t n);

int				ft_strncmp(const char *s1, const char *s2, size_t n);

/*
** copy at most n characters from src into dst.  If src is less than n
** characters long, the remainder of dst is filled with `\0' characters.
** Otherwise, dst is not terminated.
***
** OUT:
**	- returns the original value of dst.
*/
char			*ft_strncpy(char *dst, const char *src, size_t n);
int				ft_strnequ(char *s1, char *s2, size_t n);
char			*ft_strnew(size_t size);

/*
** The ft_strnstr() function locates the first occurrence of the null-terminated
** string s2 in the string s1, where not more than n characters are searched.
** Characters that appear after a `\0' character are not searched.
***
** OUT:
**	- If s2 is an empty string, s1 is returned.
**	- if s2 occurs nowhere in s1, NULL is returned;
**	- otherwise a pointer to the first character of the first occurrence of s2
**	  is returned.
*/
char			*ft_strnstr(const char *s1, const char *s2, size_t n);

/*
** The ft_strrchr() function is identical to ft_strchr(), except it locates the
** last occurrence of c.
***
** OUT:
**	- returns a pointer to the located character.
**	- NULL if the character does not appear in the string.
*/
char			*ft_strrchr(const char *s, int c);
char			*ft_strrev(char *str);
char			**ft_strsplit(char const *s, char c);
/*
** The ft_strstr() function locates the first occurrence of the null-terminated
** string s2 in the null-terminated string s1.
***
** OUT:
**	- If s2 is an empty string, s1 is returned.
**	- if s2 occurs nowhere in s1, NULL is returned;
**	- otherwise a pointer to the first character of the first occurrence of s2
**	  is returned.
*/
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			*ft_xmalloc(size_t n);

#endif
