/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:12:53 by skerkour          #+#    #+#             */
/*   Updated: 2014/12/01 17:12:55 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <unistd.h>

#include "libft.h"

static int	ft_gnl_cut(int fd, char **line, char **buf, char *pos)
{
	int		ret;

	*line = ft_strdup(*buf);
	while (!pos)
	{
		if ((ret = read(fd, *buf, BUFF_SIZE)) < 0)
			return (-1);
		if ((pos = ft_strchr(*buf, '\n')) == NULL && !ret)
			return ((*buf)[0] = 0);
		else if (pos)
		{
			(*buf)[ret] = ret ? 0 : (*buf)[ret];
			pos[0] = 0;
			*line = ft_strjoinf(*line, *buf);
			ft_strcpy(*buf, pos + 1);
		}
		else
		{
			(*buf)[ret] = ret ? 0 : (*buf)[ret];
			*line = ft_strjoinf(*line, *buf);
			(*buf)[0] = 0;
		}
	}
	return (*line ? 1 : -1);
}

int			ft_gnl(int const fd, char **line)
{
	static char	*buf;
	int			ret;
	char		*pos;

	if (BUFF_SIZE < 1 || !line)
		return (-1);
	if (!buf)
		if ((buf = (char*)malloc(BUFF_SIZE + 1)) == NULL
				&& (*buf = 0))
			return (-1);
	pos = ft_strchr(buf, '\n');
	if (pos)
	{
		pos[0] = 0;
		*line = ft_strdup(buf);
		ft_strcpy(buf, pos + 1);
		return (*line ? 1 : -1);
	}
	else
		ret = ft_gnl_cut(fd, line, &buf, NULL);
	if (ret == 0 && ft_strlen(*line) == 0)
		free(buf);
	if (ret == -1)
		return (-1);
	return (ret ? 1 : ft_strlen(*line) != 0);
}
