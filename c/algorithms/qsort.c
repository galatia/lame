#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
median(int start, int end, int* lst) {
  int p0 = lst[start];
  int p1 = lst[start / 2 + (end - 1)/2]; // "usual rules of alg don't work for edge cases"
  int p2 = lst[end - 1];

  int A = p0 < p1;
  int B = p1 < p2;
  int C = p2 < p0;

       if(A == C)  return p0;
  else if(A == B)  return p1;
  else             return p2;
  
}

// Takes the starting index (usually 0 when called), end index, and list
void
quicksort(int start, int end, int* lst) {
  if(end - 1 <= start)  return;
  else {
    int i=start, lesser_i, greater_i, saved;
    int pivot = median(start, end, lst);

    lesser_i = start; 
    greater_i = end - 1; 
    while(i <= greater_i) {
      if(lst[i] < pivot){
        saved = lst[lesser_i];
        lst[lesser_i] = lst[i];
        lst[i] = saved;
        ++lesser_i;
        ++i;
      } else if (lst[i] > pivot) {
        saved = lst[greater_i];
        lst[greater_i] = lst[i];
        lst[i] = saved;
        --greater_i;
      } else {
        ++i;
      }
    }

    // Recurse lessers lst[0 until not incl lesser_i]
    quicksort(start, lesser_i, lst); //skip pivot, also avoid segfault :D
    // Recurse greaters lst[lesser_i through not incl lesser_i + greater_i]
    quicksort(greater_i+1 , end, lst); 
  }
}

int
main(){
  int test[] = {2,4,11,9,3,7,3};
//  int test[] = {1,2,3,4,5,6,7,8,9,10};
  int test_n = sizeof(test)/sizeof(test[0]);
  
  quicksort(0, test_n, test);
  for(int i = 0; i < test_n; i++)
    printf("%d ", test[i]);
  printf("\n");

  return 0;
}
