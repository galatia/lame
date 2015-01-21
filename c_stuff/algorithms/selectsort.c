#include <stdio.h>
#include <limits.h> // since sorting ints, need the biggest possible one to compare for smallest

// for every element in the list
 // loop through to find the smallest in the unsorted portion
 // and then switch it with the first in the unsorted portion 

void
selectsort(int* lst, int lst_n) {
  int i, j, smallest, smallest_index;
  for(i = 0; i < lst_n; i++) {
    smallest = INT_MAX;
    for(j = i; j < lst_n; j++)
      if(lst[j] <= smallest) {
        smallest = lst[j];
        smallest_index = j;
      }
    lst[smallest_index] = lst[i];
    lst[i] = smallest;
  }
}

int
main(){
  int test[] = {2,4,11,9,3,7,3};
  int test_n = sizeof(test)/sizeof(test[0]);
  
  selectsort(test, test_n);
  for(int i = 0; i < test_n; i++)
    printf("%d ", test[i]);
  printf("\n");

  return 0;
}
