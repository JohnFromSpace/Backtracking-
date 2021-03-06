/*Hamiltonian Path in an undirected graph is a path that visits each vertex exactly once. 
A Hamiltonian cycle (or Hamiltonian circuit) is a Hamiltonian Path such that there is an edge (in the graph) 
from the last vertex to the first vertex of the Hamiltonian Path. Determine whether a given graph contains Hamiltonian Cycle or not. 
If it contains, then prints the path. Following are the input and output of the required function.
Input: 
A 2D array graph[V][V] where V is the number of vertices in graph and graph[V][V] is adjacency matrix representation of the graph. 
A value graph[i][j] is 1 if there is a direct edge from i to j, otherwise graph[i][j] is 0.
Output: 
An array path[V] that should contain the Hamiltonian Path. path[i] should represent the ith vertex in the Hamiltonian Path. 
The code should also return false if there is no Hamiltonian Cycle in the graph.
For example, a Hamiltonian Cycle in the following graph is {0, 1, 2, 4, 3, 0}.*/

//Java program for solving the Hamiltonian Cycle Problem

class HamiltonianCycle
{
  final int V = 5;
  int path[];
  
  boolean isSafe(int v, int graph[][], int path[], int pos)
  {
    //Check if this vertex is adjacent of the previously added vertex
    if(graph[path[pos - 1]][v] == 0)
      return false;
    
    //Check if this vertex is already included. This step can be optimized by creating an array of size V.
    for(int i = 0; i < V; i++)
      if(path[i] == v)
        return false;
    
    return true;
  
  }
  
  //A recursive function to solve the Hamiltonian Cycle Problem
  boolean hamiltonianCycleSolution(int graph[][], int path[], int pos)
  {
    
    //Base case: if all vertices are added in the Hamiltonian cycle
    if(pos == V)
    {
      
      //If there is an edge from the last added vertex to the first vertex
      if(graph[path[pos - 1]][path[0]] == 1)
        return true;
      else
        return false;
      
    }
    
    
    //Try different vertices as a next candidate for Hamiltonian Cycle
    //We skip 0 because it was already used for the start
    for (int v = 1; v < V; v++)
    {
      //Check if the vertex can be added to the cycle
      if(isSafe(v, graph, path, pos))
      {
        path[pos] = v;
        
        //Recur to construct the rest of the path
        if(hamiltonianCycleSolution(graph, path, pos + 1) == true)
          return true;
        
        //If adding vertex v doesn't lead to a solution, remove it
        path[pos] = -1;
        
      }
    
    }
    
    //If no vertex can be added to the Hamiltonian Cycle constructed\
    return false;
    
  }
  
  int hamiltonianCycle(int graph[][])
  {
    path = new int[V];
    for(int i = 0; i < V; i++)
      path[i] = -1;
    
    /* Let us put vertex 0 as the first vertex in the path.
    If there is a Hamiltonian Cycle, then the path can be
    started from any point of the cycle as the graph is
    undirected */
    
    path[0] = 0;
    if(hamiltonianCycleSolution(graph, path, 1) == false)
    {
      System.out.println("\nSolution does not exist.\n");
      return 0;
    }
    
    printSolution(path);
    return 1;
    
  }
  
  
  void printSolution(int path[])
  {
    Syste.out.println("Solution exists: Following is one Hamiltonian Cycle");
    
    for(int i = 0; i < V; i++)
      System.out.println(" " + path[0] + " ");
    
    //Print the first vertex again to show the complete cycle
    System.out.println(" " + path[0] + " ");
  }
  
  
  //Main program
  public static void main(String args[])
  {
    HamiltonianCycle hamiltonian = new HamiltonianCyle();
    
    /* Let us create the following graph
           (0)--(1)--(2)
            |   / \   |
            |  /   \  |
            | /     \ |
           (3)-------(4)    */
    
    int graph1[][] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 1},
                      {0, 1, 1, 1, 0}};
    
    /* Let us create the following graph
           (0)--(1)--(2)
            |   / \   |
            |  /   \  |
            | /     \ |
           (3)       (4)    */
    
    int graph2[][] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 0},
                      {0, 1, 1, 0, 0}};
    
    
   //The solution is printed
    hamiltonian.hamiltonianCycle(graph2);  
  }
 
}

