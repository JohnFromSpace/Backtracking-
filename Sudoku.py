#Like all other Backtracking problems, Sudoku can be solved by one by one assigning numbers to empty cells.
#Before assigning a number, check whether it is safe to assign. 
#Check that the same number is not present in the current row, current column and current 3X3 subgrid. 
#After checking for safety, assign the number, and recursively check whether this assignment leads to a solution or not. 
#If the assignment doesn’t lead to a solution, then try the next number for the current empty cell. 
#And if none of the number (1 to 9) leads to a solution, return false and print no solution exists.

#Print grid
def printGrid(arr):
  for i in range(9):
    for j in range(9):
      print arr[i][j]
    print ('n')
    
def findEmptyLocation(arr, 1):
  for row in range(9):
    for col in range(9):
      if(arr[row][col] == 0):
        l[0] = row
        l[1] = col
        return True
  return False    
      
 def usedInRow(arr, row, num) :
  for i in range(9):
    if(arr[row][i] == num):
      return True
  return False  
    
 def usedInCol(arr, col, num):
  for i in range(9):
    if(arr[i][col] == num):
      return True
 return False   

 def usedInBox(arr, row, col, num):
    for i in range(9):
      for j in range(9):
        if(arr[i + row][j + col] == num):
          return True
   return False
  
 def checkLocationSafety(arr, row, col, num):
  return not usedInRow(arr, row, num) and
  not usedInCol(arr, col, num) and
  not usedInBox(arr, row - row % 3, col - col % 3, num)
  
 def solveSudoku(arr):
    # 'l' is a list variable that keeps the
    # record of row and col in
    # find_empty_location Function
    l = [0, 0]
    
    #if there is no assigned location 
    if(not findEmptyLocation(arr, l)):
      return True
    
    #assigning  list values from the function above
    row = l[0]
    col = l[0]
    
    #consider digits 1 to 9
    for num in range(1, 10):
      
      if(checkLocationIsSafe(arr, row, col, num)):
        # make tentative assignment
        arr[row][col] = num
        
        if(solveSudoku(arr)):
          return True
        
        #upon failure 
        arr[row][col] = 0
        
    #backtracking
    return False
  
  #main functio
  if __name__ == "__main__":
    
    #creating a 2d array for the grid
    grid = [[0 for x in range(9)] for y in range(9)]
    
    #assigning values to the grid
    grid =[[3, 0, 6, 5, 0, 8, 4, 0, 0],
          [5, 2, 0, 0, 0, 0, 0, 0, 0],
          [0, 8, 7, 0, 0, 0, 0, 3, 1],
          [0, 0, 3, 0, 1, 0, 0, 8, 0],
          [9, 0, 0, 8, 6, 3, 0, 0, 5],
          [0, 5, 0, 0, 9, 0, 6, 0, 0],
          [1, 3, 0, 0, 0, 0, 2, 5, 0],
          [0, 0, 0, 0, 0, 0, 0, 7, 4],
          [0, 0, 5, 2, 0, 6, 3, 0, 0]]
    
    #if success, print the grid
    if(solveSudoku(arr)):
      printGrid(grid)
    else:
      print "No solution exists."
    
