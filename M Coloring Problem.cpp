/*The idea is to assign colors one by one to different vertices, 
starting from the vertex 0. Before assigning a color, 
check for safety by considering already assigned colors to the adjacent vertices 
i.e check if the adjacent vertices have the same color or not. 
If there is any color assignment that does not violate the conditions, 
mark the color assignment as part of the solution. 
If no assignment of color is possible then backtrack and return false.*/


#include <iostream>

#define V 4

void prinsSolution(int color[]);
  bool isSafe(int v, bool graph[V][V], int color[], int c){
    for(int i = 0; i < V; i++){
      if(graph[V][i] && c == color[i])
        return false;
    
//A recursive utility function to solve m coloring problem
bool graphColoringUtil(bool graph[V][V], int m, int color[], int v){

    //Base case: if all vertices are assigned a color then return true
    if(v == V)
      return true;

    //Consider this vertex v and try different colors
    for(int c = 1; c <= m; c++){

      //Check if the assignement of color c to v is fine
      if(isSafe(v, graph, color, c)){
        color[v] = c;

        if(graphColoringUtil(graph, m, color, v + 1) == true)
          return true;

        //If assigning color c doesn't lead to a solution then remove it
        color[v] = 0;

      }

    }
      //If no color can be assigned to this vertex
    return false;

  }

//The following function provides us with the more feasible solutions, considering there
//are many more solutions.
bool graphColoring(bool graph[V][V], int m){
  
  //Initialize all color values as 0
  //This initialization is needed correct functioning of isSafe()
  int color[V];
  for(int i = 0; i < V; i++){
    color[i] = 0;
  }
  
  if(graphColorUtil(graph, m, color, 0) == false){
    std::cout << "Solution does not exist.";
    return false;
  }
  
  printSolution(color);
  return true;
}
      
void printSolution(int color[]){
  
  std::cout << "Solution Exists: " << "Following are assigned colors" << "\n";
  
  for(int i = 0; i < V; i++){
    std::cout << " " << color[i] << " ";
  }
  
  std::cout << "\n";
  
}      
  
int main(){
  /*Create following graph
  
  (3)---(2)
   |   / |
   |  /  |
   | /   |
  (0)---(2)
  
  */
  
  bool graph[V][V] = {{0, 1, 1, 1},
                      {1, 0, 0, 1},
                      {1, 1, 0, 1},
                      {1, 0, 1, 0}};
  
  int m = 3;
  graphColoring(graph, m);
  return 0;
}
