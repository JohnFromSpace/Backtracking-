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
function hamiltonianCycleSolution($graph, &$path, $pos)
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
  
  
}












?>
