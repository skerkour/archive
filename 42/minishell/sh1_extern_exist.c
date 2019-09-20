/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1_extern_exist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 20:47:30 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/11 20:50:27 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_sh1.h"

int		sh1_extern_exist(char *cmd, char **env)
{
	char	*path;

	if ((path = sh1_search_cmd_path(cmd, env)) == NULL)
		return (0);
	free(path);
	return (1);
}
