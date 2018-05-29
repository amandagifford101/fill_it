/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 22:58:40 by agifford          #+#    #+#             */
/*   Updated: 2018/05/26 19:48:14 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_board(t_env *env)
{
	int	i;
	
	i = 0;
	while (i < 11)
	{
		ft_putstr(env->board[i]);
		i++;
	}
}

void	print_working_area(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (i < env->min_board)
	{
		j = 0;
		while (j < env->min_board)
		{
			ft_putchar(env->board[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
