/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 15:00:25 by agifford          #+#    #+#             */
/*   Updated: 2018/05/29 18:43:48 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_env	*init_env(t_tet **tets)
{
	t_env	*env;
	int		i;

	i = 0;
	env = ft_memalloc(sizeof(*env));
	env->tets = tets;
	env->row = 0;
	env->col = 0;
	env->cur_tet = 0;
	while (tets[i] != NULL)
		i++;
	env->num_tets = i;
	i = 0;
	while (i * i < env->num_tets * 4)
		i++;
	env->min_board = i;
	env->board = ft_memalloc(sizeof(char*) * 12);
	i = 0;
	while (i < 12)
	{
		env->board[i] = ft_memalloc(sizeof(char) * 12);
		ft_memset(env->board[i], '.', 11);
		i++;
	}
	return (env);
}

t_tet	*init_tet(char **tet)
{
	t_tet	*tet_ptr;

	tet_ptr = ft_memalloc(sizeof(t_tet));
	tet_ptr->x = 0;
	tet_ptr->y = 0;
	tet_ptr->tet = tet;
	return (tet_ptr);
}
