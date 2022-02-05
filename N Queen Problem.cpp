//N Queen Problem 
//Backtracking

#include <stdio.h>
#include <stdbool.h>
#define N 4

int ld[30] = { 0 }; //left diagonal 
int rd[30] = { 0 }; //right diagonal
int cl[30] = { 0 }; 

void printSolution(int board[N][N]){
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      printf(" %d ", board[i][j]);
    }
    printf("\n");
  }
}

bool solveNQueenProblem(int board[N][N], int col){
  if(col >= N)
    return true;
  
  for(int i = 0; i < N; i++){
    /*Check if the queen can be placed on board[i][col]*/
    /*A check if a queen can be placed on board[row][col]. We just need to check ld[row - col + n - 1] and rd[row + col]*/
    if( (ld[i - col + N - 1] != 1 && rd[i + col] != 1) && (cl[i] != 1) ){
      board[i][col] = 1;
      ld[i - col + N - 1] = rd[i+col]=cl[i] = 1;
      
      //recur to place the rest of the queens
      if(solveNQUtil(board, col + 1))
        return true;
      
      //if placing queen in board[i][col] doesn't lead to a solution, then remove queen from board[i][col]
      board[i][col] = 0;//Backtracking
      ld[i - col + N - 1] = rd[i + col] = cl[i] = 0;      
  
    }
  }
  //if the queen cannot be placed in any row in this column
  return false;
}

bool solveNQ(){
  int board[N][N] = {{0, 0, 0, 0}, 
                     {0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0}};
  if(solveNQUtil(board, 0) == false){
    printf("Solution does not exist.");
    return false;
  }
  
  
  printSolution(board);
  return true;
  
                    
}


int main(){ 
  solveNQ();
  return 0;
}












