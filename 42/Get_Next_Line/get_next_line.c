/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 17:43:16 by skerkour          #+#    #+#             */
/*   Updated: 2014/11/27 14:30:17 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <unistd.h>

#include "get_next_line.h"
#include "libft.h"

static char	*ft_strjoinmod(char *s1, char *s2)
{
	char	*ret;

	ret = NULL;
	if (s1 && s2)
	{
		if ((ret = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)) == NULL)
			return (NULL);
		ft_strcpy(ret, s1);
		ft_strcat(ret, s2);
		free((char*)s1);
	}
	return (ret);
}

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
			*line = ft_strjoinmod(*line, *buf);
			ft_strcpy(*buf, pos + 1);
		}
		else
		{
			(*buf)[ret] = ret ? 0 : (*buf)[ret];
			*line = ft_strjoinmod(*line, *buf);
			(*buf)[0] = 0;
		}
	}
	return (*line ? 1 : -1);
}

int			get_next_line(int const fd, char **line)
{
	static char	*buf;
	int			ret;
	char		*pos;

	if (BUFF_SIZE < 1 || !line)
		return (-1);
	if (!buf)
		if ((buf = (char*)malloc(BUFF_SIZE + 1)) == NULL
				&& !(*buf = 0))
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
