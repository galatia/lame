/* STUFF I LEARNED FROM THIS ONE
 *
 * segfaults can happen from stack overflow
 * this won't happen if you tail recurse properly
 * if you -- or ++, you need to do that first, otherwise it passes in old val
 *
 * more obvious recursively what the algorithm is doing
 * but puts you more at risk for segfaults (unless you're sure to tail recurse)
 * 
 * if finding mid, this is avg of high and low, and not just mid of their diff
 * if dividing a sum, divide first to avoid int overflow
 *
 * test for lots of cases, not just one that fits the bill
 *
 * walking through it manually is time consuming but super useful
 *
 * don't tweak and recompile unless you have a hypothesis for what went wrong
 */


#include <stdio.h>

int subfindmin(int* list, int low, int high) {
  if (high - low == 1) { 
    if (list[low] < list[high])  return list[low]; 
    else                         return list[high];
  }

  int mid = (high - low) / 2 + low;
       if(list[mid] < list[high])  return subfindmin(list, low,   mid );  
  else if(list[mid] > list[high])  return subfindmin(list, mid,   high); 
  else                             return subfindmin(list, low, --high);
}

int
findmin(int* list, int list_n) {
  return subfindmin(list, 0, list_n - 1);
}

int
main(){
  int test[] = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8};
  int test_n = (sizeof(test)/sizeof(test[0]))/2;

  int i, min; 
  for(i=0; i<test_n; i++) 
    if ((min = findmin(test+i, test_n)) == 1)  printf("PASS\n");
    else                                       printf("FAIL (min found = %d)\n", min);
} 
