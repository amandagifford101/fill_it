#include <stdio.h>
#include "fillit.h"
#define DIM_32 [4][4]
#define UNVOID(X) (*((char (*)[4][4])X))

typedef struct s_piece {
  void *piecearr;
  struct s_piece *next;
  struct s_piece *prev;
} t_piece;

static t_piece g_all_valid_pieces_list;



int main () {
  char test[4][4] = L;
  char test2[4][4] = I;
  t_piece test3;
  test3.piecearr = &test;

  int i = 0;
  int j = 0;
  while (j < 4){
    i = 0;
    while (i < 4){
      printf("%i", UNVOID(test3.piecearr)[j][i] == test2[j][i]);
      i++;
    }
    j++;
    printf("\n");
  }
}
