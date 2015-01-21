#include <stdio.h>



int* msort(int* list, int list_n) {
  if(list_n <= 1)  return;

  int half_n = list_n/2;
  int* half2 = list + half_n; // inc ptr to where the 2nd half starts
  int half2_n = list_n - half_n; // in case of odd, will be 1 more

  msort(list,  half_n);
  msort(half2, half2_n);

  return merge(list, half_n, half2_n);
}

int main() {
  int test[] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2};
  int test_n = sizeof(test)/sizeof(test[0]);

  msort(test, test_n);
  for(int i = 0; i < test_n; i++)
    printf("%d ", test[i]);
  printf("\n");

  return 0;
}
