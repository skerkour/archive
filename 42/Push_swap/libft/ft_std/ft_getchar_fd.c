/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 18:11:07 by skerkour          #+#    #+#             */
/*   Updated: 2014/12/08 18:21:53 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#include "libft.h"

char	ft_getchar_fd(int fd)
{
	char	ret;

	read(fd, &ret, 1);
	return (ret);
}
