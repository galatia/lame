/* STUFF I LEARNED
 * Initializing arr with * instead of [] demotes it to ptr immediately
 * so you can't sizeof() it because it will give size of ptr ie 8
 *
 *
 */

#include <stdio.h>

int fact(int n){
  int ans = 1;
  for(int i = 1; i <= n; i++)  ans *= i;
  return ans;
}

// str to permute
// total number of letters to permute
// number of letters left to add
// array of pointers to array of permutations
// number of perumutations done so far
void subperm(char* str, int str_n, int str_i, char** perms, int perms_n) {
       if(str_i == str_n)  return; 
  else if(str_i == ) {
    perms[perms_n - 1][0] = str[str_i];
    subperm(str, --str_i, );
  } else {
    
  subperm();
}

void perm(char* str, int str_n) { 
  int perms_n = fact(str_n);
  // malloc pointers for each perm, and then the space for each word
  // perms_n distributes for size of pointers and lengths of words
  char** perms = malloc(perms_n * (sizeof(char*) + (str_n+1)));

  // Set all the ptrs in the block to the strings they refer to
  char* block = (char*) perms; // cast whole malloced perms as char* to be
                            // able to do arithmetic on it at the byte level
                            // block is a ptr to the beginning of chunk
  block += perms_n * sizeof(char*); // block now pts to beg of chars
  for(i = 0; i < perms_n; i++) {
    perms[i] = block + (i * (str_n + 1)); // perms is still char** to beginning
                              // of ptrs part of chunk, and the i-th ptr is set
                              // to the addr of the ith string where strings
                              // are null-terminated
     

  subperm(str, str_n, str_n, perms, 0); 
}

int main() {
  char test[]  = "abcd";
  int  test_n  = sizeof(test) - 1;

  perm(test, test_n);
  printf("%s\n", perms);
}

/*
a
ab, ba
cab, acb, abc, cba, bca, bac
[24]
each new one is previous perms_n * iteration (ie length of previous word +1)
*/
