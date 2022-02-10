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
  def hamCycle(self, path, pos):
    
      
    
    
    




