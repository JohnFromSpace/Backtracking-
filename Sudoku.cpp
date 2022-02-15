/*Approach: 
Like all other Backtracking problems, Sudoku can be solved by one by one assigning numbers to empty cells. 
Before assigning a number, check whether it is safe to assign. 
Check that the same number is not present in the current row, current column and current 3X3 subgrid. 
After checking for safety, assign the number, and recursively check whether this assignment leads to a solution or not. 
If the assignment doesn’t lead to a solution, then try the next number for the current empty cell. 
And if none of the number (1 to 9) leads to a solution, return false and print no solution exists.*/

/*Algorithm: 

Create a function that checks after assigning the current index the grid becomes unsafe or not. Keep Hashmap for a row, column and boxes. 
If any number has a frequency greater than 1 in the hashMap return false else return true; hashMap can be avoided by using loops.
Create a recursive function that takes a grid.
Check for any unassigned location. If present then assign a number from 1 to 9. 
Check if assigning the number to current index makes the grid unsafe or not. 
If safe then recursively call the function for all safe cases from 0 to 9. 
If any recursive call returns true, end the loop and return true. 
If no recursive call returns true then return false.
If there is no unassigned location then return true.*/

#include <bits/stdc++.h>
using namespace std;

//UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

//N is size of sudoku grid
//Size will be NxN
#define N 9

//Finds an entry grid that is still unassigned
bool FindUnassignedLocation(int grid[N][N], int& row, int& col);

//Checks whether it will be legal to assign num to given row, col
bool isSafe(int grid[N][N], int row, int col, int num);

/* Takes a partially filled-in grid and attempts
to assign values to all unassigned locations in
such a way to meet the requirements for
Sudoku solution (non-duplication across rows,
columns, and boxes) */
bool SolveSudoku(int grid[N][N])
{
  int row, col;
  
  //If there is no unassigned location, we are done
  if(!FindUnassignedLocation(grid, row, col))
    return true;
  
  //Consider digits 1 to 9
  for(int i = 1; i <= 9; i++)
  {
    if(isSafe(grid, row, col, num))
    {
      //Make tentative assignment
      grid[row][col] = num;
      
      //Return, if success
      if(SolveSudoku(grid))
        return true;
      
      //Failure, make it unassigned and try once again
      grid[row][col] = UNASSIGNED;
      
    }
  
  }
  
  //Backtracking
  return false;
}


/* Searches the grid to find an entry that is
still unassigned. If found, the reference
parameters row, col will be set the location
that is unassigned, and true is returned.
If no unassigned entries remain, false is returned. */
  
bool FindUnassignedLocation(int grid[N][N], int& row, int& col)
{
  for(row = 0; row < N; row++)
    for(col = 0; col < N; col++)
      if(grid[row][col] == UNASSIGNED)
        return true;
  return false;
}

/* Returns a boolean which indicates whether
an assigned entry in the specified row matches
the given number. */
bool UsedInRow(int grid[N][N], int row, int num)
{
  for(int col = 0; col < N; col++)
    if(grid[row][col] == num)
      return true;
  return false;
}

/* Returns a boolean which indicates whether
an assigned entry in the specified column
matches the given number. */
bool UsedInCol(int grid[N][N], int col, int num)
{
  for(int row = 0; row < N; row++)
    if(grid[row][col] == num)
      return true;
  return false;
}

/* Returns a boolean which indicates whether
an assigned entry within the specified 3x3 box
matches the given number. */
bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num)
{
  for(int row = 0; row < 3; row++)
    for(int col = 0; col < 3; col++)
      if(grid[row + boxSartRow][col + boxStartCol] == num)
        return true;
  return false;
}

/* Returns a boolean which indicates whether
it will be legal to assign num to the given
row, col location. */
bool isSafe(int grid[N][N], int row, int col, int num)
{
  /* Check if 'num' is not already placed in
  current row, current column
  and current 3x3 box */
  return !UsedInRow(grid, row, num) && !UsedInCol(grid, col, num) && !UsedInBox(grid, row - row % 3, col - col % 3, num) && grid[row][col] == UNASSIGNED;
}

/* A utility function to print grid */
void PrintGrid(int grid[N][N])
{
  for(int row = 0; row < N; row++)
  {
    for(int col = 0; col < N; col++)
    {
      cout << grid[row][col] << " ";
    }
    cout << endl;
  }

}






