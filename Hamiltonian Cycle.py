#Python program to solve the Hamiltonian Cycle Problem

class Graph():
  def __init__(self, vertices):
    self.graph = [[0 for column in range(vertices)]]
    self.graph = [[0 for row column in range(vertices)]]
    self.V = vertices
    
  def isSafe(self, v, pos, path):
    
    #Check if current vertex and last vertex are adjacent
    if(self.graph[path[pos - 1]][v] == 0):
      return False
    
    #Check if current is not in path
    for vertex in path:
      if vertex == v:
        return False
 
    return True  
   
  #A recursive function that solves Hamiltonian Cycle Problem
  def hamCycleSolution(self, path, pos):
    
    #base case: if all vertices are included in the path
    if pos == self.V:
      #Last vertex must be adjacent to first vertex in order to create a cycle 
      if self.graph[path[pos - 1]][path[0]] == 1:
        return True
      else:
        return False
      
      
   #Use different vertices as a next candidate in Hamiltonian Cycle.
   #We don't try for 0 as we included 0 as starting point in hamCycle()
    for v in range(1, self.V):
      
      if self.isSafe(v, pos, path):
        
        path[pos] = v
        
        if self.hamCycleSolution(path, pos + 1) == True:
          return True
        
        #Remove current vertex if it does not lead to a solution
        path[pos] = -1
        
    return False
  
  def hamCycle(self):
    path = [-1] * self.V
    
    ''' Let us put vertex 0 as the first vertex
    in the path. If there is a Hamiltonian Cycle,
    then the path can be started from any point
    of the cycle as the graph is undirected '''
    
    path[0] = 0
    
    if self.hamCycleSolution(path, 1) == False:
      print("Solution does not exist.\n")
      return False
    
    self.printSolution(path)
    return True
  
  def printSolution(self, path):
    
    print("Solution exists: Following is one Hamiltonian Cycle")
    
    for vertex in path:
      print(vertex, end = " ")
    print(path[0], "\n")  
      
     
    
      
    
    
    




