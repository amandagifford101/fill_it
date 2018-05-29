/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:25:21 by agifford          #+#    #+#             */
/*   Updated: 2018/05/29 15:25:33 by agifford         ###   ########.fr       */
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

	
int	can_put_piece(t_env *env)
{
	TET_Y = 0;
	while (TET_Y < 4)
	{
		TET_X = 0;
		while (TET_X < 4)
		{
			if (TET == '#')
			{
				if (((TET_X + env->col > env->min_board) && (TET_Y + env->row > env->min_board)) ||
					   	ft_isalpha(env->board[env->row + TET_Y][env->col + TET_X]))
					return (0);
			}
			TET_X++;
		}
		TET_Y++;
	}
	return (1);
}

void	put_piece(t_env *env)
{
	TET_Y = 0;
	while (TET_Y < 4)
	{
		TET_X = 0;
		while (TET_X < 4)
		{
			if (TET == '#')
			{
				env->board[env->row + TET_Y][env->col + TET_X] =
					env->cur_tet + 'A';
				print_working_area(env);
				ft_putchar('\n');
			}
			TET_X++;
		}
		TET_Y++;
	}
}

int	animal_style(t_env *env)
{
	env->row = 0;
	while (env->row < env->min_board)
	{
		env->col = 0;
		while (env->col < env->min_board)
		{
			if (can_put_piece(env))	
			{
				put_piece(env);
				env->cur_tet++;
				if (env->cur_tet > env->num_tets)
					return (1);
				animal_style(env);
			}
			env->col++;
		}
		env->row++;
	}
	return (0);
}	

int	backtrack_main(t_env *env)
{
	while (!(animal_style(env)))
	{
		if (env->min_board == 11)
			return (0);
		env->min_board++;
		clear_board(env);
	}
	return (1);
}
