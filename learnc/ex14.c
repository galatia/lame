#include <stdio.h>

int main(int argc, char **argv) 
{
  int i; 
  for(i = 1; i < argc; i++) {
    // print letters
    int j;
    char c;
    
    for(j = 0; (c = argv[i][j]); j++) 
      // if c is a letter
      if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') 
        printf("'%c == %d ", c, c);
    
    printf("\n");
  }
    return 0;
}
