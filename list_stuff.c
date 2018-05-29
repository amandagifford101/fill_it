#include "fillit.h"

t_arr_list	*new_node(void *data)
{
	t_arr_list *ret;

	ret = (t_arr_list*)ft_memalloc(sizeof(t_arr_list));
	ret->next = ret;
	ret->prev = ret;
	ret->piecearr = data;
	return (ret);
}

void		list_add(t_arr_list *head, void *data)
{
	t_arr_list *left;
	t_arr_list *insert;

	left = head->prev;
	insert = new_node(data);
	insert->prev = left;
	insert->next = head;
	left->next = insert;
	head->prev = insert;
}

void		print_piecearr(t_arr_list *node)
{
	int i;
	int j;

	i = 0;
	j = 0;

	if (!node->piecearr)
		return ;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			//printf("%c", ((char**)node->piecearr)[j][i]);
			//remove printf or this function it's just for printing out the 2d array in the node
			i++;
		}
		j++;
//		printf("\n");
	}
}

char		**unstack_em(char arr[19][4][4], int i)
{
	char	**ret;
	int		x;
	int		y;

	x = 0;
	y = 0;
	ret = (char**)ft_memalloc((sizeof(char*) * 4));
	while (y < 4)
	{
		ret[y] = (char*)ft_memalloc(sizeof(char) * 4);
		while (x < 4)
		{
			ret[y][x] = arr[i][y][x];
			x++;
		}
		y++;
		x = 0;
	}
	return (ret);
}

t_arr_list *init_global(void)
{
	int		i;

	SUPERMAC;
	i = 0;
	g_valid_pieces = new_node(NULL);
	while (i < 19)
		list_add(g_valid_pieces, unstack_em(y, i++));
        return g_valid_pieces;
}

//testing main please ignore
/* int main() { */
/*	 t_arr_list *temp; */
/*	 init_global(); */
/*	 temp = g_valid_pieces->next; */
/*	 while ((unsigned int)temp->piecearr) { */
/*	   print_piecearr(temp); */
/*	   printf("\n"); */
/*	   temp = temp->next; */
/*	 } */
/* } */
