/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_bitch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 23:06:22 by agifford          #+#    #+#             */
/*   Updated: 2018/05/29 13:16:07 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
				if (((TET_X + env->col > env->min_board) &&
						(TET_Y + env->row > env->min_board)) ||
						ft_isalpha(env->board[env->row + TET_Y][env->col + TET_X]))
					return (0);
			}
			TET_X++;
		}
		TET_Y++;
	}
	return (1);
}	

int	put_piece(t_env *env) 
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
	return (1);
}	

void	 animal_style(t_env	*env)
{	
	env->col = 0;
	while (env->col < env->min_board)
	{
		if (!ft_isalpha(env->board[env->row][env->col]) && env->cur_tet < env->num_tets ) //add isalpha over '.'
		{
			if (can_put_piece(env))	
				put_piece(env);
			else
				env->col++;
		}
		else
			return;
				
				print_working_area(env);
				ft_putchar('\n');
			}

		}
}	

int	fuck_with_it(t_env	*env)
{
	env->row = 0;
	while (env->row < env->min_board)
	{
		animal_style(env);
		/*
		** took away -1 from conditional and moved env->cur_tet up two lines
		*/
env->row++;
	}
	return (1);
}

int	double_fuck(t_env *env)
{
	while (fuck_with_it(env) == 0)
	{
		if (env->min_board == 11)
			return (0);
		env->min_board++;
	}
	return (1);
}
