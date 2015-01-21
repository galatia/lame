#include <stdio.h>

/* count lines in input */

main()
{
  int c, lines;

  lines = 0;
  while((c = getchar()) != EOF)
    if (c == '\n')
      lines ++;
  printf("%d\n", lines);
}
