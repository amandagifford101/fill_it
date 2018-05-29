 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 19:00:11 by agifford          #+#    #+#             */
/*   Updated: 2018/05/29 14:55:21 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# define I {{'#','.','.','.'},{'#','.','.','.',},{'#','.','.','.'},X0
# define X0 {'#','.','.','.'}}
# define O {{'#','#','.','.'},{'#','#','.','.'},{'.','.','.','.'},X1
# define X1 {'.','.','.','.'}}
# define L {{'#','.','.','.'},{'#','.','.','.'},{'#','#','.','.'},X2
# define X2 {'.','.','.','.'}}
# define J {{'.','#','.','.'},{'.','#','.','.'},{'#','#','.','.'},X3
# define X3 {'.','.','.','.'}}
# define FLAT {{'#','#','#','#'},{'.','.','.','.'},{'.','.','.','.'},X4
# define X4 {'.','.','.','.'}}
# define L_180 {{'#','#','.','.'},{'.','#','.','.'},{'.','#','.','.'},X5
# define X5 {'.','.','.','.'}}
# define RIGHT_L {{'#','#','#','.'},{'#','.','.','.'},{'.','.','.','.'},X6
# define X6 {'.','.','.','.'}}
# define LEFT_L {{'.','.','#','.'},{'#','#','#','.'},{'.','.','.','.'},X7
# define X7 {'.','.','.','.'}}
# define J_180 {{'#','#','.','.'},{'#','.','.','.'},{'#','.','.','.'},X8
# define X8 {'.','.','.','.'}}
# define RIGHT_J {{'#','.','.','.'},{'#','#','#','.'},{'.','.','.','.'},X9
# define X9 {'.','.','.','.'}}
# define LEFT_J {{'#','#','#','.'},{'.','.','#','.'},{'.','.','.','.'},X10
# define X10 {'.','.','.','.'}}
# define LEFT_S {{'#','.','.','.'},{'#','#','.','.'},{'.','#','.','.'},X11
# define X11 {'.','.','.','.'}}
# define S {{'.','#','#','.'},{'#','#','.','.'},{'.','.','.','.'},X12
# define X12 {'.','.','.','.'}}
# define RIGHT_Z {{'.','#','.','.'},{'#','#','.','.'},{'#','.','.','.'},X13
# define X13 {'.','.','.','.'}}
# define Z {{'#','#','.','.'},{'.','#','#','.'},{'.','.','.','.'},X14
# define X14 {'.','.','.','.'}}
# define T_180 {{'.','#','.','.'},{'#','#','#','.'},{'.','.','.','.'},X15
# define X15 {'.','.','.','.'}}
# define LEFT_T {{'.','#','.','.'},{'#','#','.','.'},{'.','#','.','.'},X16
# define X16 {'.','.','.','.'}}
# define RIGHT_T {{'#','.','.','.'},{'#','#','.','.'},{'#','.','.','.'},X17
# define X17 {'.','.','.','.'}}
# define T {{'#','#','#','.'},{'.','#','.','.'},{'.','.','.','.'},X18
# define X18 {'.','.','.','.'}}
# define STACKARR {I, O, L, J, FLAT, L_180, RIGHT_L, LEFT_L, J_180, RIGHT_J,X19
# define X19 LEFT_J, LEFT_S, S, RIGHT_Z, Z, T_180, LEFT_T, RIGHT_T, T}
# define SUPERMAC	char	y[19][4][4] = STACKARR
# define TET_X	env->tets[env->cur_tet]->x
# define TET_Y	env->tets[env->cur_tet]->y
# define TET	env->tets[env->cur_tet]->tet[TET_Y][TET_X]

typedef struct				s_global_list {
	void					*piecearr;
	struct s_global_list	*next;
	struct s_global_list	*prev;
}							t_arr_list;

typedef	struct				s_tet
{
	char					**tet;
	int						x;
	int						y;
}							t_tet;

typedef	struct				s_env
{
	char					**board;
	int						min_board;
	int						row;
	int						col;
	int						num_tets;
	int						cur_tet;

	t_tet					**tets;
}							t_env;



static t_arr_list			*g_valid_pieces;

t_arr_list					*init_global();
void						print_piecearr(t_arr_list *node);
void						list_add(t_arr_list *head, void *data);
t_arr_list					*new_node(void *data);

int							can_put_piece(t_env *env);

void						put_piece(t_env *env);

void						remove_piece(t_env *env);

int							animal_style(t_env *env);

int							backtrack_main(t_env *env);

t_env						*init_env(t_tet **tets);

t_tet						*init_tet(char **tet);

void						print_board(t_env *env);

void						print_working_area(t_env *env);

t_tet						**validate(char *file);

void						clear_board(t_env *env);
#endif

