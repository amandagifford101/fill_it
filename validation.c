/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 16:39:50 by agifford          #+#    #+#             */
/*   Updated: 2018/05/26 19:43:55 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** expects a 4x4 malloced piece with at least one '#'
**
** returns the row index of the topmost '#'
*/

int get_top(char **piece)
{
  int x = 0;
  int y = 0;
  while (y < 4) {
    x = 0;
    while (x < 4 && piece[y][x] != '#') {
      if (piece[y][x] == '#')
        break;
      x++;
    }
    if (piece[y][x] == '#')
      break;
    y++;
  }
  return(y);
}

/*
** expects a 4x4 malloced piece with at least one '#'
**
** returns the column index of the leftmost '#'
*/
int get_left(char **piece)
{
  int y = 0;
  int x = 0;
  while (x < 4) {
    y = 0;
    while (y < 4 && piece[y][x] != '#') {
      if (piece[y][x] == '#')
        break;
      y++;
    }
    if (y < 4 && piece[y][x] == '#')
      break;
    x++;
  }
  return(x);
}

/*
** struct for keeping track of where I need to start looking for '#'s with top and left
** and also keep track of whatever '#' to check in the valid pieces
*/
typedef struct s_tracker {
  char** candidate;
  int top;
  int left;
  int y_hash;
  int x_hash;
} t_tracker;

/*
** expects a malloced 4x4 tetrimino piece
**
** returns a pointer to an initialized tracker struct
*/
t_tracker *construct_tracker(char **read_piece)
{
  t_tracker *ret;

  ret = (t_tracker*)ft_memalloc(sizeof(t_tracker));
  ret->candidate = read_piece;
  ret->top = get_top(read_piece);
  ret->left = get_left(read_piece);
  ret->y_hash = ret->top;
  ret->x_hash = ret->left;
  return (ret);
}

/*
** expects a non-NULL tracker and >0 hash_count
**
** stores the position of the hash in the tracker that was passed in
**
** returns nothing, only side effects
**
** example:
**           ....              ....
** the piece ..## would have   ..12
**           .##. hash numbers .34.
**           ....              ....
**
** so hash_count = 1 would set the position y_hash = 1 and x_hash = 2
*/
void set_hash_pos(t_tracker *read_piece, int hash_count)
{
  int x_offset;
  int y_offset;

  x_offset = read_piece->left;
  y_offset = read_piece->top;
  while (y_offset < 4){
    while (x_offset < 4){
      if (read_piece->candidate[y_offset][x_offset] == '#')
        hash_count--;
      if (!hash_count)
        break;
      x_offset++;
    }
    if (!hash_count)
      break;
    y_offset++;
    x_offset = read_piece->left;
  }
  read_piece->y_hash = y_offset;
  read_piece->x_hash = x_offset;
}

/*
** expects malloced 4x4 piece any amount of '#'
**
** returns the amount of '#'s
*/
int hashes(char**piece)
{
  int x;
  int y;
  int hashcount;

  x = 0;
  y = 0;
  hashcount = 0;
  while (y < 4)
    {
      while (x < 4)
        {
          if (piece[y][x] == '#')
            hashcount++;
          x++;
        }
      y++;
      x = 0;
    }
  return hashcount;
}

/*
** expects a constructed tracker for the current piece
** and a list to store the pieces that dont match
**
** traverses the global list of valid pieces and modifies it to hide
** the pieces that don't have a '#' in the same spot as the current
** read_piece->y_hash/x_hash. saves references to the pieces that don't match
** in rejects
**
** returns nothing only modifies the global list and the rejects list
*/
void remove_matches(t_tracker *read_piece, t_arr_list *rejects)
{
  t_arr_list *traverse;
  
  traverse = g_valid_pieces->next;
  while(traverse != g_valid_pieces)
    {
      //remove all the unlike pieces
      if  (((char**)traverse->piecearr)               \
           [read_piece->y_hash - read_piece->top]     \
           [read_piece->x_hash - read_piece->left]    \
           !=                                         \
           read_piece->candidate                      \
           [read_piece->y_hash]                       \
           [read_piece->x_hash])
        {
          list_add(rejects, traverse);
          traverse->next->prev = traverse->prev;
          traverse->prev->next = traverse->next;
        }
      traverse = traverse->next;
    }
}

/*
** expects a constructed tracker for the current piece,
** a list to store the rejects,
** and which hash to check (see set_hash_pos for examples)
**
** each time validate calls itself, another batch of tetriminos are stored
** in the rejects list and the next '#' position is sotred in the tracker.
** the recursion ends when the next and prev pointers of
** the global list are the same
**
** returns either the head of the circular linked list or a pointer to the node
** that is most likely the piece
*/
t_arr_list *list_validate(t_tracker *read_piece, t_arr_list *rejects, int hash_num)
{
  if (g_valid_pieces->next == g_valid_pieces->prev)
    return (g_valid_pieces->next->piecearr == NULL \
            ? NULL                                 \
            : g_valid_pieces->next);
  set_hash_pos(read_piece, hash_num);
  remove_matches(read_piece, rejects);
  hash_num++;
  return(list_validate(read_piece, rejects, hash_num));
}

/*
** expects a constructed tracker for the current piece and a non-NULL 4x4 piece
**
** if the validation function returns non-NULL this checks the candidate
** against the known valid piece for validity
**
** returns 1 if all '#' in the valid piece are in the same place as the
** candidate. 0 otherwise.
*/
int check_candidate(t_tracker *candidate, char **valid)
{
  int hash;

  hash = 1;
  while (hash <= 4)
    {
      set_hash_pos(candidate, hash);
      if (valid                                     \
          [candidate->y_hash - candidate->top]      \
          [candidate->x_hash - candidate->left]     \
          !=                                        \
          candidate->candidate                      \
          [candidate->y_hash]                       \
          [candidate->x_hash])
        return 0;
      hash++;
    }
  return 1;
}

void reconstruct_global(t_arr_list *rejects)
{
  t_arr_list *temp;

  temp = rejects->prev;
  while (temp != rejects) {
    ((t_arr_list*)temp->piecearr)->next->prev = ((t_arr_list*)temp->piecearr);
    ((t_arr_list*)temp->piecearr)->prev->next = ((t_arr_list*)temp->piecearr);
    temp = temp->prev;
  }
}

//testing mains

char *read_file(char*filename)
{
  char *file = ft_strnew(0);
  char buffer[22];
  int fd = open(filename, O_RDONLY);

  ft_memset(buffer, 0, 22);
  while (read(fd, buffer, 21))
    {
      file = ft_strjoin(file, buffer);
      ft_memset(buffer, 0, 22);
    }
  close(fd);
  return (file);
}

int valid_chars(char*file_str)
{
  int i = 0;
  while (file_str[i] != '\0')
    {
      if (file_str[i] != '.' && file_str[i] != '#' && file_str[i] != '\n')
        return (0);
      i++;
    }
  return (1);
}

char *sanitize(char *file) {
  int i = 0;
  while (file[i] != '\0')
    {
      if ((file[i] == '.'||file[i] == '#') && file[i+1] == '\n')
        file[i+1] = 'n';
      i++;
    }
  return (file);
}

int double_newline_check(char *file) {
  int newl = 0;
  int i = 0;

  while (file[i] != '\0')
    {
      if (file[i] == '\n')
        newl++;
      if (file[i] != '\n')
        newl = 0;
      if (newl > 1)
        return (0);
      i++;
    }
  return (newl);
}

int count_pieces_from_str(char *file) {
  int split_size = 0;
  int i = 0;
  while (file[i] !='\0')
    {
      if (file[i] == '\n')
        split_size++;
      i++;
    }
  split_size += file[ft_strlen(file)-1] == 'n';
  return (split_size);
}

int check_piece_length (char**splits, int split_size) {
  int i = 0;
  
  while (i < split_size)
    {
      if (ft_strlen(splits[i]) != 20)
        return (0);
      i++;
    }
  return (1);
}

char  **pre_list_checks (char *file) {
  char **splits;
  char split_size;
  
  //verify that '.' '#' and '\n' is the whole alphabet
  if (!valid_chars(file))
    return (0);
  //verify the file ends in a '\n'
  if (file[ft_strlen(file)-1] != '\n')
    return (0);
  //sanitize newlines for strsplit
  file = sanitize(file);
  //check for 2+ adjancent '\n'
  if (double_newline_check(file) != 1)
    return (0);
  //verify split_size isn't >26 otherwise bad input
  split_size = count_pieces_from_str(file);
  if (split_size > 26)
    return (0);
  //verify all values in splits are length 20 otherwise bad piece
  splits = ft_strsplit(file, '\n');
  if (!check_piece_length(splits, split_size))
    return(0);
  return (splits);
}

t_tet **build_tet_array(int split_size, char**splits, t_arr_list *rejects) {
  int i = 0;
  char **current_piece = NULL;
  t_arr_list *temp = NULL;
  t_tet **list = (t_tet**)ft_memalloc(sizeof(t_tet*) * (split_size + 1));
  t_tracker *current_piece_tracker = NULL;
  while (i < split_size)
    {
      current_piece = ft_strsplit(splits[i], 'n');
      current_piece_tracker = construct_tracker(current_piece);
      if (hashes(current_piece) != 4)
        return (0);
      temp = list_validate(current_piece_tracker, rejects, 1);
      if (!check_candidate(current_piece_tracker, temp->piecearr))
        return (0);
      list[i] = init_tet(temp->piecearr);
      reconstruct_global(rejects);
      i++;
    }
  list[i] = NULL;
  return (list);
}

t_tet **validate(char *file)
{
  t_arr_list *rejects = new_node(NULL);
  t_tet **tet_array = NULL;
  char **split_str = pre_list_checks(file);

  if (split_str == NULL)
    return (0);
  
  g_valid_pieces = init_global();

  tet_array = build_tet_array(count_pieces_from_str(sanitize(file)), split_str, rejects);

  return (tet_array);
}

//testing validation

/* int main() { */
/*   char **ret; */
/*   int x = 0; */
/*   int y = 0; */
/*   char arr[4][4] = {{'.','.','.','.'},                            \ */
/*                     {'.','.','.','.'},                            \ */
/*                     {'.','.','.','.'},                            \ */
/*                     {'.','.','.','.'}}; */
/*   t_arr_list *temp; */

/*   x = 0; */
/*   y = 0; */
/*   ret = (char**)ft_memalloc((sizeof(char*) * 4)); */
/*   while (y < 4) */
/*     { */
/*       ret[y] = (char*)ft_memalloc(sizeof(char) * 4); */
/*       while (x < 4) */
/*         { */
/*           ret[y][x] = arr[y][x]; */
/*           x++; */
/*         } */
/*       y++; */
/*       x = 0; */
/*     } */

/*   t_arr_list *rejects = new_node(NULL); */

/*   g_valid_pieces = init_global(); */

/*   if (hashes(ret) != 4) */
/*     return(0); */


/*   //if validate returns null there's no matches otherwise I need to check the one piece thats returned */
/*   if (validate(construct(ret), rejects, 1) == NULL) */
/*     { */
/*       printf("INVALID\n"); */
/*       return 0; */
/*     } */
/*   else if (check_candidate(construct(ret), ((char**)g_valid_pieces->next->piecearr)) == 0) */
/*     { */
/*       printf("INVALID\n"); */
/*       return 0; */
/*     } */
/*   printf("candidates\n"); */
/*   temp = g_valid_pieces->next; */
/*   while (temp != g_valid_pieces) { */
/*     print_piecearr(temp); */
/*     printf("\n"); */
/*     temp = temp->next; */
/*   } */

/*   //must reconstruct for the next piece */
/*   temp = rejects->prev; */
/*   while (temp != rejects) { */
/*     ((t_arr_list*)temp->piecearr)->next->prev = ((t_arr_list*)temp->piecearr); */
/*     ((t_arr_list*)temp->piecearr)->prev->next = ((t_arr_list*)temp->piecearr); */
/*     temp = temp->prev; */
/*   } */
/*   /\* printf("reconstructed\n"); *\/ */
/*   /\*   temp = g_valid_pieces->next; *\/ */
/*   /\* while (temp != g_valid_pieces) { *\/ */
/*   /\*   print_piecearr(temp); *\/ */
/*   /\*   printf("\n"); *\/ */
/*   /\*   temp = temp->next; *\/ */
/*   /\* } *\/ */
/* } */


//testing get top&&left

/* int main() { */
/*   char **ret; */
/*   int x; */
/*   int y; */
/*   char arr[4][4] = {{'.','.','.','.'},                                  \ */
/*                     {'.','.','.','.'},                                  \ */
/*                     {'.','.','#','#'},                                  \ */
/*                     {'.','#','#','.'}}; */
/*   t_arr_list test; */

/*   x = 0; */
/*   y = 0; */
/*   ret = (char**)ft_memalloc((sizeof(char*) * 4)); */
/*   while (y < 4) */
/*     { */
/*       ret[y] = (char*)ft_memalloc(sizeof(char) * 4); */
/*       while (x < 4) */
/*         { */
/*           ret[y][x] = arr[y][x]; */
/*           x++; */
/*         } */
/*       y++; */
/*       x = 0; */
/*     } */
/*   test.piecearr = ret; */
/*   print_piecearr(&test); */
/*   printf("%d %d\n", get_top(ret), get_left(ret)); */
/* } */
