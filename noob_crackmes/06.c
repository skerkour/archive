/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 10:47:51 by skerkour          #+#    #+#             */
/*   Updated: 2014/12/03 11:27:35 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/uio.h>
#include <sys/types.h>

void	scratch_pass(char *str)
{
	char	i = 0;

	while (*str)
		*str++ ^= 0x42 + i++;
}

int main(void)
{
	char			pass[] = "vq+))+|{%\\'#!";
	int				fd;
	unsigned int	rand = 0;
	unsigned int	rep;

	if ((fd = open("/dev/random", O_RDONLY)) < 0)
		exit(1);
	read(fd, &rand, sizeof(unsigned int));
	close(fd);
	puts("please enter the password : ");
	scanf("%u", &rep);
	if ((fd = open(".tmppass", O_RDWR | O_CREAT | O_TRUNC)) < 0)
		exit(1);
	write(fd, &rand, sizeof(unsigned int));
	close(fd);
	usleep(100);
	unlink(".tmppass");
	if (rep == rand)
	{
		scratch_pass(pass);
		printf("GG, the secret is :\n%s\n", pass);
	}
	else
		puts("try again");
	return (0);
}
