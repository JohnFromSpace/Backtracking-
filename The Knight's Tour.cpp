#include <bits/stdc++.h>
using namespace std;

#define N 8

int solveKTUtil(int x, int y, int moveI, int sol[N][N], int xMove[], int yMove[]);

//A utility function to check if i,j are valid indexes for NxN chessboard
int isSafe(int x, int y, int sol[N][N]){
  
  return (x >= 0 && x< N && y >= 0 && y < N && sol[x][y] == -1);
}






