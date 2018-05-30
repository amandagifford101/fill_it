/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deletions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:55:20 by agifford          #+#    #+#             */
/*   Updated: 2018/05/29 21:15:31 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	remove_piece(t_env *env)
{
	int	y;
	int	x;

	y = 0;
	while (y < env->min_board)
	{
		x = 0;
		while (x < env->min_board)
		{
			if (env->board[y][x] == env->cur_tet + 'A')
				env->board[y][x] = '.';
			x++;
		}
		y++;
	}
	env->cur_tet++;
}

void	clear_board(t_env *env)
{
	int	y;
	int	x;

	y = 0;
	while (y < env->min_board)
	{
		x = 0;
		while (x < env->min_board)
		{
			if (env->board[y][x] >= 'A' && env->board[y][x] <= 'Z')
				env->board[y][x] = '.';
			x++;
		}
		y++;
	}
	env->cur_tet++;
}
