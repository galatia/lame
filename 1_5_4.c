#include <stdio.h>

/* inside or outside a word*/
#define IN  1
#define OUT 0

/* count lines, words, and chars in input */
int 
main()
{
  int c, nl, nw, nc, state;

  state = OUT;
  nl = nw = nc = 0;

  while((c = getchar()) != EOF){
    nc ++; 
    
    if (c == '\n')                          nl++;
    if (c == ' ' || c == '\n' || c == '\t') state = OUT;
    else if (state == OUT) {
      state = IN;
      nw ++;
    }
  }

  printf("Lines: %d\tWords: %d\tCharacters:%d\n", nl, nw, nc);
  
  return 0;
}
