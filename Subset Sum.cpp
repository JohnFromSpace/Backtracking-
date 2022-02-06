#include <bits/stdc++.h>
using namespace std;

#define ARRAYSIZE(a) (sizeof(a)/sizeof(a[0]))
static int total_nodes

//prints subset found
void printSubset(int A[], int size){
  for(int i = 0; i < size; i++){
    cout << " " << A[i]; 
  }
  cout << "\n";
}

//qsort compare function
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






