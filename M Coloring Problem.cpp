/*The idea is to assign colors one by one to different vertices, 
starting from the vertex 0. Before assigning a color, 
check for safety by considering already assigned colors to the adjacent vertices 
i.e check if the adjacent vertices have the same color or not. 
If there is any color assignment that does not violate the conditions, 
mark the color assignment as part of the solution. 
If no assignment of color is possible then backtrack and return false.*/


#include <iostream>

#define V 4
