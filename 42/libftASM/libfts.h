/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 16:07:51 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/20 17:14:36 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTS_H
# define LIBFTS_H

#include <string.h>

/*
** 64-bit C calling convention is: %rdi, %rsi, %rdx, %rcx, %r8 and %r9
*/
unsigned int	ft_arrlen(char **tab);
void			ft_bzero(void *s, size_t n);
void			ft_cat(int fd);
int				ft_indexof(char *str, char c);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr(int n);
int				ft_puts(char *str);
char			*ft_strcat(char *s1, char *s2);
char			*ft_strcpy(char *dst, char *src);
char			*ft_strdup(char *s1);
size_t			ft_strlen(char *s);
int				ft_tolower(int c);
int				ft_toupper(int c);

#endif
