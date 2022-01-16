//N Queen Problem 
//Backtracking

#include <stdio.h>
#include <stdbool.h>
#define N 4

int ld[30] = { 0 }; //left diagonal 
int rd[30] = { 0 }; //right diagonal
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

bool solveNQueenProblem(int board[N][N], int col)
{
  if(col >= N)
    return true;
  
  for(int i = 0; i < N; i++)
  {
    /*Check if the queen can be placed on board[i][col]*/
    /*A check if a queen can be placed on board[row][col]. We just need to check ld[row - col + n - 1] and rd[row + col]*/
    if( (ld[i - col + N - 1] != 1 && rd[i + col] != 1) && (cl[i] != 1) )
    {
         
    }
  }
}










