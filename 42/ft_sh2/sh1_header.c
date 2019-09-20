/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 14:45:51 by skerkour          #+#    #+#             */
/*   Updated: 2015/01/04 15:35:08 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pwd.h>
#include <unistd.h>
#include <stdlib.h>

#include "ft_sh1.h"

char	*sh1_getuname(void)
{
	register struct passwd	*pw;
	register uid_t			uid;

	uid = geteuid();
	pw = getpwuid(uid);
	if (pw)
		return (ft_strdup(pw->pw_name));
	else
		return (ft_itoa(uid));
}

char	*sh1_gethname(void)
{
	char	*ret;

	ret = (char*)ft_xmalloc(255);
	*ret = 0;
	gethostname(ret, 255);
	return (ret);
}

char	*get_rel_from_abs(char *abs, char *rel)
{
	char	*pos;

	if (rel && (pos = ft_strstr(abs, rel)))
	{
		abs[0] = '~';
		abs[1] = 0;
		ft_strcat(abs, pos + ft_strlen(rel));
	}
	return (abs);
}

char	*sh1_getcwd(char **env, char *home)
{
	char	*ret;

	UNUSED(env);
	ret = (char*)ft_memalloc(1024);
	*ret = 0;
	getcwd(ret, 1024);
	ret = get_rel_from_abs(ret, home);
	return (ret);
}

char	*sh1_get_header(char **env)
{
	char	*ret;
	char	*uname;
	char	*hname;
	char	*path;
	char	*home;

	if ((ret = (char*)malloc(1 + 32 + 1 + 255 + 1 + 1024 + 2)) == NULL)
		return (NULL);
	home = sh1_getenv(env, "HOME");
	uname = sh1_getuname();
	hname = sh1_gethname();
	path = sh1_getcwd(env, home);
	ret[0] = '[';
	ret[1] = 0;
	ft_strcat(ret, uname);
	ft_strcat(ret, "@");
	ft_strcat(ret, hname);
	ft_strcat(ret, ":");
	if (path)
		ft_strcat(ret, path);
	ft_strcat(ret, "]$ ");
	free(uname), free(hname), free(path);
	return (ret);
}
