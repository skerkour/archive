/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 20:28:55 by skerkour          #+#    #+#             */
/*   Updated: 2015/01/04 18:15:20 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "priv_ft_printf.h"
#include "libft.h"

int		ft_is_in_array(char *str, char **array)
{
	while (*array)
	{
		if (!ft_strcmp(str, *array))
			return (1);
		++array;
	}
	return (0);
}

int ptf_srch_token(char *format, int *token_size)
{
	char	flags[] = "#0-+ ";
	char	larg_lin[] = "0123456789";
	char	preci[] = ".0123456789";
	//char	size_mod[][] = {"hh", "h", "l", "ll", "j", "z"};
	char	conv[] = "sSpdDioOuUxXcC";

	*token_size = 1;
	++format;
	while (*format &&  ft_strchr(flags, *format))
		++format, ++(*token_size);
	while (*format &&  ft_strchr(larg_lin, *format))
		++format, ++(*token_size);
	while (*format &&  ft_strchr(preci, *format))
		++format, ++(*token_size);
	if (*format && ft_strchr(conv, *format))
	{
		++(*token_size);
		return (1);
	}
	return (0);
}

int		ft_printf(const char *format, ...)
{
	unsigned int	nargs;
	int				ret;
	va_list			args;

	if (format)
	{
		ret = 0;
		//ftptf_get_tokens(format, &nargs);
		va_start(args, format);
		(void)(nargs);
		//ret = ftptf_display(format, nargs, args)
		va_end(args);
	}
	ret = 0;
	char	*str = (char*)format;
	int		token_size = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '%' && *(str - 1) != '%')
		{
			if (ptf_srch_token(str, &token_size))
			{
				ft_putstr("token size = "), ft_putnbr(token_size), ft_putstr(" -> ");
				while (token_size-- > 0)
					ft_putchar(*str++);
				ft_putchar('\n');
			}
			else
				++str;
		}
		else
			++str;
	//	else
	//		ft_putchar(*str);
	}
	return (ret);
}
