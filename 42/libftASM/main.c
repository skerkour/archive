/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 16:03:13 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/20 17:13:16 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "libfts.h"

#define DEBUG 0

#undef KO
#undef OK
#define KO "\e[1;31mKO\e[0m"
#define OK "\e[1;32mOK\e[0m"

#undef TRUE
#define TRUE 1
#undef FALSE
#define FALSE 0

#ifndef SKERKOUR_LIBFT
	typedef unsigned char			t_uchar;
	typedef unsigned short			t_ushort;
	typedef unsigned int			t_uint;
	typedef unsigned long			t_ulong;
	typedef unsigned long long int	t_llint;
	typedef unsigned char			t_bool;
#endif

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

void	ft_mem_hd(void *pptr, t_ulong n)
{
	t_uchar	*ptr = (t_uchar*)pptr;
	t_uchar	*tptr = ptr;
	ptr += n;
	while (tptr < ptr)
	{
		printf("\t%p | %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x ",
			tptr, tptr[0], tptr[1], tptr[2], tptr[3], tptr[4], tptr[5], tptr[6], tptr[7],
			tptr[8], tptr[9], tptr[10], tptr[11], tptr[12], tptr[13], tptr[14], tptr[15]);
		printf("|%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",
			isprint(tptr[0]) ? tptr[0] : '.', isprint(tptr[1]) ? tptr[1] : '.',
			isprint(tptr[2]) ? tptr[2] : '.', isprint(tptr[3]) ? tptr[3] : '.',
			isprint(tptr[4]) ? tptr[4] : '.', isprint(tptr[5]) ? tptr[5] : '.',
			isprint(tptr[6]) ? tptr[6] : '.', isprint(tptr[7]) ? tptr[7] : '.',
			isprint(tptr[8]) ? tptr[8] : '.', isprint(tptr[9]) ? tptr[9] : '.',
			isprint(tptr[10]) ? tptr[10] : '.', isprint(tptr[11]) ? tptr[11] : '.',
			isprint(tptr[12]) ? tptr[12] : '.', isprint(tptr[13]) ? tptr[13] : '.',
			isprint(tptr[14]) ? tptr[14] : '.', isprint(tptr[15]) ? tptr[15] : '.');
		tptr += 16;
	}
}

t_bool t_strcat(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;
	t_uint	i = 0;

	char	src[5][200] =
	{
		{"salut =)"},
		{"regerg gr\x00erefefer"},
		{"bonjour mmmm"},
		{"SALUT =)\x00\x00fewfew mon pet\x90\x90it"},
		{"SALUT =)fewfew mon pet\x90\x90it"}
	};
	char	src2[5][200] =
	{
		{"salut =)"},
		{"regerg gr\x00erefefer"},
		{"bonjour mmmm"},
		{"SALUT =)\x00\x00fewfew mon pet\x90\x90it"},
		{"SALUT =)fewfew mon pet\x90\x90it"}
	};
	char	s2[5][200] =
	{
		{" toi"},
		{"petit filo\x00u efefer"},
		{"adame"},
		{" wesh wesh yo\x00\x00fewfew mon pet\x90\x90it"},
		{"SALUT =)fewfew mon pet\x90\x90it"}
	};

	for (i = 0; i < 5; ++i)
	{
		just =TRUE;
		strcat(src[i], s2[i]);
		ft_strcat(src2[i], s2[i]);
		if (memcmp(src[i], src2[i], 199))
		{
			ret = FALSE;
			just = FALSE;
		}
		if (v)
			printf("\t%s / %s / i = %u -> %s | %s | %s\n",src[i], s2[i], i, src[i], src2[i], just ? OK : KO);
	}
	return (ret);
}

t_bool t_bzero(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;

	char str[] = "wesh wesh yoooo\x00hello world he\x00heheheheheh";
	char str2[]  = "wesh wesh yoooo\x00hello world he\x00heheheheheh";
	int i = 0;
	while (i < sizeof (str))
	{
		just = TRUE;
		bzero(str, i);
		ft_bzero(str2, i);
		if(memcmp(str, str2, i) != 0)
		{
			ret = FALSE;
			just = FALSE;
		}
		if (v)
		{
			ft_mem_hd(str, 16);
			puts("\t-------------------------------------------------------------------");
			ft_mem_hd(str2, 16);
			puts(just ? OK : KO);
		}
		i++;
	}
	return (ret);
}

t_bool t_isalpha(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;
	int		i = 0;
	char	buf[256] = {0};

	for (i = 0; i < 256; ++i)
		buf[i] = i;
	for(i = 0; i < 256; ++i)
	{
		just = TRUE;
		if (isalpha(buf[i]) != ft_isalpha(buf[i]))
		{
			ret = FALSE;
			just = FALSE;
		}
		if (v)
			printf("\t0x%02x -> %d | %d | %s\n", buf[i], isalpha(buf[i]), ft_isalpha(buf[i]), just ? OK : KO);
	}
	return (ret);
}

t_bool t_isalnum(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;
	int		i = 0;
	char	buf[256] = {0};

	for (i = 0; i < 256; ++i)
		buf[i] = i;
	for(i = 0; i < 256; ++i)
	{
		just = TRUE;
		if (isalnum(buf[i]) != ft_isalnum(buf[i]))
		{
			ret = FALSE;
			just = FALSE;
		}
		if (v)
			printf("\t0x%02x -> %d | %d | %s\n", buf[i], isalnum(buf[i]), ft_isalnum(buf[i]), just ? OK : KO);

	}
	return (ret);
}

t_bool t_isascii(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;
	int		i = 0;
	char	buf[256] = {0};

	for (i = 0; i < 256; ++i)
		buf[i] = i;
	for(i = 0; i < 256; ++i)
	{
		just = TRUE;
		if (isascii(buf[i]) != ft_isascii(buf[i]))
		{
			ret = FALSE;
			just = FALSE;
		}
		if (v)
			printf("\t0x%02x -> %d | %d | %s\n", buf[i], isascii(buf[i]), ft_isascii(buf[i]), just ? OK :KO);
	}
	return (ret);
}

t_bool t_isdigit(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;
	int		i = 0;
	char	buf[256] = {0};

	for (i = 0; i < 256; ++i)
		buf[i] = i;
	for(i = 0; i < 256; ++i)
	{
		just = TRUE;
		if (isdigit(buf[i]) != ft_isdigit(buf[i]))
		{
			ret = FALSE;
			just = FALSE;
		}
		if (v)
			printf("\t0x%02x -> %d | %d | %s\n", buf[i], isdigit(buf[i]), ft_isdigit(buf[i]), just ? OK : KO);
	}
	return (ret);
}

t_bool t_isprint(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;
	int		i = 0;
	char	buf[256] = {0};

	for (i = 0; i < 256; ++i)
		buf[i] = i;
	for(i = 0; i < 256; ++i)
	{
		just = TRUE;
		if (isprint(buf[i]) != ft_isprint(buf[i]))
		{
			ret = FALSE;
			just = FALSE;
		}
		if (v)
			printf("\t0x%02x -> %d | %d | %s\n", buf[i], isprint(buf[i]), ft_isprint(buf[i]), just ? OK :KO);
	}
	return (ret);
}

t_bool t_memcpy(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;
	char	dst[200];
	char	dst2[200];
	char	src[] = "salut =)\x00\x42\x90\x90\x00\xff\xff\x00\x80\xcd\xffldoezfezfezfzef:;:!;!:fez!fé&";
	t_uint	i = 0;

	if (v)
		ft_mem_hd(src, sizeof(src));
	for (i = 0; i < sizeof(src); ++i)
	{
		just = TRUE;
		bzero(dst, 200);
		bzero(dst2, 200);
		memcpy(dst, src, i);
		ft_memcpy(dst2, src, i);
		if (memcmp(dst, dst2, i))
		{
			ret = FALSE;
			just = FALSE;
		}
		if (v)
			printf("\t(ft_)memcpy(dst, src, i) / %d -> %d | %d | %s\n", i, 0,
					memcmp(dst, dst2, i), just ? OK : KO);
	}
	return (ret);
}

t_bool t_memset(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;
	t_uint	i = 0;
	char	dst[50] = {0};
	char	dst2[50] = {0};

	for (i = 0; i < 42; ++i)
	{
		just = TRUE;
		bzero(dst, sizeof(dst));
		bzero(dst2, sizeof(dst2));
		memset(dst, 'B', sizeof(dst));
		ft_memset(dst2, 'B', sizeof(dst2));

		if (memcmp(dst, dst2, i))
		{
			ret = FALSE;
			just = FALSE;
		}
		if (v)
		{
			ft_mem_hd(dst, sizeof(dst));
			puts("\t-------------------------------------------------------------------");
			ft_mem_hd(dst2, sizeof(dst2));
			printf("\ti = %u -> %s\n", i, just ? OK : KO);
		}
	}
	return (ret);
}


t_bool t_tolower(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;
	int		i = 0;
	char	buf[256] = {0};

	for (i = 0; i < 256; ++i)
		buf[i] = i;
	for(i = 0; i < 256; ++i)
	{
		just = TRUE;
		if (tolower(buf[i]) != ft_tolower(buf[i]))
		{
			ret = FALSE;
			just = FALSE;
		}
		if (v)
			printf("\t0x%02x -> %d | %d | %s\n", buf[i], tolower(buf[i]),
				ft_tolower(buf[i]), just ? OK : KO);
	}
	return (ret);
}

t_bool t_toupper(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;
	int		i = 0;
	char	buf[256] = {0};

	for (i = 0; i < 256; ++i)
		buf[i] = i;
	for(i = 0; i < 256; ++i)
	{
		just = TRUE;
		if (toupper(buf[i]) != ft_toupper(buf[i]))
		{
			ret = FALSE;
			just = FALSE;
		}
		if (v)
			printf("\t0x%02x -> %d | %d | %s\n", buf[i], toupper(buf[i]),
				ft_toupper(buf[i]), just ? OK : KO);
	}
	return (ret);
}

t_bool t_strlen(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;
	t_uint	i = 0;
	char	str[10][200] =
	{
		{"salut =)\x90\x90"},
		{"42 FTW\x01\x00\x90"},
		{"hey ooo \x90 dewfewfewfew"},
		{"bon\x00 dwedeeeeeeeeeee"},
		{""},
		{"lolo\x01lol"}
	};

	for (i = 0; i < 6; ++i)
	{
		just = TRUE;
		if (strlen(str[i]) != ft_strlen(str[i]))
		{
			ret = FALSE;
			just = FALSE;
		}
		if (v)
			printf("\t'%s' -> %u | %u | %s\n", str[i], (unsigned int)strlen(str[i]), (unsigned int)ft_strlen(str[i]), just ? OK : KO);
	}
	return (ret);
}

t_bool t_strdup(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;
	char	str[] = {'f', 'e', 'r', 'f', 'r', 0x90, ' ', 'l', 'o', 'l', 0x00, 'e', 'f', 'e'};

	char	*p1;
	p1 = strdup(str);
	char	*p2;
	p2 = ft_strdup(str);

	if (strcmp(p1, p2) || p2 == str)
	{
		ret = FALSE;
		just = FALSE;
	}
	if (v)
	{
		printf("\tstr = '%s'\n", str);
		ft_mem_hd(p1, sizeof(str));
		puts("\t-------------------------------------------------------------------");
		ft_mem_hd(p2, sizeof(str));
		printf("\tstrcmp(p1, p2) = %d | %s\n", strcmp(p1, p2), just ? OK : KO);
	}
	free(p1);
	free(p2);

	just = TRUE;
	p1 = strdup("");
	p2 = ft_strdup("");
	if (strcmp(p1, p2) || p2 == str)
	{
		ret = FALSE;
		just = FALSE;
	}
	if (v)
	{
		puts("\tstr = ''\n");
		ft_mem_hd(p1, sizeof(str));
		puts("\t-------------------------------------------------------------------");
		ft_mem_hd(p2, sizeof(str));
		printf("\tstrcmp(p1, p2) = %d | %s\n", strcmp(p1, p2), just ? OK : KO);
	}
	free(p1);
	free(p2);
	return (ret);
}

t_bool t_arrlen(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;
	char	*arr1[] = {"lol", "42", NULL};
	char	*arr2[] = {NULL};
	int i;
	if (ft_arrlen(arr1) != 2)
	{
		ret = FALSE;
		just = FALSE;
	}
	if (v)
	{
		puts("arr1 :");
		for (i = 0; arr1[i]; ++i)
			printf("%s, ", arr1[i]);
		printf("\n%d -> %s\n", ft_arrlen(arr1), just == TRUE ? OK : KO);
	}
	just = TRUE;
	if (ft_arrlen(arr2) != 0)
	{
		ret = FALSE;
		just = FALSE;
	}
	if (v)
	{
		puts("arr2 :");
		for (i = 0; arr2[i]; ++i)
			printf("%s", arr2[i]);
		printf("\n%d -> %s\n", ft_arrlen(arr2), just == TRUE ? OK : KO);
	}
	return (ret);
}

t_bool t_indexof(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;
	char	*arr[] = {
		"lol",
		"lol3\x00lololol",
		"42424242452422",
		"\x00wesh wesh yo",
		"42",
		"ma maison\n"
	};
	char	to_find[] = {
		'l',
		'o',
		'5',
		'w',
		'e',
		'n'
	};
	int		rep[] = {
		0,
		1,
		9,
		-1,
		-1,
		8
	};
	int i;

	for (i = 0; i < 5; i++)
	{
		just = TRUE;
		if (ft_indexof(arr[i], to_find[i]) != rep[i])
		{
			just = FALSE;
			ret = FALSE;
		}
		if (v)
			printf("'%s', %c -> %d | %d\t%s\n", arr[i], to_find[i], rep[i], ft_indexof(arr[i], to_find[i]), just ? OK : KO);
	}
	return (ret);
}

t_bool t_strcpy(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;
	char	str[] = {'f', 'e', 'r', 'f', 'r', ' ', 0x90, 'l', 'o', 'l', 0x00, 'e', 'f', 'e'};
	char	dst[42];
	char	dst2[42];
	t_uint	i = 0;

	bzero(dst, sizeof(dst));
	bzero(dst2, sizeof(dst2));
	strcpy(dst, str);
	ft_strcpy(dst2, str);
	if (memcmp(dst, dst2, sizeof(str)))
	{
		ret = FALSE;
		just = FALSE;
	}
	if (v)
	{
		ft_mem_hd(dst, sizeof(dst));
		puts("\t-------------------------------------------------------------------");
		ft_mem_hd(dst2, sizeof(dst2));
		puts(just ? OK : KO);
	}

	just = TRUE;
	bzero(dst, sizeof(dst));
	bzero(dst2, sizeof(dst2));
	strcpy(dst, "");
	ft_strcpy(dst2, "");
	if (memcmp(dst, dst2, sizeof(str)))
	{
		ret = FALSE;
		just = FALSE;
	}
	if (v)
	{
		ft_mem_hd(dst, sizeof(dst));
		puts("\t-------------------------------------------------------------------");
		ft_mem_hd(dst2, sizeof(dst2));
		puts(just ? OK : KO);
	}
	return (ret);
}

int		main(int ac, char **av)
{
	puts("ft_arrlen: ");
	if (!t_arrlen(DEBUG)) { puts(KO); t_arrlen(1); } else puts(OK);
	
	puts("ft_bzero : ");
	if (!t_bzero(DEBUG)) { puts(KO); t_bzero(1); } else puts(OK);
	
	puts("ft_indexof : ");
	if (!t_indexof(DEBUG)) { puts(KO); t_indexof(1); } else puts(OK);
	
	puts("ft_isalnum : ");
	if (!t_isalnum(DEBUG)) { puts(KO); t_isalnum(1); } else puts(OK);

	puts("ft_isalpha : ");
	if (!t_isalpha(DEBUG)) { puts(KO); t_isalpha(1); } else puts(OK);
	
	puts("ft_isascii : ");
	if (!t_isascii(DEBUG)) { puts(KO); t_isascii(1); } else puts(OK);

	puts("ft_isdigit: ");
	if (!t_isdigit(DEBUG)) { puts(KO); t_isdigit(1); } else puts(OK);

	puts("ft_isprint: ");
	if (!t_isprint(DEBUG)) { puts(KO); t_isprint(1); } else puts(OK);
	
	puts("ft_memcpy: ");
	if (!t_memcpy(DEBUG)) { puts(KO); t_memcpy(1); } else puts(OK);

	puts("ft_memset: ");
	if (!t_memset(DEBUG)) { puts(KO); t_memset(1); } else puts(OK);
	
	puts("ft_putchar_fd: ");
	{
		ft_putchar_fd('l', 1);
		ft_putchar_fd('o', 2);
		ft_putchar_fd('o', 1);
		ft_putchar_fd('l', 1);
		ft_putchar_fd('\n', 2);
	}

	puts("ft_putnbr: ");
	{
		ft_putnbr(4242);
		ft_putchar_fd('\n', 1);
		ft_putnbr(-4242);
		ft_putchar_fd('\n', 1);
		ft_putnbr(-11);
		ft_putchar_fd('\n', 1);
		ft_putnbr(0);
		ft_putchar_fd('\n', 1);
		ft_putnbr(INT_MIN);
		ft_putchar_fd('\n', 1);
		ft_putnbr(INT_MAX);
		ft_putchar_fd('\n', 1);
	}

	puts("ft_puts: ");
	{
		puts("lol");
		ft_puts("lol");
		puts("");
		ft_puts("");
		puts("dewdwedew");
		ft_puts("dewdwedew");
		puts("lo\x00lololololpas vu");
		ft_puts("lo\x00lololololpas vu");
		puts("lol ewf ewf ewf wef 909 ew0 9");
		ft_puts("lol ewf ewf ewf wef 909 ew0 9");
		puts(NULL);
		ft_puts(NULL);
	}

	puts("ft_strcat: ");
	if (!t_strcat(DEBUG)) { puts(KO); t_strcat(1); } else puts(OK);

	puts("ft_strcpy: ");
	if (!t_strcpy(DEBUG)) { puts(KO); t_strcpy(1); } else puts(OK);
	
	puts("ft_strdup: ");
	if (!t_strdup(DEBUG)) { puts(KO); t_strdup(1); } else puts(OK);

	puts("ft_strlen: ");
	if (!t_strlen(DEBUG)) { puts(KO); t_strlen(1); } else puts(OK);

	puts("ft_tolower: ");
	if (!t_tolower(DEBUG)) { puts(KO); t_tolower(1); } else puts(OK);

	puts("ft_toupper: ");
	if (!t_toupper(DEBUG)) { puts(KO); t_toupper(1); } else puts(OK);

	if (ac  == 2)
	{
		int fd;
		if (!strcmp(av[1], "-"))
		{
			fd = -1;
			ft_cat(fd);
		}
		else if (!strcmp(av[1], "--"))
		{
			ft_cat(0);
		}
		else
		{
			fd = open(av[1], O_RDONLY);
			ft_cat(fd);
			close(fd);
		}
	}
	return (0);
}
