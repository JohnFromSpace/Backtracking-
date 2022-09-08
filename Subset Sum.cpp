#include <iostream>
#include <cstdlib>

#define ARRAYSIZE(a) (sizeof(a)/sizeof(a[0]))
static int total_nodes

//Prints subset found
void printSubset(int A[], int size){
  for(int i = 0; i < size; i++){
    std::cout << " " << A[i]; 
  }
  std::cout << "\n";
}

//Qsort compare function
int comparator(const void *pLhs, const void *pRhs){
  int *lhs = (int *) pLhs;
  int *rhs = (int *) pRhs;
  return *lhs > *rhs;
}
  
// inputs
// s            - set vector
// t            - tuplet vector
// s_size       - set size
// t_size       - tuplet size so far
// sum          - sum so far
// ite          - nodes count
// target_sum   - sum to be found

void subset_sum(int s[], int t[], int size_t, int s_size, int t_size, int sum, int ite, int const target_sum){
  total_nodes++;
  
  if(target_sum == sum){
    printSubset(t, t_size);
    
    if(ite + 1 < s_size && sum - s[ite] + s[ite + 1] <= target_sum){
     
      //Exculde previous added item and consider next candidate
      subset_sum(s, t, s_size, t_size - 1, sum - s[ite], ite + 1, target_sum);
      
    }
     return; 
  }
  else{
    
    //Constraint check
    if(ite < s_size && sum + s[ite] <= target_sum){
      
      //Generate nodes along the breadth 
      for(int i = ite; i < size; i++){
        t[t_size] = s[i];
        if(sum + s[i] <= target_sum){
                  
          //Consider next level node along depth
          subset_sum(s, t, s_size, t_size + 1, sum + s[i], i + 1, target_sum);
          
        }
      
      }
    
    }
    
  }
  
}

//Wrapper that prints subsets that sum to target_sum
void generateSubsets(int s[], int size, int target_sum){
  int *tuplet_vector = (int *)malloc(size * sizeof(int));
  int total = 0;
  
  //Sort the set
  qsort(s, size, sizeof(int), &comparator);
  for(int i = 0; i < size; i++){
    total += s[i];
  }
  
  if(s[0] <= target_sum && total >= target_sum){
     subset_sum(s, tuplet_vector, size, 0, 0, 0, target_sum);
  }
  free(tuplet_vector);
}

int main(){
  int weights[] = {15, 22, 14, 26, 32, 9, 16, 8};
  int target 53;
  int size = ARRAYSIZE(weights);
  generateSubsets(weights, size, target);
  std::cout << "Nodes generated: " << total_nodes;
  
  return 0;
}
