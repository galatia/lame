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

// Takes the lowest index (usually 0 when called), highest index incl, and list
void
quicksort(int low, int high, int* lst) {
  if(high <= low)  return; 
  int pivot = median(low, high + 1, lst);
  int greater_i = high, lesser_i = low, saved;
  for(int i = low; i <= greater_i; ){
           if(lst[i] > pivot) {
      saved = lst[i];
              lst[i] = lst[greater_i];
                       lst[greater_i] = saved;
      --greater_i;
    } else if (lst[i] < pivot) {
      saved = lst[i];
              lst[i] = lst[lesser_i];
                       lst[lesser_i] = saved;
      ++lesser_i;
      ++i;
    } else {
      ++i;
    }
  }
  quicksort(low,           lesser_i - 1, lst);
  quicksort(greater_i + 1, high,         lst);
}

int
main(){
  int test[] = {2,4,11,9,3,7,3};
//  int test[] = {1,2,3,4,5,6,7,8,9,10};
  int test_n = sizeof(test)/sizeof(test[0]);
  
  quicksort(0, test_n - 1, test);
  for(int i = 0; i < test_n; i++)
    printf("%d ", test[i]);
  printf("\n");

  return 0;
}
