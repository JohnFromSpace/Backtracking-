#Python Solution of the M Coloring Problem

class Graph: 
  def __init__(self, vertices):
    self.V = vertices;
    self.graph = [[0 for column in range(vertices)]\ for row in range(vertices)]
    
    def isSafe(self, v, color, c):
      for i in range (self.V):
        if self.graph[v][i] == 1 and color[i] == c:
          return False
      return True
    
    
    
        
  
        
        
        
        
        
        
        
        
        
      

