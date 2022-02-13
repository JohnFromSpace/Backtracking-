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
