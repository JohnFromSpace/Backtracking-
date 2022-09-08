#include <iostream>
#include <iomanip>

#define N 8

int solveKTUtil(int x, int y, int movei, int sol[N][N], int xMove[], int yMove[]);

//A utility function to check if i,j are valid indexes for NxN chessboard
int isSafe(int x, int y, int sol[N][N]){
  
  return (x >= 0 && x< N && y >= 0 && y < N && sol[x][y] == -1);
}

//Utility function to print the solution matrix
void printSolution(int sol[N][N]){
  for(int x = 0; x < N; x++){
    for(int y = 0; y < N; y++)
        std::cout << " " << setw(2) << sol[x][y] << " ";
      std::cout << std::endl;
  
  }
  
}

/*This function solves the Knight Tour problem using
Backtracking. This function mainly uses solveKTUtil()
to solve the problem. It returns false if no complete
tour is possible, otherwise return true and prints the
tour.
Please note that there may be more than one solutions, 
this function prints one of the feasible solutions.*/

int solveKT(){
  int sol[N][N];
  
  //Initialization of solutions of matrix
  for(int x = 0; x < N; x++)
    for(int y = 0; y < N; y++)
      sol[x][y] = -1;

  /* xMove[] and yMove[] define next move of Knight.
    xMove[] is for next value of x coordinate
    yMove[] is for next value of y coordinate */
  int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
  int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};
  
  //Starting position of knight
  sol[0][0] = 0;
  
  if(solveKTUtil(0, 0, 1, sol, xMove, yMove) == 0){
    std::cout << "Solution does not exist";
    return 0;
  }
  else{
    printSolution(sol);
  }
      
return 1;
}

//A recursive utility function to solve the Knight's Tour problem
int solveKTUtil(int x, int y, int movei, int sol[N][N], int xMove[8], int yMove[8]){
  int k, next_x, next_y;
  if(movei == N * N){
    return 1;
  }
  
  
  for(k = 0; k < 8; k++){
    next_x = x + xMove[k];
    next_y = y + yMove[k];
    if(isSafe(next_x, next_y, sol)){
      sol[next_x][next_y] = movei;
      if(solveKTUtil(next_x, next_y, movei + 1, sol, xMove, yMove) == 1){
        return 1;
      }
      else{
        //backtracking occurs
        sol[next_x][next_y] = -1;
        
      }
       
    }
    
  }
    
  return 0;
 }

int main(){
   solveKT();
  return 0;
}
