#include <stdio.h>

// while not everything is sorted
  // for every elem except last, compare with the next one and if >, swap

void
bubblesort(int* lst, int lst_n) {
  int i, saved;
  char sorted = 0;
  while(!sorted)
    for(i = 0, sorted = 1; i < lst_n - 1; i++) 
      if(lst[i] > lst[i+1]) {
        saved = lst[i];
                lst[i] = lst[i+1];
                         lst[i+1] = saved;
        sorted = 0;
      }
}


int
main(){
  int test[] = {2,4,11,9,3,7,3};
  int test_n = sizeof(test)/sizeof(test[0]);
  
  bubblesort(test, test_n);
  for(int i = 0; i < test_n; i++)
    printf("%d ", test[i]);
  printf("\n");

  return 0;
}
