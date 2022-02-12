/*Like all other Backtracking problems, Sudoku can be solved by one by one assigning numbers to empty cells.
Before assigning a number, check whether it is safe to assign. 
Check that the same number is not present in the current row, current column and current 3X3 subgrid. 
After checking for safety, assign the number, and recursively check whether this assignment leads to a solution or not. 
If the assignment doesn’t lead to a solution, then try the next number for the current empty cell. 
And if none of the number (1 to 9) leads to a solution, return false and print no solution exists.*/

class GFG
{
  public static boolean isSafe(int[][] board, int row, int col, int num)
  {
    //Row has the unique numbers(row-clash)
    for(int d = 0; d < board.length; d++)
    {
      //Check if the number we are trying to place is already in the following row
      if(board[row][d] == num){
        return false;
      }
    }
    
    //Column has the unique numbers(column-clash)
    for(int r = 0; r < board.length; r++)
    {
      //Check if the number we are trying to place is already in the following column
      if(board[d][col] == num)
      {
        return false;
      }
    
    }  
    
    //Corresponding square/box has unique number(box-clash)
    int sqrt = (int)Math.sqrt(board.length);
    int boxRowStart = row - row % sqrt;
    int boxColStart = col - col % sqrt;
    for(int r = boxRowStart; r < board.length + sqrt; r++)
    {
      for(int d = boxColStart; d < board.length + sqrt; d++)
      {
        if(board[r][d] == num)
        {
          return false;
        }
      
      }
    
    }
    
    //If there is no clash
    return true;

  }
  
  public static boolean solveSudoku(int[][] board, int n)
  {
    int row = -1;
    int col = -1;
    boolean isEmpty = true;
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < n; j++)
      {
        if(board[i][j] == 0)
        {
          row = i;
          col = j;
          
          //There are still some remaining missing values 
          isEmpty = false;
          break;
        }
      }
      if(!isEmpty)
      {
        break;
      }
    }
    
    //No empty space left
    if(isEmpty)
    {
      return true;
    }
    
    //Else for each row-backtrack
    for(int num = 1; num <= n; n++)
    {
      if(isSafe(board, row, col, num))
      {
        board[row][col] = num;
        if(solveSudoku(board, n))
        {
          //Print board
          return true;
        }
        else
        {
          //Replace it
          board[row][col] = 0;
        }
      }
    }
    
    return false;
    
  }
  
  public static void print(int[][] board, int N)
  {
    
    
  }
  

}


