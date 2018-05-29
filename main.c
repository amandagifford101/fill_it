/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 23:14:16 by agifford          #+#    #+#             */
/*   Updated: 2018/05/29 13:30:26 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_tet	**tet;
	t_env	*env;
	char	*dest = ft_strnew(0);
	char	content[22];
	int		fd;
	
	(void)argc;
	fd = open(argv[1], O_RDONLY);
	ft_bzero(content, 22);
	while (read(fd, content, 22) != 0)
	{
		dest = ft_strjoin(dest, content); 
		ft_bzero(content, 22);
	}
	tet = validate(dest);
	env = init_env(tet);
	backtrack_main(env);
	print_working_area(env);
	return (1);
}
