//Java program of solution to the M Coloring Problem
public class mColoringProblem
{
  final int V = 4;
  int color[];
  
  boolean isSafe(int v, int graph[][], int color[], int c)
  {
    for (int i = 0; i < V; i++)
      if(graph[v][i] == 1 && c == color[i])
        return false;
    return true;
  }
  
  boolean graphColoringUtil(int graph[][], int m, int color[], int v)
  {
    //base case where all vertices are assigned a colour 
    if(v == V)
      return true;
    
    //consider this vertex v and try different colours
    for(int c = 1; c <= m; c++)
    {
      if(isSafe(v, graph, color, c))
      {
        color[v] = c;
          
        //recur to assign colours to the rest of the vertices
        if(graphColoringUtil(graph, m, color, v + 1))
          return true;
        
        //if assignment of colour c does not work then remove it
        color[v] = 0;
      }
    }
    
    //if no color can be assigned to this vertex
    return false;
  
  }
  


}
