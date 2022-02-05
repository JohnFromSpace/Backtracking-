#include <bits/stdc++.h>
using namespace std;

#define N 8

int solveKTUtil(int x, int y, int moveI, int sol[N][N], int xMove[], int yMove[]);

//A utility function to check if i,j are valid indexes for NxN chessboard
int isSafe(int x, int y, int sol[N][N]){
  
  return (x >= 0 && x< N && y >= 0 && y < N && sol[x][y] == -1);
}

//Utility function to print the solution matrix
void printSolution(int sol[N][N]){
  for(int x = 0; x < N; x++){
    for(int y = 0; y < N; y++)
        cout << " " << setw(2) << sol[x][y] << " ";
      cout << endl;
  
  }
  
}






