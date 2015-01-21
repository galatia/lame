#include <stdio.h>

void
insertsort(int lst[], int lst_n) {
  int i, j, k, savetoinsert;
  // Loop through all elements in list (for sorting each)
  for(i = 0; i < lst_n; i++) {
    // Loop through sorted part to find where to insert (i.e., j)
    for(j = 0; j < i && lst[i] >= lst[j]; j++); 
    // if it's greater than and needs to be inserted:
    savetoinsert = lst[i];
    // Loop from sorted to greater than the one to insert to shift 1
    for(k = i - 1; k >= j; k--)
      lst[k+1] = lst[k];
    lst[j] = savetoinsert; // insert elem
  }
}

int
main(){
  int test[] = {2,4,11,9,3,7,3};
  int test_n = sizeof(test)/sizeof(test[0]);
  
  insertsort(test, test_n);
  for(int i = 0; i < test_n; i++)
    printf("%d ", test[i]);
  printf("\n");

  return 0;
}
