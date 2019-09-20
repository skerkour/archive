/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:54:35 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/15 13:23:56 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** some test from :
** - https://github.com/Nax/libft-test
** -
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "../libft.h"

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

#endif // SKERKOUR_LIBFT

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

t_bool	t_atoi(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;
	int		i = 0;

	char str[18][20] =
	{
		{"000000110"},
		{"-153"},
		{"+132"},
		{"++876"},
		{"--132"},
		{"dsds"},
		{"42jk "},
		{" 21"},
		{"      32 "},
		{"42 32 "},
		{"1-2"},
		{"4+2 "},
		{"  +442"},
		{"  -4232 "},
		{"4,5"},
		{"  \t\n  \r\r\v\f-899"},
		{""},
		{"2147483647"}
	};

	while (i < 18)
	{
		just = TRUE;
		if(atoi(str[i]) != ft_atoi(str[i]))
		{
			ret = FALSE;
			just = FALSE;
		}
		if (v)
			printf("\t'%s' -> %d | %d | %s\n", str[i], atoi(str[i]),
					ft_atoi(str[i]), just ? OK : KO);
		i++;
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

t_bool t_itoa(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;

	int		nb[10] = {
		0,
		-4242,
		4242,
		12345600,
		1,
		-1,
		-2147483648,
		199994,
		133742,
		2147483647
	};
	char	str[10][20] = {
		{ "0" },
		{ "-4242" },
		{ "4242" },
		{ "12345600" },
		{ "1" },
		{ "-1" },
		{ "-2147483648" },
		{ "199994" },
		{ "133742" },
		{"2147483647"}
	};
	int i = 0;
	char	*reti;

	for (i = 0; i < 10; ++i)
	{
		just = TRUE;
		reti = ft_itoa(nb[i]);
		if (strcmp(reti, str[i]))
		{
			ret = FALSE;
			just = FALSE;
		}
		if (v)
			printf("\t%d -> '%s' | '%s' | %s\n", nb[i], str[i], reti, just ? OK : KO);
		if (!just && v)
			ft_mem_hd(reti, 16);
		free(reti);
	}
	return (ret);
}

t_bool t_memalloc(int v)
{
	t_bool	ret = TRUE;
	void	*p1 = malloc(142),
			*p2 = ft_memalloc(142);

	bzero(p1, 142);
	if (memcmp(p1, p2, 142))
	{
		ret = FALSE;
	}
	if (v)
	{
		ft_mem_hd(p1, 142);
		puts("\t-------------------------------------------------------------------");
		ft_mem_hd(p2, 142);
		puts(ret ? OK : KO);
	}
	free(p1);
	free(p2);
	return (ret);
}

t_bool t_memccpy(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;
	char	dst[200] = {0};
	char	src[] = "Ceci est \x00un test =)";
	void	*p1, *p2;

	p1 = memccpy(dst, src, 'i', 10);
	p2 = ft_memccpy(dst, src, 'i', 10);
	if (p1 != p2)
	{
		ret = FALSE;
		just = FALSE;
	}
	if (v)
	{
		ft_mem_hd(dst, sizeof(src));
		printf("\t'%s' -> %p | %p | %s\n", "(ft_)memccpy(dst, src, 'i', 10);", p1, p2, just ? OK :KO);
	}

	just = TRUE;
	p1 = memccpy(dst, src, 'k', 5);
	p2 = ft_memccpy(dst, src, 'k', 5);
	if (p1 != p2)
	{
		ret = FALSE;
		just = FALSE;
	}
	if (v)
	{
		ft_mem_hd(dst, sizeof(src));
		printf("\t'%s' -> %p | %p | %s\n", "(ft_)memccpy(dst, src, 'k', 5);", p1, p2, just ? OK :KO);
	}

	just = TRUE;
	p1 = memccpy(dst, src, 0, 0);
	p2 = ft_memccpy(dst, src, 0, 0);
	if (p1 != p2)
	{
		ret = FALSE;
		just = FALSE;
	}
	if (v)
	{
		ft_mem_hd(dst, sizeof(src));
		printf("\t'%s' -> %p | %p | %s\n", "(ft_)memccpy(dst, src, 0, sizeof(src));", p1, p2, just ? OK : KO);
	}

	just = TRUE;
	p1 = memccpy(dst, src, 0, sizeof(src));
	p2 = ft_memccpy(dst, src, 0, sizeof(src));
	if (p1 != p2)
	{
		ret = FALSE;
		ret = FALSE;
	}
	if (v)
	{
		ft_mem_hd(dst, sizeof(src));
		printf("\t'%s' -> %p | %p | %s\n", "(ft_)memccpy(dst, src, 0, sizeof(src));", p1, p2, just ? OK : KO);
	}

	just = TRUE;
	p1 = ft_memccpy(dst, src, 'e', sizeof(src));
	p2 = dst + 2;
	if (p1 != p2)
	{
		ret = FALSE;
		just = FALSE;
	}
	if (v)
	{
		ft_mem_hd(dst, sizeof(src));
		printf("\t'%s' -> %p | %p | %s\n", "(ft_)memccpy(dst, src, 'e', sizeof(src));", p1, p2, just ? OK : KO);
	}
	return (ret);
}

t_bool t_memchr(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;
	char	str[] = "abcdefGIJHKKA1fezfezfz\x00$*%µM.?./-('(-è_234567890AAZERYJNdazazdazdazdazdzadezrtyhdgresgreB";
	t_uint	i = 0, len = 0;

	if (v)
		ft_mem_hd(str, sizeof(str));
	for (i = 0, len = strlen(str) + 1; i < len; ++i)
	{
		just = TRUE;
		if (memchr(str, i, i) != ft_memchr(str, i, i))
		{
			just = FALSE;
			ret = FALSE;
		}
		if (v)
			printf("\t'0x%0x2' / %u -> %p | %p | %s\n", i, i, memchr(str, i, i),
					ft_memchr(str, i, i), just ? OK : KO);
	}
	return (ret);
}

t_bool t_memcmp(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;
	t_uint	i = 0;
	char	buff[300];
	char	buf[300];
	for (i = 0; i < sizeof(buff); ++i)
		buff[i] = (char)i;
	for (i = 0; i < sizeof(buf); ++i)
		buf[i] = (char)i;
	buf[120] = 0x42;
	buff[180] = 0x90;
	if (v)
	{
		ft_mem_hd(buff, sizeof(buff));
		puts("\t-------------------------------------------------------------------");
		ft_mem_hd(buf, sizeof(buf));
	}
	for (i = 0; i < sizeof(buff); ++i)
	{
		just = TRUE;
		if (i == 130)
			buff[120] = 0x42;
		if (memcmp(buff, buf, i) != ft_memcmp(buff, buf, i))
		{
			ret = FALSE;
			just = FALSE;
		}
		if (v)
			printf("\t%s / %d-> %d | %d | %s\n", "(ft_)memcmp(buff, buf, i)", i,
					memcmp(buff, buf, i), ft_memcmp(buff, buf, i), just ? OK : KO);
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

t_bool t_memdel(int v)
{
	t_bool	ret = TRUE;
	void	*ptr = malloc(200);

	ft_memdel(&ptr);
	if (ptr)
		ret = FALSE;
	if (v)
		printf("\t%p | %p | %s", NULL, ptr, ret ? OK : KO);
	return (ret);
}

t_bool t_memmove(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;
	t_uint	i = 0;
	char	orig[] = "salut =)\x00\x42\x90\x90\x00\xff\xff\x00\x80\xcd\xffldoezfezfezfzef:;:!;!:fez!fewfféfefewf&";
	char	buf[] = "salut =)\x00\x42\x90\x90\x00\xff\xff\x00\x80\xcd\xffldoezfezfezfzef:;:!;!:fez!fewfféfefewf&";
	char	buf2[] = "salut =)\x00\x42\x90\x90\x00\xff\xff\x00\x80\xcd\xffldoezfezfezfzef:;:!;!:fez!fewfféfefewf&";
	if (v)
		ft_mem_hd(buf, sizeof(buf));
	for (i = 0; i < 42; ++i)
	{
		just = TRUE;
		memmove(buf, buf + i, sizeof(buf) - i);
		ft_memmove(buf2, buf2+ i, sizeof(buf2) - i);
		if (memcmp(buf2, buf, i))
		{
			ret = FALSE;
			just = FALSE;
		}
		if (v)
		{
			ft_mem_hd(buf, sizeof(buf));
			puts("\t-------------------------------------------------------------------");
			ft_mem_hd(buf2, sizeof(buf2));
			printf("\ti = %u -> %s\n", i, just ? OK : KO);
		}
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

t_bool t_strchr(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;
	t_uint	i = 0;
	char	str[] = "gg la \x90 Bande de fous\x0\x0 4142F";

	char	tab[10] = {'a', '1', '4', 0x90, 0x00, 'B', 'n', 'F', 0x01, 'G'};

	char	*r = NULL;
	char	*r2 = NULL;

	if (v)
		ft_mem_hd(str, sizeof(str));
	for (i = 0; i < 10; ++i)
	{
		just =TRUE;
		r = NULL;
		r2 = NULL;
		r = strchr(str, tab[i]);
		r2 = ft_strchr(str, tab[i]);
		if (r != r2)
		{
			ret = FALSE;
			just = FALSE;
		}
		if (v)
			printf("\tc = %02x -> %p | %p | %s\n", tab[i], r ,r2, just ? OK : KO);
	}
	just = TRUE;
	char lol[] = "";
	if (strchr(lol, 0) != ft_strchr(lol, 0))
	{
		ret = FALSE;
		just = FALSE;
	}
	if (v)
		printf("\tstr = '' / c = %02x -> %p | %p | %s\n", 0 , strchr(lol, 0), ft_strchr(lol, 0), just ? OK : KO);
	return (ret);
}

t_bool t_strclr(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;

	char	s1[] = "ferfrefrefer";
	char	vide[sizeof(s1)] = {0};
	if (v)
	{
		puts("\tbefore : ");
		ft_mem_hd(vide, sizeof(vide));
		puts("\t-------------------------------------------------------------------");
		ft_mem_hd(s1, sizeof(s1));
	}
	ft_strclr(s1);
	if (memcmp(s1, vide, sizeof(s1)))
	{
		ret =  FALSE;
		just = FALSE;
	}
	if (v)
	{
		puts("\tafter : ");
		ft_mem_hd(vide, sizeof(vide));
		puts("\t-------------------------------------------------------------------");
		ft_mem_hd(s1, sizeof(s1));
		puts(just ? OK : KO);
	}

	just = TRUE;
	char	s2[] = {'f', 'e', 'r', 'f', 'r', ' ', ' ', 0x00, 'e', 'f', 'e'};
	char	s3[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 'e', 'f', 'e'};
	if (v)
	{
		puts("\tbefore : ");
		ft_mem_hd(s3, sizeof(s3));
		puts("\t-------------------------------------------------------------------");
		ft_mem_hd(s2, sizeof(s2));
	}
	ft_strclr(s2);
	if (memcmp(s2, s3, sizeof(s2)))
	{
		ret =  FALSE;
		just = FALSE;
	}
	if (v)
	{
		puts("\tafter : ");
		ft_mem_hd(s3, sizeof(s3));
		puts("\t-------------------------------------------------------------------");
		ft_mem_hd(s2, sizeof(s2));
		puts(just ? OK : KO);
	}
	return (ret);
}

t_bool t_strcmp(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;
	t_uint	i = 0;

	char	s1[9][42] =
	{
		{""},
		{"salut =)"},
		{"salut =("},
		{"wwwwwwww \x00 dwdw"},
		{"dwdwdwdw"},
		{""},
		{"ma ison  maiso n maisone"},
		{"yoyoyoyoyoyoyoyyoyo"},
		{"yoyoyoyoyoyoyoyyoyo"}
	};
	char	s2[9][42] =
	{
		{""},
		{"salut =("},
		{"salut =)"},
		{"wwwwwwww \x00 ololo"},
		{""},
		{"dwdwdwdw"},
		{"ma ison  maiso n maisona"},
		{"yoyoyoyoyoyoyoyyoyo "},
		{"yoyoyoyoyoyoyoyyoyo"}
	};

	for (i = 0; i < 9; ++i)
	{
		just = TRUE;
		if (strcmp(s1[i], s2[i]) != ft_strcmp(s1[i], s2[i]))
		{
			just = FALSE;
			ret = FALSE;
		}
		if (v)
			printf("\ts1 = '%s' / s2 = '%s' -> %d | %d | %s\n", s1[i], s2[i],
				strcmp(s1[i], s2[i]), ft_strcmp(s1[i], s2[i]), just ? OK : KO);
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

t_bool t_strdel(int v)
{
	t_bool	ret = TRUE;
	char	*ptr = (char*)malloc(200);

	ft_strdel(&ptr);
	if (ptr)
		ret = FALSE;
	if (v)
		printf("\t%p | %p | %s", NULL, ptr, ret ? OK : KO);
	return (ret);
}

t_bool t_strdup(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;
	char	str[] = {'f', 'e', 'r', 'f', 'r', 0x90, ' ', 'l', 'o', 'l', 0x00, 'e', 'f', 'e'};

	char	*p1 = strdup(str);
	char	*p2 = ft_strdup(str);

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

t_bool t_strequ(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;
	t_uint	i = 0;

	char	s1[9][42] =
	{
		{""},
		{"salut =)"},
		{"salut =("},
		{"wwwwwwww \x00 dwdw"},
		{"dwdwdwdw"},
		{""},
		{"ma ison  maiso n maisone"},
		{"yoyoyoyoyoyoyoyyoyo"},
		{"yoyoyoyoyoyoyoyyoyo"}
	};
	char	s2[9][42] =
	{
		{""},
		{"salut =("},
		{"salut =)"},
		{"wwwwwwww \x00 ololo"},
		{""},
		{"dwdwdwdw"},
		{"ma ison  maiso n maisona"},
		{"yoyoyoyoyoyoyoyyoyo "},
		{"yoyoyoyoyoyoyoyyoyo"}
	};
	int val = 0;
	for (i = 0; i < 9; ++i)
	{
		just = TRUE;
		val = strcmp(s1[i], s2[i]) ? 0 : 1;
		if (val != ft_strequ(s1[i], s2[i]))
		{
			just = FALSE;
			ret = FALSE;
		}
		if (v)
			printf("\ts1 = '%s' / s2 = '%s' -> %d | %d | %s\n", s1[i], s2[i],
				val, ft_strequ(s1[i], s2[i]), just ? OK : KO);
	}
	return (ret);
}

static void tf_striter(char *c)
{
	if (*c >= 0x61 && *c <= 0x7a)
		*c -= 0x20;
}
t_bool t_striter(int v)
{
	t_bool	ret = TRUE;
	char	str[] = "aAAaADEFfrefrefer9089078986';'..,";
	char	res[] = "AAAAADEFFREFREFER9089078986';'..,";

	ft_striter(str, tf_striter);
	if (memcmp(str, res, sizeof(str)))
		ret = FALSE;
	if (v)
	{
		ft_mem_hd(res, sizeof(str));
		puts("\t-------------------------------------------------------------------");
		ft_mem_hd(str, sizeof(str));
		puts(ret ? OK : KO);
	}
	return (ret);
}

static void tf_striteri(unsigned int i, char *c)
{
	*c = i;
}
t_bool t_striteri(int v)
{
	t_bool	ret = TRUE;
	char	str[] = {'a', 'b', 'c', 'd', 's', 's', 's', 's', 0x00, 0};
	char	res[] = { 0, 1, 2, 3, 4, 5, 6, 7, 0, 0x00,};

	ft_striteri(str, tf_striteri);
	if (memcmp(str, res, sizeof(str)))
		ret = FALSE;
	if (v)
	{
		ft_mem_hd(res, sizeof(str));
		puts("\t-------------------------------------------------------------------");
		ft_mem_hd(str, sizeof(str));
		puts(ret ? OK : KO);
	}
	return (ret);
}

t_bool t_strjoin(int v)
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
	char	*res = NULL;

	for (i = 0; i < 5; ++i)
	{
		just =TRUE;
		strcat(src[i], s2[i]);
		res = ft_strjoin(src2[i], s2[i]);
		if (strcmp(src[i], res) || res == src2[i])
		{
			ret = FALSE;
			just = FALSE;
		}
		if (v)
			printf("\t%s / %s / i = %u -> %s | %s | %s\n",src[i], s2[i], i, src[i], src2[i], just ? OK : KO);
		free(res);
	}
	return (ret);
}

#ifndef linux
t_bool t_strlcat(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;
	size_t	k;
	size_t	j;

	char	s1[] = "c est ";
	char	s2[] = "moi";
	size_t	i = 0;
	char	*target = malloc(sizeof(s1)-1 + sizeof(s2) + 10);
	char	*target2 = malloc(sizeof(s1)-1 + sizeof(s2) + 10);

	while (i < 15)
	{
		just = TRUE;
		ft_bzero(target, sizeof(s1)-1 + sizeof(s2) + 10);
		ft_bzero(target2, sizeof(s1)-1 + sizeof(s2) + 10);
		strcpy(target, s1);
		strcpy(target2, s1);
		k = strlcat(target, s2, i);
		j = ft_strlcat(target2, s2, i);
		if (k != j || memcmp(target, target2, sizeof(s1)-1 + sizeof(s2) + 10))
		{
			ret = FALSE;
			just = FALSE;
		}
		if (v)
		{
			printf("\ts1 = '%s' / s2 = '%s' / n = %u -> %u | %u | %s\n", s1, s2,
					i, k, j, just ? OK : KO);
			ft_mem_hd(target, sizeof(s1)-1 + sizeof(s2) + 10);
			puts("\t-------------------------------------------------------------------");
			ft_mem_hd(target2, sizeof(s1)-1 + sizeof(s2) + 10);
		}
		i++;
	}
	free(target);
	return (ret);
}
#endif
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
		{"lolo\x01lol"},
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
			printf("\t'%s' -> %u | %u | %s\n", str[i], strlen(str[i]), ft_strlen(str[i]), just ? OK : KO);
	}
	return (ret);
}

static char tf_strmap(char c)
{
	if (c >= 0x61 && c <= 0x7a)
		c -= 0x20;
	return (c);
}
t_bool t_strmap(int v)
{
	t_bool	ret = TRUE;
	char	orig[] = "aAAaADEFfrefrefer9089078986';'..,";
	char	str[] = "aAAaADEFfrefrefer9089078986';'..,";
	char	res[] = "AAAAADEFFREFREFER9089078986';'..,";

	char	*ress = ft_strmap(str, tf_strmap);
	if (memcmp(ress, res, sizeof(str)) || ress == str || strcmp(orig, str))
		ret = FALSE;
	if (v)
	{
		ft_mem_hd(res, sizeof(str));
		puts("\t-------------------------------------------------------------------");
		puts("\tress = ");
		ft_mem_hd(ress, sizeof(str));
		puts("\t-------------------------------------------------------------------");
		puts("\tstr = ");
		ft_mem_hd(str, sizeof(str));
		puts(ret ? OK : KO);
	}
	free(ress);
	return (ret);
}

static char tf_strmapi(unsigned int pos, char c)
{
	return ((char)pos);
}
t_bool t_strmapi(int v)
{
	t_bool	ret = TRUE;
	char	orig[] = {'a', 'b', 'c', 'd', 's', 's', 's', 's', 0x00, 0};
	char	str[] = {'a', 'b', 'c', 'd', 's', 's', 's', 's', 0x00, 0};
	char	res[] = { 0, 1, 2, 3, 4, 5, 6, 7, 0, 0x00,};

	char	*ress = ft_strmapi(str, tf_strmapi);
	if (strcmp(res, ress) || ress == str || strcmp(orig, str))
		ret = FALSE;
	if (v)
	{
		ft_mem_hd(res, sizeof(str));
		puts("\t-------------------------------------------------------------------");
		puts("\tress = ");
		ft_mem_hd(ress, sizeof(str));
		puts("\t-------------------------------------------------------------------");
		puts("\tstr = ");
		ft_mem_hd(str, sizeof(str));
		puts(ret ? OK : KO);
	}
	free(ress);
	return (ret);
}

t_bool t_strncat(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;
	char	s1[9][42] =
	{
		{""},
		{"salut"},
		{""},
		{"wesh"},
		{"bonjour"},
		{"un jour"},
		{"mais pas"},
		{'b', 'o', 'n', 'j', 'o', 'u', 'r', 0, 'l', 'o', 'l'},
		{'b', 'o', 'n', 'j', 'o', 'u', 'r', 0}
	};
	char	s2[9][42] =
	{
		{""},
		{""},
		{"salut"},
		{" wesh yo"},
		{" les petits"},
		{"je serai le meilleur"},
		{"bonjoure"},
		{' ' , 'b', 'o', 'n', 'j', 'o', 'u', 'r', 0, 'n', 'o', 'n'},
		{ 0, 'n', 'o', 'n'}
	};
	t_uint	i = 0;
	t_uint	n[9] = { 43, 69, 43, 0, 2, 1, 7, 120, 15};
	char	ress[120];
	char	ress2[120];

	for (i = 0; i < 9; ++i)
	{
		just = TRUE;
		bzero(ress, 120);
		bzero(ress2, 120);
		strncat(s1[i], s2[i], n[i]);
		ft_strncat(s1[i], s2[i], n[i]);
		if (memcmp(ress, ress2, 119))
		{
			ret = FALSE;
			just = FALSE;
		}
		if (v)
		{
			printf("s1 = '%s' / s2 = '%s' / n = %u\nress = \n", s1[i], s2[i], n[i]);
			ft_mem_hd(ress, sizeof(ress));
			puts("\t-------------------------------------------------------------------\nress2 = ");
			ft_mem_hd(ress2, sizeof(ress));
			puts(just ? OK : KO);
		}
	}

	return (ret);
}

t_bool t_strncmp(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;
	t_uint	i = 0;
	char	s1[8][42] =
	{
		{""},
		{"salut"},
		{""},
		{"wesh"},
		{"lal"},
		{"al"},
		{"bonjourr"},
		{'b', 'o', 'n', 'j', 'o', 'u', 'r', 0, 'l', 'o', 'l'}
	};
	char	s2[8][42] =
	{
		{""},
		{""},
		{"salut"},
		{"wesh"},
		{"lol"},
		{"ol"},
		{"bonjoure"},
		{'b', 'o', 'n', 'j', 'o', 'u', 'r', 0, 'n', 'o', 'n'}
	};
	t_uint	n[8] = { 43, 69, 43, 0, 2, 1, 7, 42 };

	for (i = 0; i < 8; ++i)
	{
		just = TRUE;
		if (strncmp(s1[i], s2[i], n[i]) != ft_strncmp(s1[i], s2[i], n[i]))
		{
			ret = FALSE;
			just = FALSE;
		}
		if (v)
			printf("s1 = '%s' / s2 = '%s' / n = %u -> %d | %d | %s\n", s1[i], s2[i],
					n[i], strncmp(s1[i], s2[i], n[i]), ft_strncmp(s1[i], s2[i], n[i]), just ? OK : KO);
	}
	return (ret);
}

t_bool t_strncpy(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;
	t_uint	i = 0;
	char	str[8][42] =
	{
		{""},
		{""},
		{"lol"},
		{"bonjour mon petit =)"},
		{"heyheyhey"},
		{"ggergregergergregegergegeg"},
		{"ggergregergergregegergegeg"},
		{'s', 'a', 'l', 'u', 't', 0, 0, 0x42, 0x42, 'l', 'o', 'l' }
	};
	t_uint	n[8] = { 120, 0, 70, 7, 90, 5, 0, 10};
	char	ress[120];
	char	ress2[120];

	for (i = 0; i < 8; ++i)
	{
		just = TRUE;
		bzero(ress, 120);
		bzero(ress2, 120);
		strncpy(ress, str[i], n[i]);
		ft_strncpy(ress2, str[i], n[i]);
		if (memcmp(ress, ress2, 119))
		{
			just = FALSE;
			ret = FALSE;
		}
		if (v)
		{
			printf("str = '%s' / n = %u\nress = \n", str[i], n[i]);
			ft_mem_hd(ress, sizeof(ress));
			puts("\t-------------------------------------------------------------------\nress2 = ");
			ft_mem_hd(ress2, sizeof(ress));
			puts(just ? OK : KO);
		}

	}
	return (ret);
}

t_bool t_strnequ(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;
	t_uint	i= 0;
	int		val = 0;
	char	s1[8][42] =
	{
		{""},
		{"salut"},
		{""},
		{"wesh"},
		{"lal"},
		{"al"},
		{"bonjourr"},
		{'b', 'o', 'n', 'j', 'o', 'u', 'r', 0, 'l', 'o', 'l'}
	};
	char	s2[8][42] =
	{
		{""},
		{""},
		{"salut"},
		{"wesh"},
		{"lol"},
		{"ol"},
		{"bonjoure"},
		{'b', 'o', 'n', 'j', 'o', 'u', 'r', 0, 'n', 'o', 'n'}
	};
	t_uint	n[8] = { 43, 69, 43, 0, 2, 1, 7, 42 };

	for (i = 0; i < 8; ++i)
	{
		just = TRUE;
		val = strncmp(s1[i], s2[i], n[i]) ? 0 : 1;
		if (val != ft_strnequ(s1[i], s2[i], n[i]))
		{
			ret = FALSE;
			just = FALSE;
		}
		if (v)
			printf("s1 = '%s' / s2 = '%s' / n = %u -> %d | %d | %s\n", s1[i], s2[i],
					n[i], val, ft_strncmp(s1[i], s2[i], n[i]), just ? OK : KO);
	}
	return (ret);
}

t_bool t_strnew(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;
	void	*p1 = malloc(143),
			*p2 = ft_strnew(142);

	bzero(p1, 143);
	if (memcmp(p1, p2, 143))
	{
		ret = FALSE;
		just = FALSE;
	}
	if (v)
	{
		ft_mem_hd(p1, 143);
		puts("\t-------------------------------------------------------------------");
		ft_mem_hd(p2, 143);
		puts(just ? OK : KO);
	}
	free(p1);
	free(p2);

	just = TRUE;
	p1 = malloc(1),
	p2 = ft_strnew(0);
	bzero(p1, 1);
	if (memcmp(p1, p2, 1))
	{
		ret = FALSE;
		just = FALSE;
	}
	if (v)
	{
		ft_mem_hd(p1, 1);
		puts("\t-------------------------------------------------------------------");
		ft_mem_hd(p2, 1);
		puts(just ? OK : KO);
	}
	free(p1);
	free(p2);
	return (ret);
}
#ifndef linux
t_bool t_strnstr(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;
	char	s1[10] = "un deux 3";
	char	test[11][20] = {
		{"deux"},
		{"3"},
		{""},
		{"deux"},
		{"3"},
		{"cinq"},
		{"deux"},
		{"342"},
		{"3"},
		{"deux"},
		{""}
	};
	t_uint	testn[11] = {10, 3, 6, 5, 10, 10, 10, 10, 10, 10, 0};
	t_uint	i = 0;
	if (v)
		printf("\ts1 -> '%s' (%p)\n", s1, s1);
	for (i = 0; i < 11; ++i)
	{
		just = TRUE;
		if (i == 4)
		{
			s1[9] = '4';
			if (v)
				printf("\ts1 -> '%s' (%p)\n", s1, s1);
		}
		if (i == 8)
		{
			s1[1] = 0;
			if (v)
				printf("\ts1 -> '%s' (%p)\n", s1, s1);
		}
		if (i == 10)
		{
			s1[0] = 0;
			if (v)
				printf("\ts1 -> '%s' (%p)\n", s1, s1);
		}
		if (strnstr(s1, test[i], testn[i]) != ft_strnstr(s1, test[i], testn[i]))
		{
			ret = FALSE;
			just = FALSE;
		}
		if (v)
			printf("\ts2 = '%s' / n = %d -> %p | %p | %s\n", test[i], testn[i],
				strnstr(s1, test[i], testn[i]), ft_strnstr(s1, test[i], testn[i]),
				just ? OK : KO);
	}
	return (ret);
}
#endif

t_bool t_strrchr(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;
	char	str[] = "abcdefghiabche\x9fzefezhkjacsbm";
	char	c[9] = { 'a', 'w', 0x90, 0, 'b', 'm', 'e', 'q', 't' };
	t_uint	i = 0;

	for (i = 0; i < 9; ++i)
	{
		just = TRUE;
		if (strrchr(str, c[i]) != ft_strrchr(str, c[i]))
		{
			just = FALSE;
			ret = FALSE;
		}
		if (v)
			printf("\tstr = '%s' / c = 0x%02x -> %p | %p | %s\n", str, c[i],
					strrchr(str, c[i]), ft_strrchr(str, c[i]), just ? OK : KO);
	}

	char	s2[] = "";
	just = TRUE;
	if (strrchr(s2, 0) != ft_strrchr(s2, 0))
	{
		just = FALSE;
		ret = FALSE;
	}
	if (v)
		printf("\tstr = '%s' / c = 0x%02x -> %p | %p | %s\n", s2, 0,
				strrchr(s2, 0), ft_strrchr(s2, 0), just ? OK : KO);
	just = TRUE;
	if (strrchr(s2, 'a') != ft_strrchr(s2, 'a'))
	{
		just = FALSE;
		ret = FALSE;
	}
	if (v)
		printf("\tstr = '%s' / c = 0x%02x -> %p | %p | %s\n", s2, 'a',
				strrchr(s2, 'a'), ft_strrchr(s2, 'a'), just ? OK : KO);
	return (ret);
}

t_bool t_strsplit(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;

	char	str[] = "--hel--o-wor---dlld--";
	char	res[5][42] =
	{
		{"hel"},
		{"o"},
		{"wor"},
		{"dlld"},
		{0}
	};
	char	c = '-';
	char	**r = ft_strsplit(str, c);
	t_uint	i = 0;
	for (i = 0; i < 4; ++i)
	{
		just = TRUE;
		if (strcmp(r[i], res[i]))
		{
			just = FALSE;
			ret = FALSE;
		}
		if (v)
			printf("\tstr = '%s' / c = '%c' -> '%s' | '%s' | %s\n", str, c,
					res[i], r[i], just ? OK : KO);
		free(r[i]);
	}
	just = TRUE;
	if (r[i])
	{
		ret = FALSE;
		just = FALSE;
	}
	if (v)
		printf("r[%u] = 0x%08x | 0x%08x | %s\n", i, 0, r[i], just ? OK : KO);
	free(r);
	r = NULL;

	just = TRUE;
	r = ft_strsplit("-------------------", c);
	if (*r)
	{
		just = FALSE;
		ret = FALSE;
	}
	if (v)
		printf("\tstr = '-------------------' / c = '-' r[0] -> '0x%08x' | 0x%08x | %s\n", NULL, *r, just ? OK : KO);
	free(*r);
	free(r);
	r = NULL;

	just = TRUE;
	r = ft_strsplit("saluuuut ", c);
	if (strcmp(*r, "saluuuut "))
	{
		just = FALSE;
		ret = FALSE;
	}
	if (v)
		printf("\tstr = 'saluuuut ' / c = '-' r[0] -> 'saluuuut ' | %s | %s\n", *r, just ? OK : KO);
	just = TRUE;
	if (r[1])
	{
		just = FALSE;
		ret = FALSE;
	}
	if (v)
		printf("\tstr = 'saluuuut ' / c = '-' r[1] -> '0x%08x' | 0x%08x | %s\n", NULL, r[1], just ? OK : KO);
	free(*r);
	free(r);
	return (ret);
}

t_bool t_strstr(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;

	char s1[9][42] =
	{
		{""},
		{""},
		{"salut"},
		{"ma ison nn maiso n maison"},
		{"bonjour =°"},
		{"je suis un petit je lololollolololol"},
		{"yooooooooooooooooooooyoyooyo"},
		{"salut"},
		{"***************************"}
	};
	char s2[9][42] =
	{
		{""},
		{"salut"},
		{""},
		{"maison"},
		{"bonjour =)"},
		{"lol"},
		{"yoo"},
		{"bonjour"},
		{"**"}
	};
	t_uint	i = 0;

	for (i = 0; i < 9; ++i)
	{
		just = TRUE;
		if (strstr(s1[i], s2[i]) != ft_strstr(s1[i], s2[i]))
		{
			ret = FALSE;
			just = FALSE;
		}
		if (v)
			printf("\ts1 = '%s' / s2 = '%s' -> %p | %p | %s\n", s1[i], s2[i],
				strstr(s1[i], s2[i]), ft_strstr(s1[i], s2[i]), just ? OK : KO);
	}
	return (ret);
}

t_bool t_strsub(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;
	char	str[] = "hellow wowld";

	char	*p = ft_strsub(str, 0, 5);
	if (strcmp(p, "hello"))
	{
		just = FALSE;
		ret = FALSE;
	}
	if (v)
		printf("\tft_strsub('%s', %d, %d) -> '%s' | '%s' | %s\n", str,
			0, 5, "hello", p, just ? OK : KO);
	free(p);

	just = TRUE;
	p = ft_strsub(str, 5, 5);
	if (strcmp(p, "w wow"))
	{
		just = FALSE;
		ret = FALSE;
	}
	if (v)
		printf("\tft_strsub('%s', %d, %d) -> '%s' | '%s' | %s\n", str,
				5, 5, "w wow", p, just ? OK : KO);
	free(p);

	just = TRUE;
	p = ft_strsub(str, 0, 0);
	if (strcmp(p, ""))
	{
		just = FALSE;
		ret = FALSE;
	}
	if (v)
		printf("\tft_strsub('%s', %d, %d) -> '%s' | '%s' | %s\n", str,
				0, 0, "", p, just ? OK : KO);
	free(p);
	return (ret);
}

t_bool t_strtrim(int v)
{
	t_bool	ret = TRUE;
	t_bool	just = TRUE;

	char	*res = ft_strtrim("\t\n  \tAAA \t BBB\t\n  \t");
	if (strcmp(res, "AAA \t BBB"))
	{
		ret = FALSE;
		just = FALSE;
	}
	if (v)
		printf("'%s' -> '%s' | '%s' | %s\n", "\t\n  \tAAA \t BBB\t\n  \t",
				 "AAA \t BBB", res, just ? OK : KO);
	free(res);

	just = TRUE;
	res = ft_strtrim("\t\t\n\t\t   ");
	if (strcmp(res, ""))
	{
		ret = FALSE;
		just = FALSE;
	}
	if (v)
		printf("'%s' -> '%s' | '%s' | %s\n", "\t\t\n\t\t   ",
				 "", res, just ? OK : KO);
	free(res);

	just = TRUE;
	res = ft_strtrim("");
	if (strcmp(res, ""))
	{
		ret = FALSE;
		just = FALSE;
	}
	if (v)
		printf("'%s' -> '%s' | '%s' | %s\n", "", "", res, just ? OK : KO);
	free(res);

	just = TRUE;
	res = ft_strtrim("salut =)");
	if (strcmp(res, "salut =)"))
	{
		ret = FALSE;
		just = FALSE;
	}
	if (v)
		printf("'%s' -> '%s' | '%s' | %s\n", "salut =)", "salut =)", res, just ? OK : KO);
	free(res);
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


void	t_putchar(void)
{
	char	c = 0;
	printf("%02x -> %c | ", c, c);
	ft_putchar(c);
	putchar('\n');

	c = 'a';
	printf("%02x -> %c | ", c, c);
	ft_putchar(c);
	putchar('\n');

	c = 0x90;
	printf("%02x -> %c | ", c, c);
	ft_putchar(c);
	putchar('\n');

	c = 0x42;
	printf("%02x -> %c | ", c, c);
	ft_putchar(c);
	putchar('\n');

	c = 0xff;
	printf("%02x -> %c | ", c, c);
	ft_putchar(c);
	putchar('\n');

	c = 0x89;
	printf("%02x -> %c | ", c, c);
	ft_putchar(c);
	putchar('\n');
}

void	t_putnbr(void)
{
	ft_putnbr(0);
	putchar('\n');
	ft_putnbr(4242);
	putchar('\n');
	ft_putnbr(-4242);
	putchar('\n');
	ft_putnbr(INT_MAX);
	putchar('\n');
	ft_putnbr(INT_MIN);
	putchar('\n');
	ft_putnbr(-0);
	putchar('\n');
	ft_putnbr(-1);
	putchar('\n');
}

#define DEBUG 0 // 1
int main(void)
{
	ft_putstr("ft_atoi : ");
	if (!t_atoi(DEBUG)) { puts(KO); t_atoi(1); } else puts(OK);

	ft_putstr("ft_bzero : ");
	if (!t_bzero(DEBUG)) { puts(KO); t_bzero(1); } else puts(OK);

	ft_putstr("ft_isalnum : ");
	if (!t_isalnum(DEBUG)) { puts(KO); t_isalnum(1); } else puts(OK);

	ft_putstr("ft_isalpha : ");
	if (!t_isalpha(DEBUG)) { puts(KO); t_isalpha(1); } else puts(OK);

	ft_putstr("ft_isascii : ");
	if (!t_isascii(DEBUG)) { puts(KO); t_isascii(1); } else puts(OK);

	ft_putstr("ft_isdigit : ");
	if (!t_isdigit(DEBUG)) { puts(KO); t_isdigit(1); } else puts(OK);

	ft_putstr("ft_isprint : ");
	if (!t_isprint(DEBUG)) { puts(KO); t_isprint(1); } else puts(OK);

	ft_putstr("ft_itoa : ");
	if (!t_itoa(DEBUG)) { puts(KO); t_itoa(1); } else puts(OK);

	ft_putstr("ft_memalloc : ");
	if (!t_memalloc(DEBUG)) { puts(KO); t_memalloc(1); } else puts(OK);

	ft_putstr("ft_memccpy : ");
	if (!t_memccpy(DEBUG)) { puts(KO); t_memccpy(1); } else puts(OK);

	ft_putstr("ft_memchr : ");
	if (!t_memchr(DEBUG)) { puts(KO); t_memchr(1); } else puts(OK);

	ft_putstr("ft_memcmp : ");
	if (!t_memcmp(DEBUG)) { puts(KO); t_memcmp(1); } else puts(OK);

	ft_putstr("ft_memcpy : ");
	if (!t_memcpy(DEBUG)) { puts(KO); t_memcpy(1); } else puts(OK);

	ft_putstr("ft_memdel : ");
	if (!t_memdel(DEBUG)) { puts(KO); t_memdel(1); } else puts(OK);

	ft_putstr("ft_memmove : ");
	if (!t_memmove(DEBUG)) { puts(KO); t_memmove(1); } else puts(OK);

	ft_putstr("ft_memset : ");
	if (!t_memset(DEBUG)) { puts(KO); t_memset(1); } else puts(OK);

	ft_putstr("ft_strcat : ");
	if (!t_strcat(DEBUG)) { puts(KO); t_strcat(1); } else puts(OK);

	ft_putstr("ft_strchr : ");
	if (!t_strchr(DEBUG)) { puts(KO); t_strchr(1); } else puts(OK);

	ft_putstr("ft_strclr : ");
	if (!t_strclr(DEBUG)) { puts(KO); t_strclr(1); } else puts(OK);

	ft_putstr("ft_strcmp : ");
	if (!t_strcmp(DEBUG)) { puts(KO); t_strcmp(1); } else puts(OK);

	ft_putstr("ft_strcpy : ");
	if (!t_strcpy(DEBUG)) { puts(KO); t_strcpy(1); } else puts(OK);

	ft_putstr("ft_strdel : ");
	if (!t_strdel(DEBUG)) { puts(KO); t_strdel(1); } else puts(OK);

	ft_putstr("ft_strdup : ");
	if (!t_strdup(DEBUG)) { puts(KO); t_strdup(1); } else puts(OK);

	ft_putstr("ft_strequ : ");
	if (!t_strequ(DEBUG)) { puts(KO); t_strequ(1); } else puts(OK);

	ft_putstr("ft_striter : ");
	if (!t_striter(DEBUG)) { puts(KO); t_striter(1); } else puts(OK);

	ft_putstr("ft_striteri : ");
	if (!t_striteri(DEBUG)) { puts(KO); t_striteri(1); } else puts(OK);

	ft_putstr("ft_strjoin : ");
	if (!t_strjoin(DEBUG)) { puts(KO); t_strjoin(1); } else puts(OK);
#ifndef linux
	ft_putstr("ft_strlcat : ");
	if (!t_strlcat(DEBUG)) { puts(KO); t_strlcat(1); } else puts(OK);
#endif
	ft_putstr("ft_strlen : ");
	if (!t_strlen(DEBUG)) { puts(KO); t_strlen(1); } else puts(OK);

	ft_putstr("ft_strmap : ");
	if (!t_strmap(DEBUG)) { puts(KO); t_strmap(1); } else puts(OK);

	ft_putstr("ft_strmapi : ");
	if (!t_strmapi(DEBUG)) { puts(KO); t_strmapi(1); } else puts(OK);

	ft_putstr("ft_strncat : ");
	if (!t_strncat(DEBUG)) { puts(KO); t_strncat(1); } else puts(OK);

	ft_putstr("ft_strncmp : ");
	if (!t_strncmp(DEBUG)) { puts(KO); t_strncmp(1); } else puts(OK);

	ft_putstr("ft_strncpy : ");
	if (!t_strncpy(DEBUG)) { puts(KO); t_strncpy(1); } else puts(OK);

	ft_putstr("ft_strnequ : ");
	if (!t_strnequ(DEBUG)) { puts(KO); t_strnequ(1); } else puts(OK);

	ft_putstr("ft_strnew : ");
	if (!t_strnew(DEBUG)) { puts(KO); t_strnew(1); } else puts(OK);
#ifndef linux
	ft_putstr("ft_strnstr : ");
	if (!t_strnstr(DEBUG)) { puts(KO); t_strnstr(1); } else puts(OK);
#endif
	ft_putstr("ft_strrchr : ");
	if (!t_strrchr(DEBUG)) { puts(KO); t_strrchr(1); } else puts(OK);

	ft_putstr("ft_strsplit : ");
	if (!t_strsplit(DEBUG)) { puts(KO); t_strsplit(1); } else puts(OK);

	ft_putstr("ft_strstr : ");
	if (!t_strstr(DEBUG)) { puts(KO); t_strstr(1); } else puts(OK);

	ft_putstr("ft_strsub : ");
	if (!t_strsub(DEBUG)) { puts(KO); t_strsub(1); } else puts(OK);

	ft_putstr("ft_strtrim: ");
	if (!t_strtrim(DEBUG)) { puts(KO); t_strtrim(1); } else puts(OK);

	ft_putstr("ft_tolower : ");
	if (!t_tolower(DEBUG)) { puts(KO); t_tolower(1); } else puts(OK);

	ft_putstr("ft_toupper : ");
	if (!t_toupper(DEBUG)) { puts(KO); t_toupper(1); } else puts(OK);

	puts("===================================================================");
	puts("ft_putchar : ");t_putchar();

	puts("ft_putnbr : ");t_putnbr();

# ifdef SKERKOUR_LIBFT
	t_ftbuffer *lol = ft_buffer_new("lol", 4);
	t_ftbuffer *loll = ft_buffer_new("loll", 5);
	t_ftstack	*st = ft_stack_init();
	st->push(&st, lol);
	st->push(&st, loll);
	puts((st->pop(&st))->data);
	puts((st->pop(&st))->data);
	st->destroy(&st);
# endif

	return (0);
}
