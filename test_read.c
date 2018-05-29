/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 18:08:33 by agifford          #+#    #+#             */
/*   Updated: 2018/05/16 18:49:00 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int		fd;
	char	*buf;
	
	fd = 0;
	if (argc < 2 )
		return (0);
	buf = (char*)malloc(sizeof(char) * 21);
	fd = open(argv[1], O_RDONLY);
	read(fd, buf, 21);
	printf("%s", buf);
	return (0);
}

