//N Queen Problem 
//Backtracking

#include <stdio.h>
#include <stdbool.h>
#define N 4

int ld[30] = { 0 };
int rd[30] = { 0 };
int cl[30] = { 0 };

void printSolution(int board[N][N])
{
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N; j++)
    {
      printf(" %d ", board[i][j]);
    }
    printf("\n");
  }
}












