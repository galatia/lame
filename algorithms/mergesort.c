#include <stdio.h>
#include <stdlib.h> // for psuedo-rand nums
#include <time.h>   // for seeding
#include <assert.h> // for testing

#define TEST_TIMES 100
#define MAX_TEST_LENGTH 100

// invariants: list, list_n
// b++ every time fn called
// a++ every for loop in fn
void submerge(int* list, int list_n, int a, int b){
  if(b >= list_n)  return;

  int swap;
  for(; a <= b; a++) 
    if(list[b] < list[a]) { // needs to be strictly < for insertion
                           swap = list[b];
      for(int i = b; i > a; i--)  list[i] = list[i-1];
                 list[a] = swap;
      break;
    }
  return submerge(list, list_n, ++a, ++b);
}

// assume: list2 always directly follows list1, and merge is in place
void merge(int* list1, int list1_n, int list2_n) {
  return submerge(list1, list1_n + list2_n, 0, list1_n);
}

void msort(int* list, int list_n) {
  if(list_n <= 1)  return;

  int half_n = list_n/2;
  int* half2 = list + half_n; // inc ptr to where the 2nd half starts
  int half2_n = list_n - half_n; // in case of odd, will be 1 more

  msort(list,  half_n);
  msort(half2, half2_n);

  return merge(list, half_n, half2_n);
}

int main() {
  srand(time(0));
  int test[MAX_TEST_LENGTH]; // reuse this array every test, pass in len
  for(int i = 0; i < TEST_TIMES; i++) {
    int len = rand() % MAX_TEST_LENGTH; 
    for(int j = 0; j < len; j++)
      test[j] = rand();
    msort(test, len);
    for(int k = 1; k < len; k++) 
      assert(test[k] >= test[k-1]);
    putchar('.');
  }
  putchar('\n');

  /*
  int test[] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2};
  int test_n = sizeof(test)/sizeof(test[0]);

  msort(test, test_n);
  for(int i = 0; i < test_n; i++)
    printf("%d ", test[i]);
  printf("\n");
  */

  return 0;
}
