<?php
//Solution to the Hamiltonian Cycle Problem

$V = 5;

/* A utility function to check if
the vertex v can be added at index 'pos'
in the Hamiltonian Cycle constructed so far
(stored in 'path[]') */

function isSafe($v, $graph, &$path, $pos)
{
  /* Check if this vertex is
    an adjacent vertex of the
    previously added vertex. */
  if($graph[$path[$pos - 1]][$v] == 0)
    return false;
  
  /* Check if the vertex has already been included.
    This step can be optimized by creating an array
    of size V */
  for($i = 0; $i < $pos; $i++)
    if($path[$i] == $v)
      return false;
  
  return true;
  
}

/* A recursive utility function
to solve hamiltonian cycle problem */
function hamiltonianCycleUtility($graph, &$path, $pos)
{
  global $V;
  
  /* base case: If all vertices are included in
    Hamiltonian Cycle */
  if($pos == $V)
  {
    // And if there is an edge from the
    // last included vertex to the first vertex
    if($graph[$path[$pos - 1]][$path[0]] == 1)
      return true;
    else
      return false;
  }
  
  // Try different vertices as a next candidate in
  // Hamiltonian Cycle. We don't try for 0 as we
  // included 0 as starting point hamCycle()
  for($v = 1; $v < $V; $v++)
  {
    /* Check if this vertex can be added
        to Hamiltonian Cycle */
    
    if(isSafe($v, $graph, $path, $pos))
    {
      $path[$pos] = $v;
      
      //Recur the construct to the rest of the path
      if(hamiltonianCycleUtility($graph, $path, $pos + 1, ) == true)
        return true;
      
      //If a vertex does not lead to a solution, remove it
      $path[$pos] = -1;
    
    }
  
  }

  /* If no vertex can be added to Hamiltonian Cycle
    constructed so far, then return false */
  return false;
  
}

/* This function solves the Hamiltonian Cycle problem using
Backtracking. It mainly uses hamCycleUtil() to solve the
problem. It returns false if there is no Hamiltonian Cycle
possible, otherwise return true and prints the path.
Please note that there may be more than one solutions,
this function prints one of the feasible solutions. */
function hamCycle($graph)
{
  global $V;
  $path = array_fill(0, $V, 0);
  for($i = 0; $i < $V; $i++)
    $path[$i] = -1;
  
  /* Let us put vertex 0 as the first vertex in the path.
    If there is a Hamiltonian Cycle, then the path can be
    started from any point of the cycle as the graph is
    undirected */
  $path[0] = 0;
  if(hamiltonianCycleUtility($graph, $path, 1) == false)
  {
    echo("\nSolution does not exist.");
    return 0;
  }
  
  printSolution($path);
  return 1;
}














?>
