#include <stdio.h>

#define N 8


bool solveMaze(int maze[N][N], int int x, int y, int sol[N][N]);

//Function to print out the solution matrix
void printSolution(int sol[N][N]){
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++)
      printf(" %d", sol[i][j]);
    printf("\n");
  }
}  

//Check if x and y are valid indices for the matrix with size NxN
bool isSafe(int maze[N][N], int x, int y){
   if(x >= 0 && x < N && y >= 0 && y <= N && maze[N][N] == 1)
     return true;
  
  return false;  
}   
  
bool solveMaze(int maze[N][N]){
  int sol[N][N] = {{0, 0, 0, 0}, 
                   {0, 0, 0, 0},
                   {0, 0, 0, 0},
                   {0, 0, 0, 0}};
  
  if(solveMaze(maze, 0, 0, sol) == false){
    printf("Solution does not exist.");
    return false;
  }
  
  printSolution(sol);
  return true;
}

//The recursive part
bool solveMaze(int maze[N][N], int x, int y, sol[N][N]){
  
  //When goal reached
  if(x == N - 1 && y == N - 1 && maze[x][y] == 1){
    sol[x][y] = 1;
    return true;
  }
  
 //Check if maze is valid
  if(isSafe(maze, x, y) == true){
    //Check if the current block is already part of the solution path
    if(sol[x][y] == 1)
    {
      return false;
    }
    
    sol[x][y] = 1;
    
    //Move forward in x direction
    if(solveMaze(maze, x + 1, y, sol) == true){
      return true;
    }
    
    
    //If moving in x direction does not give a solution, then move down in the y direction
    
    
    
    
      
  }
  
}





    
 
    
  







